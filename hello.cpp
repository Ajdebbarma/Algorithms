#include<iostream>
#include<climits>
using namespace std;
    int main(){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

    int mini = INT_MAX;
        int maxNo=0;
        for(int i=0; i<n; i++){
            mini = min(mini, arr[i]);
            maxNo = max(maxNo, arr[i]-mini);
        }
        cout<<mini<<endl;
        cout<<maxNo;
      return 0;    

}
    


    





    

    
    
