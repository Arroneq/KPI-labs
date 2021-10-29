#include <iostream>
using namespace std;

int* in_queue(int *queue);
void out_queue(int *queue);
int* add_element_to_queue(int *queue, int value);
int* delete_element_from_queue(int *queue);

int length, head, tail, n;

int* in_queue(int *queue)
{
	cout << "Введіть цифри" << endl;

	for (int i=0; i<length; i++)
		cin >> queue[i];

	return queue;
}

bool queue_is_empty()
{
	if (n == 0)
		return true;
	else
		return false;
}

bool queue_is_overflowed()
{
	if (n >= length)
		return true;
	else
		return false;
}

void out_queue(int *queue)
{
	cout << "\nВаша черга: ";

	for (int i=0; i<length; i++)
	{		
		if (tail < head) // 5 6 7t _ _ _ h3 4
		{
			if (queue_is_empty() == 1)  // для випадку, коли head "перекрокує" tail з нижнього if
				cout << "_ ";
			else
			{
			if (i>tail && i<head)
				cout << "_ ";
			else
				cout << queue[i] << " ";
			}
		}
		if (head <= tail) // _ _ _h3 4 5t
		{
			if (queue_is_empty() == 1) // head по модулю стане на індекс 0, проте черга порожня
				cout << "_ ";
			else
			{
				if (i>=head && i<=tail)
					cout << queue[i] << " ";
				else
					cout << "_ ";
			}
		}
	}

    cout << endl;
}

int* add_element_to_queue(int *queue, int value)
{
	if (queue_is_overflowed() == 0)
	{
		tail++;
		tail = tail % length;
		queue[tail] = value;
		n++;
	}
	else
		cout << "Черга переповнена!" << endl;

	return queue;
}

int* delete_element_from_queue(int *queue)
{
	if (queue_is_empty() == 0)
	{
		head ++;
		head = head % length;
		n--;
	}
	else
		cout << "Помилка спустошення!" << endl;

	return queue;
}

int main()
{
	cout << "Введіть початкову кількість елементів у черзі:" << endl;
	cin >> length;
	n = length; // лічильник сумарної кількості доданих та віднятих елементів
	head = 0;
	tail = length-1; // щоб мати саме індекс
	int *queue = new int[length];

	queue = in_queue(queue);

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
			out_queue(queue);
			break;
		}
		case 2: {
			cout << "Введіть значення елементу, який бажаєте додати до черги" << endl;
			int value;
			cin >> value;
			queue = add_element_to_queue(queue, value);
			out_queue(queue);
			break;
		}
		case 3: {
			queue = delete_element_from_queue(queue);
			out_queue(queue);
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
