#include <iostream>
using namespace std;
struct node{
    int value;
	node* next;
	node* prev;
public:
	node(){
		value = 0;
		next = prev = NULL;
	}
	node(int _value, node* _prev= NULL, node* _next= NULL){
		value = _value;
		next = _next;
		prev = _prev;
	}
};
class Queue{
	node* head;
	node* tail;
	int size;
public:
	Queue(){
		head = tail = NULL;
		size = 0;
	}
	void push(int value){
		node* temp = new node(value);
		if (head == NULL){
			head = tail = temp;
			return;
		}
		else{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		}
		size++;
	}
	void pop(){
		if (head == NULL)
            return;
		if (head->next == NULL){
			delete head;
			head = tail = NULL;
		}
		else{
		node* temp = head->next;
		delete head;
		head = temp;
		head->prev = NULL;
		}
		size--;
	}
	int top(){
		return head->value;
	}
	int isEmpty(){
		if (head == NULL || tail == NULL)
            return 1;
		return 0;
	}
};
int main()
{
    Queue q1;
    q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);
	q1.push(50);
	q1.push(60);
	while(q1.isEmpty()==0){
            cout<<q1.top()<<endl;
             q1.pop();
    }
    return 0;
}
