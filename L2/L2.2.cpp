#include <iostream>
#include <ctime>
using namespace std;

int compare = 0, moves = 0;

void quicksort(int *m, int l, int r)
{
	int i = l, j = r, cap, c = (l+r)/2, pivot = *(m+c);

	while (i <= j)
	{
		while (*(m+i) < pivot)
		{
			i++;
			compare++;
		}
		if (*(m+i) == pivot) 
			compare++;

		while (*(m+j) > pivot)
		{
			j--;
			compare++;
		}
		if (*(m+j) == pivot) 
			compare++;

		if (i <= j)
		{
			cap = *(m+i);
			*(m+i) = *(m+j);
			*(m+j) = cap;

			i++;
			j--;

			moves++;
		}
	}
	
	if (l < j)
		quicksort(m, l, j);
	if (i < r)
		quicksort(m, i, r);
}

int main()
{
	int l = 7, m[l];

    for (int i = 0; i < l; i++)
      m[i] = rand()%20;	

	//int l=6, m[l] = {8,11,2,5,8,10};

	cout << "Початковий масив:   ";
	for (int i = 0; i < l; i++)
        cout << m[i] << " ";
    cout << endl;	
	
int n=1, time = 0;
for (int i=0; i<n; i++)
{
	int start_time =  clock();

	quicksort(m,0,l-1);	
	
	int end_time = clock();
	int search_time = end_time - start_time;
	time = time + search_time;
}

	cout << "Вісортований масив: ";
  	for (int i = 0; i < l; i++)
  	{
  		cout << m[i] << " ";
  	}
  	cout << endl;

	cout << "elements = " << l << endl;
	cout << "compare = " << compare << endl;
	cout << "moves = " << moves << endl;
	cout << "time = " << time/n*0.001 << "c" << endl;
}
