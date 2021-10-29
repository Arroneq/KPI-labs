#include <iostream>
using namespace std;

struct myqueue
{
    int number;
    myqueue *next, *prev;

};

myqueue *Q_last = NULL;

myqueue* in_queue();
void out_queue(myqueue *Q);
bool empty_queue(int *first);
myqueue* add_element_to_queue(myqueue *Q, int value);
myqueue* delete_element_from_queue(myqueue *Q);

myqueue* in_queue()
{
	cout << "Введіть початкову кількість елементів у черзі:" << endl;

	int n;
	cin >> n;

	cout << "Введіть цифри" << endl;

    myqueue *temp, *first, *current;
    temp = new myqueue;
    first = temp;
	temp->prev = NULL;

    for (int i=0; i<n; i++)
    {
        cin >> temp->number; 
        if (i < n-1)
        {    
			current = temp;

			temp->next = new myqueue;
            temp = temp->next;

			temp->prev = current;
		} 
        else 
		{
			Q_last = temp;
			temp->next = NULL;
		}
    }

  	return first;
}

void out_queue(myqueue *Q)
{
	cout << "\nВаша черга: ";
    for ( ; Q != NULL; Q = Q->next)
    {
        cout << Q->number << " ";
    }

    cout << endl;
}

bool empty_queue(myqueue *first)
{
	if (Q_last == NULL && first == NULL)
		return true;
	else
		return false;
}

myqueue* add_element_to_queue(myqueue *Q, int value)
{
	myqueue *previous = Q_last, *first = Q;

	if (empty_queue(first) == true)
	{
		first = Q_last = new myqueue; 
		
		Q_last->number = value;
		Q_last->next = NULL;
		Q_last->prev = previous;

	} else {
	Q_last->next = new myqueue;
	Q_last = Q_last->next;

	Q_last->number = value;
	Q_last->next = NULL;
	Q_last->prev = previous;
	}

	return first;
}

myqueue* delete_element_from_queue(myqueue *Q)
{
	myqueue *delete_me, *first = Q;

	if (empty_queue(first) == false)
	{
		delete_me = first;
		if (delete_me->next == NULL)
		{
			delete delete_me;
			first = Q_last = NULL;
			cout << "Черга порожня!" << endl; 		
		} else {
			first = first->next;
			first->prev = NULL;
			delete delete_me; 
		}
	} 
	else
		cout << "Черга порожня!" << endl;

	return first;

}

int main()
{
	myqueue *Q_first = NULL;

	Q_first = in_queue(); // заповнюємо стек початковими елементами	 

	int input = 1;

	while(input != 0)
	{

	cout << "\nПерелік можливих операцій: " << endl;
	cout << "1: вивести задану чергу;" << endl;
	cout << "2: додати елемент до черги;" << endl;
	cout << "3: видалити елемент з черги;" << endl;
	cout << "0: завершити роботу;" << endl;

	cin >> input;
	switch (input)
	{
		case 1: {
			out_queue(Q_first);
			break;
		}
		case 2: {
			cout << "Введіть значення елементу, який бажаєте додати до черги" << endl;
			int value;
			cin >> value;
			Q_first = add_element_to_queue(Q_first, value);
			out_queue(Q_first);
			break;
		}
		case 3: {
			Q_first = delete_element_from_queue(Q_first);
			out_queue(Q_first);
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
