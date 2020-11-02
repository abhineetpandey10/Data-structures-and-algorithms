#include<iostream>
using std::cin;
using std::cout;
int merge(int a[],int tmp[],int start,int mid,int end)
{
    int i=start,j=mid+1,l1=mid-start+1,l2=end-mid,k=start;
    int invCount=0;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
            tmp[k++]=a[i++];
        else
        {
            tmp[k++]=a[j++];
            invCount+=(mid+1-i);
        }
    }
    while(i<=mid)
        tmp[k++]=a[i++];
    while(j<=end)
        tmp[k++]=a[j++];
    for(int p=start;p<=end;p++)
        a[p]=tmp[p];
    return invCount;
}
int countInversions(int a[],int tmp[],int start, int end)
{
    int invCount=0,mid=0;
    if(start<end)
    {
        mid=start+(end-start)/2;
        invCount+=countInversions(a,tmp,start,mid);
        invCount+=countInversions(a,tmp,mid+1,end);
        invCount+=merge(a,tmp,start,mid,end);
    }
    return invCount;
}
int mergeSort(int a[],int size)
{
    int tmp[size];
    return countInversions(a,tmp,0,size-1);
}
int main()
{
    int a[]={4,2,10,12,-102,56};
    cout<<mergeSort(a,6);
}
