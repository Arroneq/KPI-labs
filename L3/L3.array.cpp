#include <iostream>
#include <string>
using namespace std;

char* in(char* arr, string str, int length);
void show(char* arr, int length);
char* delete_element(char* arr, int length, int index);
char* add_element(char* arr, int length, int index, char letter);
char* out_from_to_modified(char *arr, int length, int start, int end);
char* task_function(char* arr, int length);

int n; // довжина масиву як глобальна змінна

char* in(char* arr, string str, int length) //розбиваємо й перезаписуємо введений рядок на окремі букви
{
	char* first;
	first = arr;

	for (int i=0; i<n; i++)
		arr[i] = str[i];

	return first;
}

void show(char* arr, int length)
{
	cout << "Ваш текст: ";
	for (int i=0; i<length; i++)
		cout << arr[i];
	cout << endl;
}

char* delete_element(char* arr, int length, int index)
{
	char* first;
	char* temp = new char[length-1];

    for (int i = 0; i < index; i++) 
    {
		temp[i] = arr[i]; 
    }

	for (int i = index; i < length-1; i++) 
    {
        temp[i] = arr[i+1]; 
    }
	n--;

	delete[] arr;
	first = temp;
	return first;
}

char* add_element(char* arr, int length, int index, char letter)
{
	char* first;

    for (int i = length; i > index; i--) 
    {
		arr[i] = arr[i-1];
    }
	arr[index] = letter;
    n++;

	first = arr;
	return first;
}

int is_deleted = 0;

char* from_to_modified(char *arr, int length, int start, int end) //для task_function()
{
	char* first = arr;
	int amount_of_letters = end - start;

	is_deleted = 0; //змінна, що фіксує, скільки літер видалили
	
	if (amount_of_letters % 2 != 0)
	{
		if (amount_of_letters == 1) // якщо слово з одної літери, то кінець рівний початку (викликаємо видалення лише один раз)
		{
			is_deleted = 1;
			first = delete_element(first, length, start);
		}
		else
		{
			is_deleted = 2;
			first = delete_element(first, length, start);
			first = delete_element(first, length-1, end-2); // зсув, адже один елемент вже видалилии на попередньому кроці, а також end=length, а це індексно не останній елемент, а наступний за ним
		}
	}

	return first;		
}

char* task_function(char* arr, int length) //Надрукувати всі слова, у яких непарна кількість літер. Перед друком видалити першу та останню літеру кожного слова.
{
	//ділимо літери на слова
	char *first = arr;
	int length_of_word = 0, start_with = 0, amount_of_letters = 0;
    for (int i = 0; i < length; i++) 
	{
   		if (arr[i] == ' ' || arr[i] == '.')
		{
			is_deleted = 0;

			first = from_to_modified(first, length, start_with, start_with + length_of_word);
			// якщо відбулося видалення, слід зменшити довжину
			length = length - is_deleted;		

			i = i - is_deleted; // так само необхідний зсув по індексу i
			start_with = i + 1; // крім цього, start_with має тепер починатися далі (+ is_deleted)		
			length_of_word = 0;
		}
		else
			length_of_word ++;
    }
	n = length;
	return first;
}

int main()
{
	string str;
	bool input_str = 1;
	cout << "Введіть текст. В кінці поставте крапку" << endl;
	getline(cin, str);

	if (str == "")
		input_str = 0;

	while (input_str == 0)
	{
		cout << "Введіть непорожній рядок!" << endl;
		getline(cin, str);
		if (str == "")
			input_str = 0;
		else
			input_str = 1;
	}
	
	n = str.length();
	char *array = new char[n];

	array = in(array, str, n);

	int input = 1;

	while(input != 0)
	{

	cout << "\nПерелік можливих операцій: " << endl;
	cout << "1: вивести заданий масив;" << endl;
	cout << "2: видалити елемент по заданому індексу;" << endl;
	cout << "3: видалити весь масив;" << endl;
	cout << "4: додати елемент по заданому індексу;" << endl;
	cout << "5: надрукувати всі слова, у яких непарна кількість літер. Перед друком видалити першу та останню літеру кожного слова;" << endl;
	cout << "0: завершити роботу;" << endl;

	cin >> input;
	switch (input)
	{
		case 1: {
			show(array, n);
			break;
		}
		case 2: {
			cout << "Введіть індекс елементу (починаючи лічбу нуля), який бажаєте видалити" << endl;
			int index;
			cin >> index;
			array = delete_element(array, n, index);
			show(array, n);
			break;
		}
		case 3: { 
			delete[] array;
			break;
		}
		case 4: {
			cout << "Введіть через пробіл значення та індекс елементу (починаючи лічбу нуля), який бажаєте додати" << endl;
			char value;
			int index2;
			cin >> value >> index2;
			array = add_element(array, n, index2, value);
			show(array, n);
			break;
		} 
		case 5: {
			array = task_function(array, n);
			show(array, n);
			break;
		}
		case 0: {
			cout << "Роботу завершено! (можливий варіант - введено не номер операції)" << endl; break;
		}
		default:
			cout << "Введіть номер операції із заданого переліку!" << endl; break;
	}
	}
}
