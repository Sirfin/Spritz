#ifndef SPRITZ_H
#define SPRITZ_H
#include <vector>
#include <cstdint>
#include <cstring>
#include <iostream>
#define N 256
//As defined in the paper, the default Value is 256
class Spritz
{
    public:
        Spritz();
        virtual ~Spritz();
        std::vector<unsigned char> Hash(size_t r , std::vector<unsigned char> M) ;
        void Absorb(const std::vector<unsigned char> I);
        std::vector<unsigned char>  squeeze(int r) ;
              void InitializeState() ;
    protected:

    private:

        void Crush() ;
        unsigned char Drip()  ;
        void Update() ;
        unsigned char Output() ;
        void Shuffle() ;
        void AbsorbStop() ;
        void AbsorbNibble(const unsigned char x) ;
        void AbsorbByte(const unsigned char b) ;
        //we do not use std::string cause we want just the byte representation otherwise
                               //it would not be possible to input an Integer.
        void Whip(const int r) ;
        int gcd(int a, int b) ;

        void Swap(unsigned char* a,unsigned char* b);
        int i ; //using unsigned char as byte representation as argumented here:
        int j ; //https://stackoverflow.com/questions/20024690/is-there-byte-data-type-in-c
        int k ;
        int z ;
        int a ;
        int w ;
        unsigned char S[N] ;

        inline unsigned High(unsigned char a)
        {
            return a >> 4 ;
        }
        inline unsigned char Low(unsigned char a)
        {
            return a & 0xf ;
        }
};

#endif // SPRITZ_H
