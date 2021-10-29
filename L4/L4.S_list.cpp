#include <iostream>
using namespace std;

struct mystack
{
    int number;
    mystack *next, *prev;

};

mystack* in_stack();
void out_stack(mystack *S);
bool empty_stack();
mystack* add_element_to_stack(mystack *S, int value);
mystack* delete_element_from_stack(mystack *S);

mystack *S_last = NULL;

mystack* in_stack()
{
	cout << "Введіть початкову кількість елементів у стеку:" << endl;

	int n;
	cin >> n;

	cout << "Введіть цифри" << endl;

    mystack *temp, *first, *current;
    temp = new mystack;
    first = temp;
	S_last = NULL;
	temp->prev = NULL;

    for (int i=0; i<n; i++)
    {
        cin >> temp->number; 
        if (i < n-1)
        {    
			current = temp;

			temp->next = new mystack;
            temp = temp->next;

			temp->prev = current;
		} 
        else 
		{
			S_last = temp;
			temp->next = NULL;
		}
    }

  	return first;
}

void out_stack(mystack *S)
{
	cout << "\nВаш стек: ";
    for ( ; S != NULL; S = S->next)
    {
        cout << S->number << " ";
    }

    cout << endl;
}

bool empty_stack()
{
	if (S_last == NULL)
		return true;
	else
		return false;
}

mystack* add_element_to_stack(mystack *S, int value)
{
	mystack *previous = S_last, *first = S;

	if (empty_stack() == true)
	{
		first = S_last = new mystack; 
		
		S_last->number = value;
		S_last->next = NULL;
		S_last->prev = previous;

	} else {
	S_last->next = new mystack;
	S_last = S_last->next;

	S_last->number = value;
	S_last->next = NULL;
	S_last->prev = previous;
	}

	return first;
}

mystack* delete_element_from_stack(mystack *S)
{
	mystack *delete_me = S_last, *first = S;

	if (empty_stack() == false)
	{
		delete_me = S_last;
		if (delete_me->prev == NULL)
		{
			delete delete_me;
			first = S_last = NULL;
			cout << "Стек порожній!" << endl; 		
		} else {
			S_last = S_last->prev;
			S_last->next = NULL;
			delete delete_me; 
		}
	} 
	else
		cout << "Стек порожній!" << endl;

	return first;

}

int main()
{
	mystack *S_first = NULL;

	S_first = in_stack(); // заповнюємо стек початковими елементами	 

	int input = 1;

	while(input != 0)
	{

	cout << "\nПерелік можливих операцій: " << endl;
	cout << "1: вивести заданий стек;" << endl;
	cout << "2: додати елемент до стеку;" << endl;
	cout << "3: видалити елемент з стеку;" << endl;
	cout << "0: завершити роботу;" << endl;

	cin >> input;
	switch (input)
	{
		case 1: {
			out_stack(S_first);
			break;
		}
		case 2: {
			cout << "Введіть значення елементу, який бажаєте додати до стеку" << endl;
			int value;
			cin >> value;
			S_first = add_element_to_stack(S_first, value);
			out_stack(S_first);
			break;
		}
		case 3: {
			S_first = delete_element_from_stack(S_first);
			out_stack(S_first);
			break;
		}
		case 0: {
			cout << "Роботу завершено! (можливий варіант - введено не номер операції)" << endl; 
			break;
		}
		default: {
			break;
		}
	}
	}
}
