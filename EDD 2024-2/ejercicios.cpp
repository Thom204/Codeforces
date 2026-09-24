#include <iostream>
#include <bits/stdc++.h>
#define PI 3.1415

using namespace std;

//tipo de retorno NombreFuncion(argumentos){}

//tipos:
//  primitivos: int, double, float, null_ptr, char, bool, string

//  compuesto: int[], vector<char>

// paso por valor vs paso por referencia.

string funcion_1(string s, char c){
    //s pas por valor (como copia)
    return s+c;
}

void funcion(string& s, char c){
    // s pasa por referencia
    s+=c;
}

void funcion_2(string *p, char c){
    // p accede a la direccion de memoria, *p accede al contenido
    *p +=c;
}


int funcion(int i, int j){
    return i*j;
}

void foo(){}

int main(){
    int b =25;
    string s= "zwcyvgubhnkjsbdindknvknsknkswdkckdjsnkjvsdkjnknvjzvknkndsknvkndsnkvnksnkvnsdjicnx";
    string *ss = &s; //puntero a s
    //funcion(*&s, 'c');
    funcion_2(&s, 'c');
    cout << s << endl;
    return 0;
}