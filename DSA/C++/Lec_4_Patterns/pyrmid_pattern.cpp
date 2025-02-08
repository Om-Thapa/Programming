//Pattern 
//     1
//    121
//   12321
//  1234321
#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"Enter n : ";
    cin >> n;
    cout<<endl;
    for(i=1;i<=n;i++){
        for(j=n;j>i;j--)
        cout << " ";
        for(j=1;j<i+1;j++)
        cout << j ;
        j=j-2;
        for( ;j>0;j--)
        cout << j;
        cout<<endl;
    }
    return 0;
}