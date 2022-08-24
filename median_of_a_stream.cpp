#include<bits/stdc++.h>
int signumm(int a,int b){
    if(a==b) return 0;
    else if(a>b) return 1;
    else return -1;
}
void call_median(int ele,priority_queue<int> &maxi, priority_queue<int,vector<int>,greater<int>> &mini,int &median)
{
    switch(signumm(maxi.size(),mini.size())){
           case 0: if(ele>median){
               mini.push(ele);
               median=mini.top();
           }
            else{
                maxi.push(ele);
                median=maxi.top();
            }
            break;
            case 1 : if(ele>median){
                mini.push(ele);
                median=(mini.top()+maxi.top())/2;
            }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(ele);
                median=(mini.top()+maxi.top())/2;
            }
            break;
        case -1: if(ele>median){
            maxi.push(mini.top());
            mini.pop();
            mini.push(ele);
            median=(mini.top()+maxi.top())/2;
        }
            else{
             maxi.push(ele);
              median=(mini.top()+maxi.top())/2;   
            }
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> temp;
    int median=0;
    for(int i=0;i<n;i++){
        call_median(arr[i],maxheap,minheap,median);
        temp.push_back(median);
    }
    return temp;
}
