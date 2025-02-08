//Pattern:
// *             *
// * *         * *
// * * *     * * *
// * * * * * * * *
// * * * * * * * *
// * * *     * * *
// * *         * *
// *             *
#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"Enter value of n : ";
    cin>>n;
    cout<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)
        cout<<"* ";
        for(j=i*2;j<2*n-2;j++)
        cout<<"  ";
        for(j=0;j<=i;j++)
        cout<<"* ";
        cout<<endl;
    }
    for(i=0;i<n;i++){
        for(j=i;j<n;j++)
        cout<<"* ";
        for(j=i*2;j>0;j--)
        cout<<"  ";
        for(j=i;j<n;j++)
        cout<<"* ";
        cout<<endl;
    }
}