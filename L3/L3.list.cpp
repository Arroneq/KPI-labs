#include <iostream>
#include <ctime>
#include <string>
using namespace std;

struct mylist
{
    string letter;
    mylist *next, *prev;

};

mylist* in(string s);
void out_from_first_to_last(mylist *L);
void out_from_last_to_first(mylist *L); // показую, що реалізований саме двозв'язний список
// дві тренувальні функції, ділю речення на слова
void out_from_to(mylist *L, int from, int to);
void split_to_words(mylist *L);
// функції видалення
mylist* delete_letter(mylist *L, int index);
mylist* delete_list(mylist *L);
// функція додавання елементу до списку
mylist* add_letter(mylist *L, int index, string letter);
// функція по завданню
mylist* out_from_to_modified(mylist *L, int from, int to);
mylist* task_function(mylist *L);

mylist* last;

mylist* in(string s) // тип mylist*, бо будемо повертати вказівник
{
    mylist *temp, *first, *buffer;
    temp = new mylist;
    first = temp; // зберігаємо вказівник на перший елемент
	last = NULL;
	temp->prev = NULL;
    for (int i=0; i<s.length(); i++)
    {
        temp->letter = s[i]; 
        if (i < s.length()-1) // бо нам непотрібно створювати наперед ще один елемент, коли n=1
        {    
			buffer = temp;

			temp->next = new mylist;
            temp = temp->next;

			temp->prev = buffer;
		} 
        else 
		{
			last = temp;
			temp->next= NULL; // якщо n=1 - наступна адреса вказує на NULL
		}
    }

  	return first; //повертаємо вказівник на перший (чи останній) елемент
}

void out_from_first_to_last(mylist *L)
{
    // передали функції адресу першого елементу
	cout << "\nВаш текст з початкового елементу: ";
    for ( ; L != NULL; L = L->next)
    {
        cout << L->letter;
    }

    cout << endl;
}

void out_from_last_to_first(mylist *L)
{
    // передали функції адресу останнього елементу
	cout << "\nВаш текст з кінцевого елементу: ";
    for ( ; L != NULL; L = L->prev)
    {
        cout << L->letter;
    }

    cout << endl;
}

void out_from_to(mylist *L, int from, int to)
{
	mylist *start, *end, *iterator;
	start = end = iterator = L;
    for (int i = 0; i < from; i++)
    {
        start = start->next;
    }

    for (int i = 0; i < to; i++)
    {
        end = end->next;
    }

	mylist *i;
	cout << "Слово:";
	for (i = start; i != end; i = i->next)
	{
		cout << i->letter;
	}
	cout << endl;
}

void split_to_words(mylist *L)
{
	mylist *first;
	first = L;
	int length = 0, start_with = 0;
	for ( ; L != NULL; L = L->next)
	{
   		if (L->letter == " " || L->letter == ".")
		{
			if (start_with == 0)
				out_from_to(first, start_with, start_with + length);
			else // сдікуємо за пробілами, тому start_with + 1
				out_from_to(first, start_with + 1, start_with + length);
			start_with = start_with + length;
			length = 0;
		}
		length ++;
    }
}

