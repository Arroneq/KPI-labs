#include <iostream>
using namespace std;

struct Node //Структура, що є елементом списку
{ 
	int x; //Значення ключа key
	Node *Next,*Prev; //Вказівники на наст. і попередній ел.списку
};

class List //Тип даних Список
{
	Node *Head,*Tail; //Вказівники на голову та хвіст списку

	public:
		List():Head(NULL),Tail(NULL){}; //Конструктор за замовчуванням
		~List(); //Деструктор
		void Show(); //Функція відображення списку на екрані
		void Add(int x); //Функція додавання елементу в список
};

List::~List() //Деструктор
{
	Node *temp;
	while (Head) //Поки за адресою на голову списку щось є
	{
		temp=Head->Next; //Резервна копія адреси наступного ел. списка
		delete Head; //Очистка пам’яті від першого елемента
		Head=temp; // Зміна адреси голови списку на адресу наступного елемента (головою стає наступний елемент)
	}
}

void List::Add(int x)
{ 
	Node *temp=new Node; //Виділення пам’яті під новий елемент списку
	temp->Next=NULL; //У цього ел. спочатку за наступною адресою порожньо
	temp->x=x;//Записуємо значення в поле х (key) цього елемента
	if (Head!=NULL) //Якщо список непорожній
	{
		temp->Prev=Tail; //Вказуємо адресу на попередній елемент у відповідне поле Prev новоствореного елемента
		Tail->Next=temp; //Вказуємо адресу наступного за хвостом елемента (щойноствореного)
		Tail=temp; //Змінюємо адресу хвоста
	}
	else //Якщо список порожній
	{
		temp->Prev=NULL; //В поле Prev новоствореного елемента записуємо NULL (перед ним немає елементів)
		Head=Tail=temp; //Голова і хвіст – це той елемент, який щойно додали
	}
}

void List::Show()
{
	//Виводимо список з кінця
	Node *temp=Tail; //Тимчасовий вказівник (записуємо в нього адресу останнього елемента)

	while (temp!=NULL) //Поки не зустрінеться порожнє значення (NULL)
	{
		cout<<temp->x<<" "; //Вивести значення елемента на екран
		temp=temp->Prev; //Перехід до попереднього елемента
	}
	
	cout<<"\n";
	
	// Виводимо список спочатку	
	temp=Head; //Тимчасовий вказівник вказує на адресу першого елемента
	while (temp!=NULL) // Поки не зустрінеться порожнє значення (NULL)
	{
		cout<<temp->x<<" "; // Вивести значення елемента на екран
		temp=temp->Next; // Перехід до наступного елемента
	}

	cout<<"\n";
}

int main ()
{
	List lst; //Оголошуємо змінну типу List
	lst.Add(100); //Додаємо елементи до списку
	lst.Add(200);
	lst.Add(300);
	lst.Add(400);
	lst.Show(); //Виводим список на екран
}
