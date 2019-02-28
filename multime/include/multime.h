#ifndef MULTIME_H
#define MULTIME_H


class multime
{
    int n, *p;
    int max_size;
    public:
        multime();
        multime(const multime &);
        ~multime();

        void insertion(int );
        void sterge(int );
        int cautare(int );
        int get_size();
        void afisare(int );
        int suma();
        multime pare();
        multime impare();

         int & operator[](int );
         multime operator+(const multime &m2);
         multime operator*(int valoare);
         multime & operator=(const multime &);
         bool operator<(const multime &m2);
         bool operator>(const multime &m2);

};

#endif // MULTIME_H
