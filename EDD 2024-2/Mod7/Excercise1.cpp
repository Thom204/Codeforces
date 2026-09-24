#include "BST.cpp"
#include<iostream>
#include<sstream>
#include<vector>

void splitStream_ToVector(const std::string& input, std::vector<int>& arr, char delim) {
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delim)) {
        arr.push_back(std::stoi(token));
    }
}

int main(){
    BST *tree;
    int cases;
    std::string input;

    std::cin>>cases;
    for(int _=0; _<cases; _++){
        std::vector<int> v= {};
        std::getline(std::cin>>std::ws, input);
        splitStream_ToVector(input, v, ' ');
        v.pop_back();

        tree= new BST();
        for(int i: v){
            tree->insert(i);
        }for(int j: tree->pre_Order()){
            std::cout<<j;
        }
        std::cout<<std::endl;
        v = {};
    }
}