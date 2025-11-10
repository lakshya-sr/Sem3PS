#include <iostream>

using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node<T> *next;
		Node(T data){
			this->data = data;
			next = nullptr;
		}
};

template <class T>
class Queue {
	private:
		Node<T> *head, *tail;
	public:
		Queue() {
			head = tail = nullptr;
		}
		
		void enqueue(T data){
			Node<T> *newnode = new Node<T>(data);
			if(tail) tail->next = newnode;
			else head = newnode;
			tail = newnode;
		}
		
		T dequeue(){
			if(!head) return T();
			T data = head->data;
			Node<T> *temp = head;
			head = head->next;
			delete temp;
			return data;
		}
		
		void display(){
			Node<T> *curr = head;
			while(curr){
				cout << curr->data << " -> ";
				curr = curr->next;
			}
			cout << endl;
		}
};

int main(){
	Queue<float> q;
	cout << "here";
	q.enqueue(1.5);
	q.enqueue(2.5);
	q.display();
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.display();
	
	return 0;
}
