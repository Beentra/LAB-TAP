#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct interval
{
    int s,t;
};

int cmp(interval x,interval y)
{
    return x.t<y.t;
}

 interval a[100];//vector in care vom retine ultima valoare de pe fiecare linie a matricii


//Lazar Alexandru 232
int main()
{
    ifstream f("date.in");
    int i,j,n,nr_procesoare=0,rr,cc;
    vector<interval> v;
    interval aux,ua;

    f>>n;
    for(i=0;i<n;i++)
    {
        f>>aux.s>>aux.t;
        v.push_back(aux);
    }
    sort(v.begin(),v.end(),cmp);
    a[0]=v[0];
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j].t<v[i].s)
            {
                a[j]=v[i];
                break;
            }
        }
    }


    for(i=0;i<n;i++)
        if(a[i].s!=0 && a[i].t!=0)
            nr_procesoare++;






//intuitiv consideram ca puenm intervalele intr-o matrice
//fiecare linie insemnand un procesor iar elementele din el fiind task-urile de pe procesorul respectiv
//vectorul a se traduce sub forma a[j]=x -> x este ultimul elemet de pe linia j(x este ultimul proces de pe procesorul j
//vom testa fiecare input sa vedem pe ce procesor s-ar potrivi,iar daca nuse potriveste pe nici unul creeam unul nou si il punem pe acesta
//la final numaram cate elem sunt vectorul a si vom afla nr de procesare necesare








    cout<<"nr procesoare="<<nr_procesoare;


    return 0;
}
