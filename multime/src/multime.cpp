#include "multime.h"
#include <iostream>

using namespace std;

multime::multime()
{
    n=0;
    max_size=30;
    p=new int [max_size];
}

multime::multime(const multime &m)
{
    //constructor de copiere
    n=m.n;
    p=new int[n];
    for(int i=0;i<n;i++)
        p[i]=m.p[i];
}

multime::~multime()
{
    delete [] p;
}

void multime::insertion(int val)
{
    int gasit=0;
    int poz_multime=0;

    if(n==0)
    {
        p[n]=val;
        n++;
    }
    else
    {
        while(p[poz_multime]<val && poz_multime<n)
            {
             poz_multime++;
            }
        if(p[poz_multime]==val)
            gasit=1;
        if(gasit==0 && poz_multime==n)
        {
        p[n]=val;
        n++;
        }
        else if(gasit==0)
            {
            int *aux;
            aux=new int[max_size];
            int poz_aux=0;
            for(int i=0;i<poz_multime;i++)
                aux[poz_aux++]=p[i];
            for(int i=n;i>poz_multime;i--)
                aux[i]=p[i-1];
            aux[poz_aux]=val;
            this->n++;
            for(int i=0;i<n+1;i++)
                p[i]=aux[i];
            delete [] aux;
            }
    }

}

int multime::cautare(int val)
{
    for(int i=0;i<n;i++)
        if(p[i]==val)
            return i;
}

void multime::sterge(int val)
{
    int *aux, poz_aux=0;
    aux=new int[n];
    for(int i=0;i<n;i++)
        if(p[i]!=val)
            aux[poz_aux++]=p[i];
    for(int i=0;i<poz_aux;i++)
        p[i]=aux[i];
    n--;
    delete [] aux;

}
multime& multime::operator=(const multime &val)
{
    if(this==&val)
        return *this;
    n=val.n;
    p=new int[val.n];

    for(int i=0;i<n;i++)
        p[i]=val.p[i];
    return *this;
}

int multime::get_size()
{
    return n;
}
int multime::suma()
{
    int s=0;
    for(int i=0;i<n;i++)
        s=s+p[i];
    return s;

}

int& multime:: operator[](int i){
  if(i>=0 && i<n)
    return p[i];
}

multime multime::operator+(const multime &m2)
{
  multime aux;

  int poz_m1=0,poz_m2=0,poz_aux=0;

  while((poz_m1<n) &&( poz_m2<m2.n))
  {
      if(p[poz_m1]<m2.p[poz_m2])
        {
            aux.p[poz_aux++]=p[poz_m1++];
        }
      else
        if(p[poz_m1]==m2.p[poz_m2])
        {
          aux.p[poz_aux++]=p[poz_m1++];
          poz_m2++;
        }
        else
            aux.p[poz_aux++]=m2.p[poz_m2++];
  }
  while(poz_m1<n)
     aux.p[poz_aux++]=p[poz_m1++];
  while(poz_m2<m2.n)
     aux.p[poz_aux++]=m2.p[poz_m2++];
     aux.n=poz_aux;
  return aux;

}
multime multime::operator*(int val)
{
    multime aux;
    aux.n=n;
    for(int i=0;i<aux.n;i++)
        aux.p[i]=val*p[i];
    return aux;
}
bool multime::operator<(const multime &m2)
{
    if(n<m2.n)
        return true;
    else
        return false;

}
bool multime::operator>(const multime &m2)
{
    if(n>m2.n)
        return true;
    else
        return false;

}
multime multime::pare()
{
    multime aux;
    int poz_aux=0;
    for(int i=0;i<n;i++)
        if(p[i]%2==0)
         aux.p[poz_aux++]=p[i];
    aux.n=poz_aux;
    return aux;
}
multime multime::impare()
{
    multime aux;
    int poz_aux=0;
    for(int i=0;i<n;i++)
        if(p[i]%2)
         aux.p[poz_aux++]=p[i];
    aux.n=poz_aux;
    return aux;
}
