#include<bits/stdc++.h>
using namespace std;
void printarray(vector<int>& a,int n){
for(int k=0;k<n;k++){
        cout<<a[k]<<" ";
        }
}
void counting(vector<int>& a){
    int max=*max_element(a.begin(),a.end());
    int min=*min_element(a.begin(),a.end());
    int range=max-min+1;
    vector<int> count(range),output(a.size());
    
    for(int i=0;a[i];i++){
       count[a[i]-1]++; 
    }
    for(int i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    for(int i=a.size()-1;i>=0;i--){
       output[count[a[i]-min]-1]=a[i];
       count[a[i]-min]--;
    }
    
    for (int i = 0; i < a.size(); i++)
        a[i] = output[i];
    printarray(output,a.size());
    
}
int main(){
    vector<int> a={8,1,4,4,3,2,1,5};   
        counting(a);
        
    //printarray(a,n);
    return 0;
}