mylist* delete_letter(mylist *L, int index)
{
	mylist *before_the_deleted, *after_the_deleted, *delete_me, *first, *iter;;
	before_the_deleted = after_the_deleted = first = L;
	int length = 0;

    for (iter = first; iter != NULL; iter = iter->next)
        length++;

	// вказівник iter після "прогнаного циклу" == NULL

    // далі йдуть застереження, коли не працюватиме основний алгоритм (дивись після всіх if)
        
	if (length == 0)
	{
		cout << "Введений список вже порожній!" << endl;
		return first;
	}

	if (index >= length)
	{
		cout << "Введений індекс недійсний!" << endl;
		return first;
	}
	
	int size = 0;

	if (length == 1) // окремий випадок, адже немає ні попереднього, ні наступного елементу, немажє на кого "перекинути адреси"
	{
		size = 0;
		cout << "Один елемент списку займає пам'яті: " << sizeof(L) << "В" << endl;
	    for (iter = first; iter != NULL; iter = iter->next)
	        size = size + sizeof(iter);
		cout << "Весь список займає пам'яті: " << size << "В" << endl;

		delete_me = first;
		first = last = NULL;
		delete delete_me;

		size = 0;
    	for (iter = first; iter != NULL; iter = iter->next)
    	    size = size + sizeof(iter);
		cout << "Після видалення: " << size << "В" << endl;

		return first;
	} 

	if (index+1 == length)
	{
		size = 0;
		cout << "Один елемент списку займає пам'яті: " << sizeof(L) << "В" << endl;
    	for (iter = first; iter != NULL; iter = iter->next)
        	size = size + sizeof(iter);
		cout << "Весь список займає пам'яті: " << size << "В" << endl;
		
		delete_me = last;

		last = last->prev; 
		last->next = NULL;

		delete delete_me;

		size = 0;
    	for (iter = first; iter != NULL; iter = iter->next)
    	    size = size + sizeof(iter);
		cout << "Після видалення: " << size << "В" << endl;
	
		return first;
	}

	if (index == 0)
	{
		size = 0;
		cout << "Один елемент списку займає пам'яті: " << sizeof(L) << "В" << endl;
    	for (iter = first; iter != NULL; iter = iter->next)
        	size = size + sizeof(iter);
		cout << "Весь список займає пам'яті: " << size << "В" << endl;
		
		delete_me = first;
		first = first->next;
		first->prev = NULL;

		delete delete_me;

		size = 0;
    	for (iter = first; iter != NULL; iter = iter->next)
    	    size = size + sizeof(iter);
		cout << "Після видалення: " << size << "В" << endl;
	
		return first;
	}

	size = 0;
	cout << "Один елемент списку займає пам'яті: " << sizeof(L) << "В" << endl;
    for (iter = first; iter != NULL; iter = iter->next)
        size = size + sizeof(iter);
	cout << "Весь список займає пам'яті: " << size << "В" << endl;

    for (int i = 0; i < index-1; i++)
    {
        before_the_deleted = before_the_deleted->next;
    }
	delete_me = before_the_deleted->next;

	for (int i = 0; i < index+1; i++)
    {
		after_the_deleted = after_the_deleted->next;
	}
	
	// прогонка для after_the_deleted не зовсім раціональна з точки зору часу
	
	after_the_deleted->prev = before_the_deleted;
	before_the_deleted->next = after_the_deleted;

	delete delete_me;

	size = 0;
    for (iter = first; iter != NULL; iter = iter->next)
        size = size + sizeof(iter);
	cout << "Після видалення: " << size << "В" << endl;

	return first;
}

mylist* delete_list(mylist *L)
{
	mylist *temp, *first, *iter;
	first = L;

	int size = 0;
    for (iter = first; iter != NULL; iter = iter->next)
        size = size + sizeof(iter);
	cout << "Весь список займає пам'яті: " << size << "В" << endl;

	while (first) //Поки за адресою на голову списку щось є
	{
		temp = first->next; //Резервна копія адреси наступного ел. списка
		delete first; //Очистка пам’яті від першого елемента
		first = temp; // Зміна адреси голови списку на адресу наступного елемента (головою стає наступний елемент)
	}

	size = 0;
    for (iter = first; iter != NULL; iter = iter->next)
        size = size + sizeof(iter);
	cout << "Після видалення: " << size << "В" << endl;

	return first;
}

mylist* add_letter(mylist *L, int index, string letter)
{
	mylist *add_me, *first, *next_to_added, *prev_to_added;
	first = L;

    for (int i = 0; i < index-1; i++)
        L = L->next;

	prev_to_added = L;
	L = L->next;
	next_to_added = L;

	prev_to_added->next = new mylist;
	add_me = prev_to_added->next;

	add_me->letter = letter;
	add_me->next = next_to_added;
	add_me->prev = prev_to_added;

	next_to_added->prev = add_me; 

	return first;
}

int is_deleted = 0;

