#include <iostream>
#include <deque>
using namespace std;


int indef_splitCountToDeque(string input,deque<int>& arr, string delim){
    int size;
    size_t start= 0;
    int len= delim.length();
    for(size_t i=0; i<input.length(); i++){
        if(input.substr(i, len) == delim){
            arr.push_back(stoi(input.substr(start, i-start)));
            start= i+len;
            size++;
        }
    }
    arr.push_back(stoi(input.substr(start)));
    size++;
    return size;
}

int main() {
    int C;
    string in; 
    cin >> C;
    
    for (int _ = 0; _ < C; ++_) {
        int n; 
        
        getline(cin>>ws, in);
        deque<int> piezas; 

        int altura= indef_splitCountToDeque(in, piezas, " "); 
        
        while (altura > 1) {
            int a = piezas.back(); 
            piezas.pop_back();  // Tomar el último elemento
            int b = piezas.back(); 
            piezas.pop_back();  // Tomar el penúltimo elemento

            // Si la suma de las piezas es par, combinamos las piezas
            if ((a + b) % 2 == 0) {
                piezas.push_back((a + b) / 2);  // Añadir la nueva pieza combinada
            } else {
                piezas.push_back(b);  
                piezas.push_back(a);
            }

            if (altura <= 1) break;  // Si la altura es 1, salimos
        }
        
        // Imprimir el resultado
        cout << piezas.size() << " " << piezas.back() << endl;
    }

    return 0;
}
