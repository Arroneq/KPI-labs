#include <iostream>
using namespace std;

int* in_stack(int *stack);
void out_stack(int *stack);
bool empty_stack();
int* add_element_to_stack(int *stack, int value);

int n = 0;

int* in_stack(int *stack)
{
	cout << "Введіть цифри" << endl;

	for (int i=0; i<n; i++)
		cin >> stack[i];

	return stack;
}

bool empty_stack()
{
	if (n == 0)
		return true;
	else
		return false;
}

void out_stack(int *stack)
{
	if (empty_stack() == true)
		cout << "Стек порожній!" << endl;
	else 
	{
		cout << "\nВаш стек: ";
		for (int i=0; i<n; i++)
			cout << stack[i] << " ";
	}
    cout << endl;
}

int* add_element_to_stack(int *stack, int value)
{
	stack[n] = value;
	n++;

	return stack;
}

int* delete_element_from_stack(int *stack)
{
	int* temp = new int[n-1];

    for (int i = 0; i < n-1; i++) 
    {
		temp[i] = stack[i]; 
    }

	n--;

	delete[] stack;
	return temp;
}

int* evaluatePostfix(int *stack, char* exp) 
{ 
    // Scan all characters one by one 
    for (int i = 0; exp[i]; ++i) 
    {
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(exp[i]))
            stack = add_element_to_stack(stack, int(exp[i]) - int('0')); // int('3')-int('0') = by ASCII = 51 - 48 = 3

        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = stack[n-1];
			stack = delete_element_from_stack(stack);
            int val2 = stack[n-1];
			stack = delete_element_from_stack(stack);	

            switch (exp[i]) 
            { 
            	case '+': stack = add_element_to_stack(stack, val2 + val1); break; 
            	case '-': stack = add_element_to_stack(stack, val2 - val1); break; 
            	case '*': stack = add_element_to_stack(stack, val2 * val1); break; 
            	case '/': stack = add_element_to_stack(stack, val2/val1); break; 
            } 
        } 
    } 
    return stack; 
} 

int main()
{
	cout << "Введіть початкову кількість елементів у стеку:" << endl;
	cin >> n;
	int *stack = new int[n];

	stack = in_stack(stack); // заповнюємо стек початковими елементами	 

	int input = 1;

	while(input != 0)
	{

	cout << "\nПерелік можливих операцій: " << endl;
	cout << "1: вивести заданий стек;" << endl;
	cout << "2: додати елемент до стеку;" << endl;
	cout << "3: видалити елемент з стеку;" << endl;
	cout << "4: порахувати постфіксний вираз;" << endl;
	cout << "0: завершити роботу;" << endl;

	cin >> input;
	switch (input)
	{
		case 1: {
			out_stack(stack);
			break;
		}
		case 2: {
			cout << "Введіть значення елементу, який бажаєте додати до стеку" << endl;
			int value;
			cin >> value;
			stack = add_element_to_stack(stack, value);
			out_stack(stack);
			break;
		}
		case 3: {
			stack = delete_element_from_stack(stack);
			out_stack(stack);
			break;
		}
		case 4: {
			int *stack_postfix = new int[0];
			n = 0;
    		char exp[] = "23-4-6/51*-";
			cout << "Ваш вираз: ";
			for (int i = 0; exp[i]; ++i)
				cout << exp[i];

			stack_postfix = evaluatePostfix(stack_postfix, exp);
    		cout << "\nПораховане значення : " << stack_postfix[0] << endl;
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
