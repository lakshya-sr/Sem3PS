#include "../cuckoo_filter.hpp"

#include <cassert>
#include <string>

int main() {
    cuckoo::CuckooFilter<int> filter(128, 500, 12345);
    assert(filter.empty());
    assert(filter.size() == 0);
    assert(filter.capacity() == 128 * 4);

    for (int i = 0; i < 200; ++i) {
        assert(filter.insert(i));
    }

    assert(filter.size() == 200);
    assert(filter.load_factor() > 0.0);

    for (int i = 0; i < 200; ++i) {
        assert(filter.contains(i));
    }

    for (int i = 0; i < 50; ++i) {
        assert(filter.erase(i));
    }
    assert(filter.size() == 150);

    filter.clear();
    assert(filter.empty());
    assert(!filter.contains(42));

    cuckoo::CuckooFilter<std::string, std::hash<std::string>, 8, 16> big_filter(64, 800, 999);
    assert(big_filter.insert("alpha"));
    assert(big_filter.insert("beta"));
    assert(big_filter.contains("alpha"));
    assert(big_filter.erase("alpha"));
    assert(!big_filter.contains("alpha"));

    return 0;
}

