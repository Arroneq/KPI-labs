#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Відмінно : Побудувати двійкове дерево пошуку з букв рядка, що вводиться. Вивести його на екран у вигляді дерева. Знайти букви, що зустрічаються більше одного разу. Видалити з дерева ці літери. Вивести елементи дерева, що залишилися, при його постфіксному обході.

// Добре : Побудувати двійкове дерево пошуку з цілих чисел, що вводиться. Вивести його на екран у вигляді дерева. Знайти вершину, яка містить задане число. Визначити максимальний елемент в цьому дереві.

// Реалізувати основні операції роботи з деревом: обхід дерева, включення, виключення та пошук вузлів.

struct mytree
{
    char letter;
    mytree *right, *left, *parent;

};

mytree *root = NULL;

void add_element(mytree *add_me)
{
	mytree *x = root, *y = NULL;

	while (x != NULL)
	{
		y = x; // записуємо останній ненульовий (тобто майбутнього батька)

		if (add_me->letter < x->letter) // "b" > "a"
			x = x->left;
		else
			x = x->right;	
	}

	add_me->parent = y;
	
	if (y == NULL) // значит 'х' = root = NULL, порожнє дерево, 'у' не змінився
		root = add_me;  
	else
	{
		if (add_me->letter < y->letter) // "b" > "a"
			y->left = add_me;
		else
			y->right = add_me;
	}
}

void create_tree()
{
	string str;
	bool input_str = 1;

	cout << "Введіть текст" << endl;
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
	
	mytree *temp = new mytree;
	temp->parent = temp->right = temp->left = NULL;

	for (int i=0; i<str.length(); i++)
	{
		if (str[i] != ' ')
		{
			if (i != str.length()-1)
			{	
				temp->letter = str[i];
				add_element(temp);
				mytree *previous_parent = temp;
				temp = new mytree;
				temp->parent = previous_parent;
				temp->right = temp->left = NULL;
			}
			else
			{	
				temp->letter = str[i];
				add_element(temp);
			}
		}
	}
}

mytree* max_tree(mytree *find_me)
{
	mytree *temp = find_me;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

mytree* min_tree(mytree *find_me)
{
	mytree *temp = find_me;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}	

void print_tree(mytree *p, int level)
{
    if (p != NULL)
    {
        print_tree(p->right, level + 1);
        for (int i=0; i<level; i++) 
			cout << "  ";
        cout << p->letter << endl;
        print_tree(p->left, level + 1);
    }
}

void print_tree_inorder(mytree *p) // симетричний обхід, відсортований в порядку зростання
{
	if (p != NULL)
	{
		print_tree_inorder(p->left);
		cout << p->letter;
		print_tree_inorder(p->right);
	}
}

void print_tree_preorder(mytree *p)
{
   	if (p != NULL)
	{
    	cout << p->letter;
    	print_tree_preorder(p->left);
        print_tree_preorder(p->right);
	}
}

void print_tree_postorder(mytree *p)
{
   	if (p != NULL)
	{
        print_tree_postorder(p->left);
        print_tree_postorder(p->right);
    	cout << p->letter;
	}
}

mytree* search(mytree *x, char search_me)
{
    if (x == NULL or search_me == x->letter)
        return x;
    if (search_me < x->letter)
        return search(x->left, search_me);
    else
        return search(x->right, search_me);
}

mytree* successor(mytree *find_me) // наступний за значенням елемент
{
    if (find_me->right != NULL) // мінімальний у правому піддереві (якщо воно існує)
        return min_tree(find_me->right);
 
	mytree *temp = find_me->parent;

    while (temp != NULL and find_me == temp->right) // доки не стане лівим сином свого батька
	{
		find_me = temp;
		temp = temp->parent;	
	}

	return temp;
}

mytree* delete_element(mytree *delete_me)
{
	// 1: у вершини немає синів (delete_me->parent = NULL)
	// 2: у врршини є лише один із синів (delete_me->parent = delete_me->son)
	// 3: у вершини є два сини

	mytree *temp1; // яку вершину видаляємо насправді
	mytree *temp2; // син вершини, яку видаляємо

	if (delete_me->left == NULL or delete_me->right == NULL) // 1 or 0 : 0 or 1 : 1 or 1 тобто коли або обидві вершини NULL, або немає лише однієї з вершин 
		temp1 = delete_me; //тоді видаляємо саму вершину, випадки 1) та 2)
	else
		temp1 = successor(delete_me); //інакше видалятимемо, фактично, наступну за значенням вершину

	if (temp1->left != NULL) // підгонка під випадок 2), зберігаємо адресу дитини, тобтo delete_me->son
		temp2 = temp1->left;
	else
		temp2 = temp1->right;	

	if (temp2 != NULL) // P<--S
		temp2->parent = temp1->parent;		

	if (temp1->parent == NULL) 
		root = temp2;
	else                 // P-->S : delete_me->parent = delete_me->son
	{
		if (temp1 == temp1->parent->left) // якщо син був лівим, то у для нової вершини стане лівим
			temp1->parent->left = temp2;
		else
			temp1->parent->right = temp2;
	}

	if (temp1 != delete_me) // підгонка під випадок 3), якщо видалена де-факто і де-юре вершини різні
		delete_me->letter = temp1->letter;

	return temp1;
}

int main()
{
	create_tree(); //smcqutyor

	mytree *max_element, *min_element;
	max_element = max_tree(root);
	min_element = min_tree(root);

	cout << endl;
	print_tree(root, 0);
	cout << endl;

	cout << "Максимальний елемент дерева: " << max_element->letter << endl;
	cout << "Мінімальний елемент дерева: " << min_element->letter << endl;

	cout << "\nPrint tree inorder: ";
	print_tree_inorder(root);
	cout << endl;

	cout << "Print tree preorder: ";
	print_tree_preorder(root);
	cout << endl;

	cout << "Print tree postorder: ";
	print_tree_postorder(root);
	cout << endl;

	mytree *search_letter;
	search_letter = search(root, 'q');
	cout << "\nSearched letter: " << search_letter->letter << endl;

	mytree *successor_letter;
	successor_letter = successor(search_letter);
	cout << "Successored letter: " << successor_letter->letter << endl;

	delete_element(search_letter);
	cout <<endl;

	print_tree(root, 0);
	cout << endl;
}





