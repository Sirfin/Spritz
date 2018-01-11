#ifndef SPRITZ_H
#define SPRITZ_H
#include <vector>
#include <cstdint>
#include <cstring>
#include <iostream>
#define N 256 //As defined in the paper, the default Value is 256

/*
For more detailed informations regarding the algorithm implemented here please consult the paper :
"Spritz—a spongy RC4-like stream cipher and hash function" by Ronald L. Rivest and Jacob C. N. Schuldt.
*/
class Spritz
{
    //using unsigned char as byte representation as argumented here:
    //https://stackoverflow.com/questions/20024690/is-there-byte-data-type-in-c

public:
    Spritz();
    virtual ~Spritz();
    /*
    Interface function to create an r size hash
    */
    std::vector<unsigned char> Hash(size_t r, std::vector<unsigned char> M) ;
    /*
    Interface function to absorb a value I
    */
    void Absorb(const std::vector<unsigned char> I);
    /*
    Interface function to squeeze out an r size output
    */
    std::vector<unsigned char>  squeeze(size_t r) ;
    /*
    Interface function to reset/init the state
    */
    void InitializeState() ;
protected:

private:
    void Crush() ;
    unsigned char Drip()  ;
    void Update() ;
    unsigned char Output() ;
    void Shuffle() ;
    /*
    Function to cleanly seperate different absorb inputs.
    */
    void AbsorbStop() ;

    /*
    Function that takes a part(higher or lower) of a byte and absorbs it into our sponge function
    */
    void AbsorbNibble(const unsigned char x) ;
    /*
    Function takes a byte and absorbs it into our sponge function
    */
    void AbsorbByte(const unsigned char b) ;
    void Whip(const int r) ;
    /*
    Function that calculates the greatest common denominator of two numbers
    */
    int gcd(int a, int b) ;
    /*
    Function that swaps two values.
    */
    void Swap(unsigned char& a,unsigned char& b);
    //The registers
    int i ;
    int j ;
    int k ;
    int z ;
    int a ;
    int w ;
    unsigned char S[N] ;
    /*
    Calculating the higher part of a byte
    */
    inline unsigned High(unsigned char a)
    {
        return a >> 4 ;
    }
    /*
    Calculating the lower part of a byte
    */
    inline unsigned char Low(unsigned char a)
    {
        return a & 0xf ;
    }
};

#endif // SPRITZ_H
