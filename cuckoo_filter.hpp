#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>

namespace cuckoo {

template <class Key, class Hash = std::hash<Key>, std::size_t BucketSize = 4, std::size_t FingerprintBits = 8>
class CuckooFilter {
    static_assert(BucketSize > 0, "BucketSize must be greater than zero.");
    static_assert(FingerprintBits > 0 && FingerprintBits <= 16, "FingerprintBits must be in range [1, 16].");

private:
    using fingerprint_type = std::conditional_t<FingerprintBits <= 8, std::uint8_t, std::uint16_t>;

    static constexpr std::size_t fingerprint_mask() noexcept {
        if constexpr (FingerprintBits == 16) {
            return 0xFFFFu;
        } else {
            return (static_cast<std::size_t>(1u) << FingerprintBits) - 1u;
        }
    }

    struct Bucket {
        std::array<fingerprint_type, BucketSize> slots{};

        [[nodiscard]] bool insert(fingerprint_type fp) noexcept {
            for (auto &slot : slots) {
                if (slot == 0) {
                    slot = fp;
                    return true;
                }
            }
            return false;
        }

        [[nodiscard]] bool erase(fingerprint_type fp) noexcept {
            for (auto &slot : slots) {
                if (slot == fp) {
                    slot = 0;
                    return true;
                }
            }
            return false;
        }

        [[nodiscard]] bool contains(fingerprint_type fp) const noexcept {
            for (auto slot : slots) {
                if (slot == fp) {
                    return true;
                }
            }
            return false;
        }

        [[nodiscard]] bool full() const noexcept {
            for (auto slot : slots) {
                if (slot == 0) {
                    return false;
                }
            }
            return true;
        }
    };

    std::vector<Bucket> buckets_;
    Hash hash_;
    std::mt19937 rng_;
    std::size_t count_;
    std::size_t max_kicks_;

    [[nodiscard]] fingerprint_type fingerprint(const Key &key) const {
        const std::size_t h = static_cast<std::size_t>(hash_(key));
        auto fp = static_cast<fingerprint_type>(h & fingerprint_mask());
        if (fp == 0) {
            fp = 1;
        }
        return fp;
    }

    [[nodiscard]] std::size_t index1(const Key &key) const {
        return static_cast<std::size_t>(hash_(key)) % buckets_.size();
    }

    [[nodiscard]] std::size_t index2(std::size_t i, fingerprint_type fp) const noexcept {
        const std::size_t h = std::hash<std::size_t>{}(static_cast<std::size_t>(fp));
        return (i ^ h) % buckets_.size();
    }

    [[nodiscard]] bool relocate(std::size_t index, fingerprint_type fp) {
        auto current_index = index;
        auto current_fp = fp;
        std::uniform_int_distribution<std::size_t> slot_dist(0, BucketSize - 1);

        for (std::size_t kick = 0; kick < max_kicks_; ++kick) {
            auto &current_bucket = buckets_[current_index];
            const auto slot_index = slot_dist(rng_);
            std::swap(current_fp, current_bucket.slots[slot_index]);

            current_index = index2(current_index, current_fp);
            if (buckets_[current_index].insert(current_fp)) {
                return true;
            }
        }
        return false;
    }

    [[nodiscard]] Bucket &bucket(std::size_t i) noexcept { return buckets_[i]; }
    [[nodiscard]] const Bucket &bucket(std::size_t i) const noexcept { return buckets_[i]; }

public:
    explicit CuckooFilter(std::size_t bucketCount, std::size_t maxKicks = 500, std::uint32_t seed = std::random_device{}())
        : buckets_(bucketCount == 0 ? 1 : bucketCount), hash_(), rng_(seed), count_(0), max_kicks_(maxKicks) {}

    [[nodiscard]] bool insert(const Key &key) {
        const auto fp = fingerprint(key);
        const auto i1 = index1(key);
        const auto i2 = index2(i1, fp);

        if (bucket(i1).insert(fp) || bucket(i2).insert(fp)) {
            ++count_;
            return true;
        }

        std::uniform_int_distribution<int> bucket_dist(0, 1);
        const auto start_index = bucket_dist(rng_) == 0 ? i1 : i2;
        if (relocate(start_index, fp)) {
            ++count_;
            return true;
        }
        return false;
    }

    [[nodiscard]] bool contains(const Key &key) const {
        const auto fp = fingerprint(key);
        const auto i1 = index1(key);
        const auto i2 = index2(i1, fp);
        return bucket(i1).contains(fp) || bucket(i2).contains(fp);
    }

    [[nodiscard]] bool erase(const Key &key) noexcept(noexcept(std::declval<Hash>()(std::declval<Key>()))) {
        const auto fp = fingerprint(key);
        const auto i1 = index1(key);
        const auto i2 = index2(i1, fp);
        if (bucket(i1).erase(fp) || bucket(i2).erase(fp)) {
            --count_;
            return true;
        }
        return false;
    }

    void clear() noexcept {
        for (auto &b : buckets_) {
            b.slots.fill(0);
        }
        count_ = 0;
    }

    [[nodiscard]] std::size_t size() const noexcept { return count_; }
    [[nodiscard]] std::size_t capacity() const noexcept { return buckets_.size() * BucketSize; }
    [[nodiscard]] bool empty() const noexcept { return count_ == 0; }

    [[nodiscard]] double load_factor() const noexcept {
        return capacity() == 0 ? 0.0 : static_cast<double>(count_) / static_cast<double>(capacity());
    }
};

}  // namespace cuckoo