mylist* from_to_modified(mylist *L, int from, int to) //для task_function()
{
	mylist *start, *end, *first;
	int start_index = 0, end_index = 0;
	start = end = first = L;

    for (int i = 0; i < from; i++)
    {
        start = start->next;
		start_index++;
    }

    for (int i = 0; i < to; i++)
    {
        end = end->next;
		end_index++;
    }

	// тут end_index на одиницю більший, ніж коректна індексація
	end_index--; // тепер індексація коректна

	mylist *iter;
	int amount_of_letters = 0;
	for (iter = start; iter != end; iter = iter->next)
	{
		amount_of_letters++;
	}
		
	is_deleted = 0; //змінна, що фіксує, скільки літер видалили
	
	if (amount_of_letters % 2 != 0)
	{
		if (amount_of_letters == 1) // якщо слово з одної літери, то кінець рівний початку (викликаємо видалення лише один раз)
		{
			is_deleted = 1;
			first = delete_letter(first, start_index);
		}
		else
		{
			is_deleted = 2;
			first = delete_letter(first, start_index);
			first = delete_letter(first, end_index-1); // зсув, адже один елемент вже видалилии на попередньому кроці
		}
	}

	return first;
		
}

mylist* task_function(mylist *L) //Надрукувати всі слова, у яких непарна кількість літер. Перед друком видалити першу та останню літеру кожного слова.
{
	//void split_to_words(mylist *L)
	mylist *first, *iter;
	first = L;
	int length = 0, start_with = 0, amount_of_letters = 0;
	for ( ; L != NULL; L = L->next)
	{
   		if (L->letter == " " || L->letter == ".")
		{
			if (start_with == 0)
			{
				first = from_to_modified(first, start_with, start_with + length);
				// якщо відбулося видалення, слід зменшити довжину
				length = length - is_deleted;		
			}
			else
			{
				first = from_to_modified(first, start_with + 1, start_with + length);
				// якщо відбулося видалення, слід зменшити довжину на 2
				length = length - is_deleted;
			}
			start_with = start_with + length;
			length = 0;
		}
		length ++;
    }

	return first;
}

int main()
{
	mylist *L_first = NULL, *L_last = NULL;
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
	L_first = in(str); 

	int input = 1;

	while(input != 0)
	{

	cout << "\nПерелік можливих операцій: " << endl;
	cout << "1: вивести заданий список літер с першого елементу;" << endl;
	cout << "2: вивести заданий список літер з останнього елементу;" << endl;
	cout << "3: вивести заданий список літер від і до вказаних елементів;" << endl;
	cout << "4: розділити введений рядок по словам;" << endl;
	cout << "5: видалити елемент по заданому індексу;" << endl;
	cout << "6: видалити весь список;" << endl;
	cout << "7: додати елемент по заданому індексу;" << endl;
	cout << "8: надрукувати всі слова, у яких непарна кількість літер. Перед друком видалити першу та останню літеру кожного слова;" << endl;
	cout << "0: завершити роботу;" << endl;

	cin >> input;
	switch (input)
	{
		case 1: {
			out_from_first_to_last(L_first);
			break;
		}
		case 2: {
			L_last = last; 
			out_from_last_to_first(L_last);
			break;
		}
		case 3: { 
			cout << "Введіть через пробіл початковий та кінцевий номери елементів" << endl;
			int start, end;
			cin >> start >> end;

			int start_time =  clock();

			out_from_to(L_first, start, end);	
	
			int end_time = clock();
			int search_time = end_time - start_time;
			cout << "Затрачено часу: " << search_time*0.001 << "c" << endl;
			break;
		}
		case 4: {
			split_to_words(L_first);
			break;
		} 
		case 5: {
			cout << "Введіть індекс елемента (лічба починається з нуля), який бажаєте видалити" << endl;
			int i_delete;
			cin >> i_delete;
			L_first = delete_letter(L_first, i_delete);
			out_from_first_to_last(L_first);
			break;
		}
		case 6: {
			delete_list(L_first);
			break;
		}
		case 7: {
			cout << "Введіть через пробіл індекс та значення елемента, який бажаєте додати" << endl;
			int index_add;
			string letter_add;
			cin >> index_add >> letter_add;
			L_first = add_letter(L_first, index_add, letter_add);
			out_from_first_to_last(L_first);
			break;
		}
		case 8: {
			L_first = task_function(L_first);
			out_from_first_to_last(L_first);
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
