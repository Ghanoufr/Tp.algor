#include <iostream>

#include<vector>

#include <chrono>

using std::vector;

using namespace std;

using namespace std::chrono;

void echanger(int *a, int *b);

int partition(vector<int>&V, int l, int h);

void tri_rapide(vector<int>&V, int l, int h);

int main(){

    vector <int> V;

    int n;

    cout<<"donner la taille du tableau";

    cin>>n;

    int i=n;

    while (i>0)

    {

        V.push_back(i);

        i--;

    }

    for (int i = 0; i < V.size(); i++)

    {

      cout<<V[i]<<"\n";

    }

   

    auto start = high_resolution_clock::now();

    tri_rapide(V, 0, V.size()-1);

    auto stop = high_resolution_clock::now();

 

    cout << "Time taken by function: "

         << duration_cast<microseconds>(stop - start).count() << "microseconds" << endl;

    for (int i = 0; i < V.size(); i++)

    {

      cout<<V[i]<<"\n";

    }

   return (0);

}

void echanger(int *a, int *b) {

  int t = *a;

  *a = *b;

  *b = t;

}

int partition(vector<int>&V, int l, int h){

  int pivot = V[h];

  int i = (l- 1);

  for (int j = l; j < h; j++){

    if (V[j] <= pivot){

      i++;

      echanger(&V[i],&V[j]);

    }

  }

  echanger(&V[i + 1],&V[h]);

  return (i + 1);

}

void tri_rapide(vector<int>&V, int l, int h){

  if (l < h){

    int p = partition(V, l, h);

    tri_rapide(V, l, p-1);

    tri_rapide(V, p+1,h);

  }

}

