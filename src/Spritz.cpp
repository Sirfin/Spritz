#include "Spritz.h"

Spritz::Spritz()
{
    this->InitializeState() ;
}

Spritz::~Spritz()
{
    //dtor
}

void Spritz::Swap(unsigned char* a, unsigned char* b)
{
    unsigned char temp = *a ;
    *a = *b ;
    *b = temp ;
}


void Spritz::InitializeState()
{
i = j = k = z = a = 0 ;
w = 1 ;

    for (int v = 0 ; v < N ; v++){
        S[v] = v ;
    }

}

void Spritz::Crush()
{

 for (int v = 0 ; v < (N/2); v++){
    if (S[v] > S[N-1-v])
        Swap(&S[v],&S[N-1-v]) ;
 }

}

unsigned char Spritz::Drip()
{
if (a > 0){
    Shuffle() ;
}
Update() ;
return Output() ;
}

void Spritz::Update()
{
  i = (i + w) % N;
    j = (k + S[(j + S[i]) % N]) % N;
    k = (k + i + S[j]) %N;
Swap(&S[i], &S[j]) ;
}

unsigned char Spritz::Output()
{
    z = S[(j + S[(i + S[(z + k) %N]) %N]) %N];
return z ;
}

void Spritz::Shuffle()
{
Whip(2*N) ;
Crush() ;
Whip(2*N) ;
Crush() ;
Whip(2*N) ;
a = 0 ;

}

void Spritz::AbsorbStop()
{
    if (a == N/2){
        Shuffle() ;
    }
     a = (a + 1)%N ;
}

void Spritz::AbsorbNibble(const unsigned char x)
{
if (a == N/2){
    Shuffle() ;
}
Swap(&S[a], &S[N/2 + x ]) ;
a = (a +1) %N;
}

void Spritz::AbsorbByte(const unsigned char b)
{
AbsorbNibble(Low(b)) ;
AbsorbNibble(High(b)) ;
}

void Spritz::Absorb(const std::vector<unsigned char> I)
{
for (int i = 0 ; i< I.size() ; i++){
    AbsorbByte(I[i]) ;
}
}

void Spritz::Whip(const int r)
{
for (int v = 0 ; v < r ;v++){
    Update() ;
}
w = (w+2)&0xff;
}

std::vector<unsigned char> Spritz::squeeze(int r)
{
if  (a > 0 ){
    Shuffle() ;
}
    std::vector<unsigned char> P;
    for (int v = 0  ; v < r ;v++ ){
    P.push_back(Drip()) ;
    }
    return P ;
}
std::vector<unsigned char> Spritz::Encrypt(std::vector<unsigned char>K, std::vector<unsigned char>M)
{
    this->InitializeState() ;
    this->Absorb(K) ;
    std::vector<unsigned char> C = squeeze(M.size()-1) ;
    C.insert(C.begin(),M.begin(),M.end()); //C=M+Squeeze()
    return C ;
}

/*std::vector<unsigned char> Spritz::Decrypt(std::vector<unsigned char>K, std::vector<unsigned char>C )
{
    this->InitializeState() ;
    this->Absorb(K) ;
    std::vector<unsigned char> M = squeeze(M.size()-1) ;
    return M ;
}*/
std::vector<unsigned char> Spritz::Hash(size_t r, std::vector<unsigned char>M)
{
    this->InitializeState() ;
    this->Absorb(M) ;
    this->AbsorbStop() ;
    this->AbsorbByte(r) ;
    return squeeze(r) ;
}


