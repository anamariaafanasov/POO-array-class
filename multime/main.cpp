#include <iostream>
#include "multime.h"

using namespace std;

int main()
{
    multime m1,m2,reuniune,impare;
    int nr_elem_m1,nr_elem_m2,nr_elem_suma;

    m1.insertion(3);
    m1.insertion(2);
    m1.insertion(8);
    m1.insertion(1);
    m1.insertion(8);
    m1.insertion(2);
    m1.insertion(-5);
    m1.insertion(4);

    cout<<"m1:";
    nr_elem_m1=m1.get_size();
    for(int i=0;i<nr_elem_m1;i++)
       cout<<m1[i]<<" ";
    cout<<endl;

    cout<<"impare din m1:";
    impare=m1.impare();
    for(int i=0;i<impare.get_size();i++)
        cout<<impare[i]<<" ";
    cout<<endl;

    int valoare_de_sters;
    cout<<"citeste valoare de sters din prima multime:";
    cin>>valoare_de_sters;
    m1.sterge(valoare_de_sters);
    cout<<"noua multime m1:";
    nr_elem_m1=m1.get_size();
    for(int i=0;i<nr_elem_m1;i++)
        cout<<m1[i]<<" ";
    cout<<endl;
    cout<<"m2:";

    m2.insertion(7);
    m2.insertion(1);
    m2.insertion(9);
    m2.insertion(3);
    nr_elem_m2=m2.get_size();
    for(int i=0;i<nr_elem_m2;i++)
        cout<<m2[i]<<" ";
    cout<<endl;
    if(m1>m2)
        cout<<"card(m1)>card(m2)"<<endl;
    else
        cout<<"card(m1)<card(m2)"<<endl;
    reuniune=m1+m2;
    nr_elem_suma=reuniune.get_size();
    cout<<"reuniune:";
    for(int i=0;i<nr_elem_suma;i++)
        cout<<reuniune[i]<<" ";
    cout<<endl;
    cout<<"suma elemente din m2=";
    cout<<m2.suma()<<endl;

    int scalar;
    cout<<"citeste scalar:";
    cin>>scalar;
    cout<<"inmultire elem din m2 cu scalar=";
    m2=m2*scalar;
    for(int i=0;i<nr_elem_m2;i++)
        cout<<m2[i]<<" ";
    cout<<endl;





    return 0;
}
