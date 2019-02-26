#include<iostream>
using namespace std;
struct T{
    int time,score;
};
T* a;
bool* used;
int* days;
void quickSort(int start,int end){
    while(start<end){
        int low=start;
        int high=end;
        T key=a[low];
        while(low<high){
            while(low<high&&a[high].score<=key.score){
                high--;
            }
            a[low]=a[high];
            while(low<high&&a[low].score>=key.score){
                low++;
            }
            a[high]=a[low];
        }
        a[low]=key;
        quickSort(start,low-1);
        start=low+1;
    }
}
int main()
{
    int n;
    cin>>n;
    a=new T[n];
    int maxDay=0;
    for(int i=0;i<n;i++){
        cin>>a[i].time>>a[i].score;
        if(a[i].score>maxDay){
            maxDay=a[i].score;
        }
    }
    used=new bool[maxDay+1];
    days=new int[maxDay+1];
    for(int i=0;i<=maxDay;i++){
        used[i]=false;
        days[i]=i-1;
    }
    for(int i=0;i<n;i++){
        int day=a[i].time,score=a[i].score;
        bool ok=!used[day]&&i;
        if(ok){
            
        }
    }
}