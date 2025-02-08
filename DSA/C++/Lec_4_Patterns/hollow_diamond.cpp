//        *
//      *   *
//    *       *
//  *           *
//    *       *
//      *   * 
//        *
#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout << "Enter n : ";
    cin>>n;
    cout<<endl;
    for(i=1;i<=n;i++){
        for(j=n;j>i;j--)
        cout<<"  ";
        cout << "* ";
        if(i!=1){
            for(j=1;j<=2*i-3;j++)
            cout<<"  ";
            cout<<"* ";
        }
        cout<<endl;
    }
    for(i=n-1;i>=1;i--){
        for(j=i;j<n;j++)
        cout<<"  ";
        cout << "* ";
        if(i!=1){
            for(j=1;j<=2*i-3;j++)
            cout<<"  ";
            cout<<"* ";
        }
        cout<<endl;
    }
}