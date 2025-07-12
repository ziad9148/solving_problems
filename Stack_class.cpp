	#include <iostream>
	using namespace std;
	class Stack {
	private:
		int tos;
		int size;
		int* stack;
		static int counter;
	public:
		void push(int );
		int pop();      
		static int counting();
		Stack(int );
		~Stack();
	};
	int Stack::counter = 0;
	Stack::Stack(int n ){
		counter++;		//shows how many objects are created
		size = n;
		stack = new int[size];
		tos = 0;
	}
	Stack::~Stack() {
		delete[]stack;		//freeing the memory we used to make the dynamic array
	}
		void Stack::push(int n) {			//adds an element to the stack
			if (tos == size) {
				cout << "the stack is full\n";
			}
			else {
				stack[tos] = n;
				tos++;

			}

	}
		int Stack::pop() {				//tells you what is the last element in the stack
			int retrieved;
			if (tos == 0) {
				cout << "there is no elements in the stack\n";
				retrieved = -1;
			}
			else {
			
				tos--;
				retrieved = stack[tos];	
			}
			return retrieved;


	}
		 int Stack::counting() {
			 return counter;
	}



	int main() {
		int size, n,x,last_element,number_of_objects;
		cout << "please enter the stack size:\n";
		cin >> size;
		Stack s1(size);
		 number_of_objects = Stack::counting();
		cout<<"total objects created is: "<<  number_of_objects<<"\n";


		while (true) {
			cout << "please press 1 if you want to push an element and 2 if you want to pop an element:\n ";
			cin >> n;
			switch (n) {
			case 1:
				cout << "please enter the element:\n";
				cin >> x;
				s1.push(x);
				break;
			case 2:
				last_element = s1.pop();
				if (last_element == -1) { break; }
				cout << "the last element is: " << last_element<<"\n";
				break;
			}
}
		}
	