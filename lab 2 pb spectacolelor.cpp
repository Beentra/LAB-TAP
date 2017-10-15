#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//Lazar Alexandru Gr. 232
//Pb. Spectacolelor
using namespace std;

struct spec
{
    int a,b;//a-inceput b-sfarsit
};

int cmp(spec x,spec y)
{
    return(x.b<y.b);
}

int main()
{
    ifstream f("date.in");
    int n,i,j;//n nr spectacole
    spec aux,ua;//ua-ultima activitate intratata in vectorul v1
    vector<spec> v;//vector de memorare a intervalelor
    vector<spec> v1;//vectorul in care vom memora rezultatul

    f>>n;

    for(i=0;i<n;i++)
    {
        f>>aux.a>>aux.b;
        v.push_back(aux);
    }

    sort(v.begin(),v.end(),cmp);//sortam vectorul de spectacole in ordine crescatoare dupa timpul de sf al fiecarei activitati
    v1.push_back(v[0]);
    ua=v[0];

    for(i=1;i<n;i++)
        if(v[i].a>ua.b)
        {
            v1.push_back(v[i]);
            ua=v[i];
        }

    for(i=0;i<v1.size();i++)
        cout<<"["<<v1[i].a<<" , "<<v1[i].b<<"]"<<endl;

    return 0;
}
