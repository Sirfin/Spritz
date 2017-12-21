#include <iostream>
#include <vector>
#include "../include/Spritz.h"
using namespace std;
void Test() ;
int main()
{
    Test() ;
}

void Test(){
pair<string,int[8]> BasicOutput[3] ;
BasicOutput[0].first = "ABC" ;
BasicOutput[0].second[0] = 119 ; //77 9a 8e 01 f9 e9 cb c0
BasicOutput[0].second[1] = 154 ;
BasicOutput[0].second[2] = 142 ;
BasicOutput[0].second[3] = 1 ;
BasicOutput[0].second[4] = 249 ;
BasicOutput[0].second[5] = 233 ;
BasicOutput[0].second[6] = 203 ;
BasicOutput[0].second[7] = 192 ;
BasicOutput[1].first = "spam" ;
BasicOutput[1].second[0] = 240 ; //f0 60 9a 1d f1 43 ce bf
BasicOutput[1].second[1] = 96 ;
BasicOutput[1].second[2] = 154 ;
BasicOutput[1].second[3] = 29 ;
BasicOutput[1].second[4] = 241 ;
BasicOutput[1].second[5] = 67 ;
BasicOutput[1].second[6] = 206 ;
BasicOutput[1].second[7] = 191 ;
BasicOutput[2].first = "arcfour" ;
BasicOutput[2].second[0] = 26 ; //1a fa 8b 5e e3 37 db c7
BasicOutput[2].second[1] = 250 ;
BasicOutput[2].second[2] = 139 ;
BasicOutput[2].second[3] = 94 ;
BasicOutput[2].second[4] = 227 ;
BasicOutput[2].second[5] = 55 ;
BasicOutput[2].second[6] = 219 ;
BasicOutput[2].second[7] = 199 ;
pair<string,int[8]> HashOutput[3] ;
HashOutput[0].first = "ABC" ;
HashOutput[0].second[0] = 2 ; //02 8f a2 b4 8b 93 4a 18
HashOutput[0].second[1] = 143 ;
HashOutput[0].second[2] = 162;
HashOutput[0].second[3] = 180 ;
HashOutput[0].second[4] = 139 ;
HashOutput[0].second[5] = 147 ;
HashOutput[0].second[6] = 74 ;
HashOutput[0].second[7] = 24 ;
HashOutput[1].first = "spam" ;
HashOutput[1].second[0] = 172 ; //ac bb a0 81 3f 30 0d 3a
HashOutput[1].second[1] = 187 ;
HashOutput[1].second[2] = 160;
HashOutput[1].second[3] = 129 ;
HashOutput[1].second[4] = 63 ;
HashOutput[1].second[5] = 48 ;
HashOutput[1].second[6] = 13 ;
HashOutput[1].second[7] = 58 ;
HashOutput[2].first = "arcfour" ;
HashOutput[2].second[0] = 255 ; //ff 8c f2 68 09 4c 87 b9
HashOutput[2].second[1] = 140 ;
HashOutput[2].second[2] = 242;
HashOutput[2].second[3] = 104 ;
HashOutput[2].second[4] = 9 ;
HashOutput[2].second[5] = 76 ;
HashOutput[2].second[6] = 135 ;
HashOutput[2].second[7] = 185 ;

//Testing the Basic Output with the test vectors from the paper
for (int i = 0 ; i < 3 ; i++){
    Spritz spritz ;
    std::vector<unsigned char> data(BasicOutput[i].first.begin(), BasicOutput[i].first.end());
    spritz.Absorb(data);
    data = spritz.squeeze(32) ;
    cout << "Testing Basic Vector " << i << endl ;
     bool test = true ;
    for (int j = 0 ; j < 8 ; j++){

        if (data[j] != BasicOutput[i].second[j]){
            cout << std::dec<< "Fehler bei : output=" << (int)data[j] << " test=" << (int)BasicOutput[i].second[j] << endl ;
            test =  false ;
        }
    }
    test?cout<< "Test Basic Vector " << i << ": passed"<<endl:cout<< "Test Basic Vector " << i << ": failed"<<endl ;
}

//Testing the Hash Output with the test vectors from the paper
for (int i = 0 ; i < 3 ; i++){
    Spritz spritz ;
    std::vector<unsigned char> data(HashOutput[i].first.begin(), HashOutput[i].first.end());
    data = spritz.Hash(32,data) ;
    cout << "Testing Hash Vector " << i << endl ;
     bool test = true ;
    for (int j = 0 ; j < 8 ; j++){
        if (data[j] != HashOutput[i].second[j]){
            cout << std::dec<< "Fehler bei : output=" << (int)data[j] << " test=" << (int)BasicOutput[i].second[j] << endl ;
            test =  false ;
        }
    }
    test?cout<< "Test Hash Vektor " << i << ": passed"<<endl:cout<< "Test Hash Vektor " << i << ": failed"<<endl ;
}


}
