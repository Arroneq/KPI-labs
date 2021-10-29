#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int stack_or_queue;
	cout << "З чим хочете працювати: 1-стек 2-черга" << endl;
	cin >> stack_or_queue;
	int input = 1;

	if (stack_or_queue == 1)
	{ 
		stack <int> stack;
		cout << "Введіть початкову кількість елементів у стеку:" << endl;

		int n, x;
		cin >> n;

		cout << "Введіть цифри" << endl;
		for (int i=0; i<n; i++)
		{
			cin >> x;
    		stack.push(x);
		}
 
		while(input != 0)
		{
			cout << "\nПерелік можливих операцій: " << endl;
			cout << "1: вивести заданий стек з верхнього елементу;" << endl;
			cout << "2: додати елемент до стеку;" << endl;
			cout << "3: видалити елемент з стеку;" << endl;
			cout << "4: видалити стек;" << endl;
			cout << "0: завершити роботу;" << endl;
		
			cin >> input;
			switch (input)
			{
				case 1: {
					cout << "Ваша черга: ";
					while (!stack.empty()) {
        				cout << stack.top() << " ";
       					stack.pop();
    				}
					input = 0;
					cout << "\nРоботу завершено, стек порожній!" << endl;
					break;
				}
				case 2: {
					cout << "Введіть значення елементу, який бажаєте додати до стеку" << endl;
					int value;
					cin >> value;
					stack.push(value);

					break;
					cout << endl;
					}
				case 3: {
					stack.pop();
					break;
				}
				case 4: {
					while (!stack.empty())
        				stack.pop();
					input = 0;
					cout << "\nРоботу завершено, стек порожній!" << endl;
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
	if (stack_or_queue == 2)
	{
		queue <int> queue;
		cout << "Введіть початкову кількість елементів у стеку:" << endl;

		int n, x;
		cin >> n;

		cout << "Введіть цифри" << endl;
		for (int i=0; i<n; i++)
		{
			cin >> x;
    		queue.push(x);
		}
		while(input != 0)
		{
			cout << "\nПерелік можливих операцій: " << endl;
			cout << "1: вивести задану чергу;" << endl;
			cout << "2: додати елемент до черги;" << endl;
			cout << "3: видалити елемент з черги;" << endl;
			cout << "4: видалити чергу;" << endl;
			cout << "0: завершити роботу;" << endl;
	
			cin >> input;
			switch (input)
			{
				case 1: {
					cout << "Ваша черга: ";
					while (!queue.empty()) {
        				cout << queue.front() << " ";
       					queue.pop();
    				}
					input = 0;
					cout << "\nРоботу завершено, черга порожня!" << endl;
					break;
				}
				case 2: {
					cout << "Введіть значення елементу, який бажаєте додати до стеку" << endl;
					int value;
					cin >> value;
					queue.push(value);

					break;
					cout << endl;
					}
				case 3: {
					queue.pop();
					break;
				}
				case 4: {
					while (!queue.empty())
        				queue.pop();
					input = 0;
					cout << "\nРоботу завершено, стек порожній!" << endl;
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
	else
		cout << "Роботу завершено, введено некоректний індекс!" << endl;
}
