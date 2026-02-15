#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
 
const int MAX = 100;
void max_min(int a[], int i, int j, int &max, int &min){
    int mid, maximum, minimum;
    if(i == j){
        max = min = a[i];
    }
    else if(i == j - 1){
        if(a[i] < a[j]){
            max = a[j];
            min = a[i];
        }
        else{
            max = a[i];
            min = a[j];
        }
    }
    else{
        mid = (i + j) / 2;
        max_min(a, i, mid, max, minimum);
        max_min(a, mid + 1, j, maximum, min);
 
        if(max < maximum){
            max = maximum;
        }
        if(min > minimum){
            min = minimum;
        }
    }
}
int main(){
    int n;
    int a[MAX];
    int max, min, min_el, max_el;
    srand(time(0));
    ofstream fout("min_max.txt");   
 
     cout<<"Enter minimum number of elements: ";
    cout<<"Enter minimum number of elements: ";
    cin>>min_el;
    cout<<"Enter maximum number of elements: ";
    cin>>max_el;
    cout<<endl;
 
    fout << "n time_ns array_values\n";  
    for(int n = min_el; n <= max_el; n++){
        cout<<"Number of elements = "<<n<<endl;
        for(int i = 0; i < n; i++){
            a[i] = rand() % 100; 
            cout<<a[i]<<" ";
        }
        cout<<endl;
   
        auto start = std::chrono::high_resolution_clock::now();
        max_min(a, 0, n-1, max, min);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
        cout<<"Maximum element = "<<max<<endl;
        cout<<"Minimum element = "<<min<<endl;
        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;
 
        fout << n << " " << duration.count() << "\n";
    }
    fout.close();
    return 0;
}
