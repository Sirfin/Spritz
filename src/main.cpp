#include <iostream>
#include <vector>
#include "Spritz.h"
using namespace std;

int main()
{
    string str = "ABC" ;
    std::vector<unsigned char> data(str.begin(), str.end());
    Spritz spritz ;
    data = spritz.Hash(32,data);
    cout << data.size() << endl ;

    for (int i = 0 ; i < 5;i++){
    cout << std::hex<<(int)data[i] << endl;
    }
    return 0;
}
