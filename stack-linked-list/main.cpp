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
class Stack{
	node* head;
	node* tail;
	int size;
public:
	Stack()
	{
		head = tail = NULL;
		size = 0;
	}
	void push(int value)
	{
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
	void pop()
	{
		if (head == NULL)
            return;
		node* temp = tail->prev;
		delete tail;
		tail = temp;
		if(tail!=NULL){
		tail->next = NULL;
		}
		size--;
	}
	int top(){
		return tail->value;
	}
	int isEmpty(){
		if (head == NULL || tail == NULL)
            return 1;
		return 0;
	}
};
int main()
{
    Stack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.push(60);
	while (s1.isEmpty() == 0){
            cout << s1.top() << endl;
            s1.pop();
	}
    return 0;
}
