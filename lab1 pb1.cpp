#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
//Lazar Alexandru gr 232
//se da un vector de n nr si un S, sa se afle o pereche (i,j) a.i. a[i]+a[j]=s

using namespace std;

struct nr
{
    int val;
    int indice;
};

bool cmp(nr i, nr j)
{
    return(i.val<j.val);
}


void caz1(vector<int> a, int n, int s)
{
    //O(n^2)
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n-2;j++)
            if(a[i]+a[j]==s)
                cout<<i<<" "<<j<<endl;

    cout<<endl;
}

 void caz2(vector<nr> b, int n, int s)
{
    //O(n logn)
    sort(b.begin(),b.end(),cmp);
    int i,j;
    i=0;
    j=n-1;
    while(i<j)
        if(b[i].val+b[j].val==s)
        {
            cout<<b[j].indice<<" "<<b[i].indice<<endl;//?ordinea i,j
            break;
        }
        else
            if(b[i].val+b[j].val<s)
                i++;
            else
                j--;


    cout<<endl;

}


void caz3(vector<int> a,int n,int s)
{
    int i,complement;
    map<int, int> x;
    for(i=0;i<n;i++)
        x.insert(pair<int,int>(a[i],i));
    for(i=0;i<n;i++)
    {
        complement=s-a[i];
        if(x.find(complement)!=x.end() && x[complement]!=i)
            cout<<i<<" "<<x[complement]<<endl;
    }
    cout<<endl;
}



int main()
{
    vector<int> a;
    vector<nr> b;
    int i ,n,aux,s;
    nr aux2;

    ifstream f("date.in");
    //citire
    f>>n>>s;
    for(i=0;i<n;i++)
    {
        f>>aux;
        a.push_back(aux);
        aux2.val=aux;
        aux2.indice=i;
        b.push_back(aux2);
    }

    caz1(a,n,s);//O(n^2)
    caz2(b,n,s);//O(n logn)
    caz3(a,n,s);//O(n)  //afiseaza si inversele



    return 0;
}
