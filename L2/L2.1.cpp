#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int min, cap, k, compare = 0, move = 0;
	int l = 10000, m[l];

    for (int i = 0; i < l; i++)
        m[i] = rand()%5000;
	
	//int m[l] = {5,4,3,2,1}	

	cout << "Початковий масив:   ";
	for (int i = 0; i < l; i++)
        cout << m[i] << " ";
    cout << endl;	
	
//int time = 0,n=200;
//float  time_av=0;
 
//for (int f=0; f<n; f++)
//{
	int start_time =  clock();

  	for (int i = 0; i < l; i++)
    {
    	min = m[i];
    	k = i;
    	for (int j = i + 1; j < l; j++)
    	{
    		if (m[j] < min)
    	    {
        		min = m[j];
        		k = j;
      		}
			compare += 1;
    	}
    	cap = m[k];
    	m[k] = m[i];
    	m[i] = cap;
		if(k != i)
			move += 1;
  	}

	int end_time = clock();
	int search_time = end_time - start_time;

	//time += search_time;
//}

	//time_av = time/n;
	cout << "Вісортований масив: ";
  	for (int i = 0; i < l; i++)
  	{
  		cout << m[i] << " ";
  	}
  	cout << endl;

	cout << "elements = " << l << endl;
	cout << "compare = " << compare << endl;
	cout << "move = " << move << endl;
	cout << "time = " << search_time*0.001 << "c" << endl;
}
