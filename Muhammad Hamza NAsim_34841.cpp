#include<iostream>
#include<stdio.h>
#include<string>


using namespace std;

class Stack{
private:
	char stack[10];
	int top;
	bool Valid;
public:
	Stack();
	void push(char);
	char pop();
	void check(string,int);
	bool isfull();
	bool isempty();

};

Stack::Stack()
{
	top = -1;
	Valid = true;
}

bool Stack::isfull()
{
	return top = 9;
}

bool Stack::isempty()
{
	return top < 0;
}

void Stack::push(char a)
{
	if (!isfull()){
		stack[++top] = a;
	}
}

char Stack::pop()
{
	if (!isempty())
	{
		return stack[top];
		top--;
	}
	
}

void Stack::check(string s,int x)
{
	char i;
	i = '$';
	int counter = 0;
	char charr[50];
	s.copy(charr, x);
	while (counter < x)
	{
		for (int i = 0; i < x; i++)
		{
			if (charr[i] == '(' || charr[i] == '[' || charr[i] == '{')
			{
				push(charr[i]);
			}
			if (charr[i] == ')' || charr[i] == ']' || charr[i] == '}')
			{
				if (!isempty())
				{
					Valid = false;
				}
				else
				{
					i = pop();
					if (i=='('||i=='['||i=='{'){
						Valid = false;
					}
				}
			}

		}
		counter++;
	}

	if (Valid==true)
	{
		cout << "InValid string" << endl;
	}

	else{
		cout << "Valid string" << endl;
	}
}

void main()
{
	int lenthofstring;
	string input;

	Stack obj;
	cout << "Enter the string" << endl;
	cin >> input;
	lenthofstring = input.length();
	obj.check(input, lenthofstring);
	system("pause");

}