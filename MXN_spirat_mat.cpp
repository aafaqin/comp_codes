#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void print_boundry(vector<vector <int>> arr,int diag,int m,int n){
        int i=diag;
        int j;

        for(j= diag;j<n-diag;j++)
            cout<<arr[i][j]<<" ";
            
        j--;
    
        for (i =i+1;i<m-diag;i++)
            cout<<arr[i][j]<<" ";
         if(m-1<=diag+1 ||n-1<=diag+1 )
             return;
        i--;
        for(j= j-1;j>=diag;j--)        
            cout<<arr[i][j]<<" ";
        
        j++;
        for(i=i-1;i>diag;i--)
            cout<<arr[i][j]<<" ";
}

int main() {
    int m,n;
    cin>>m>>n;
    //take 2 d vector input now in arr
    vector <vector <int>> arr;
    arr.resize(m,vector<int>(n));
    for(int i=0;i<m;i++){        
        for(int j=0;j<n;j++){
            std::cin>>arr[i][j];
        }
    }
    //outermost loop runing for the number of box like spiral sub parts
    int min;
    if (m<n)
        min=m;
    else min=n;
    // if (m==1){
    //     print_boundry(arr, 0,m,n);
    // }
    for(int diag=0;diag<=ceil(min/2);diag++){
        // cout<<arr[diag][diag];      
       // cout<<"**"<<m<<" "<<n<<" "<<diag<<" "<<"**";
        print_boundry(arr, diag,m,n);
    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
