/*
* Файл : BitScale.cpp
* 
* Язык программирования: C++ 
* 
* Назначение: Реализация методов класса BitScale
*
*/

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
#include <memory.h>
#include "BitScale.h"

const int BitScale::WordBitSize = 8*sizeof( BitScale::Word );
BitScale::BitScale( int numBits )
{
this->numBits = numBits;
numWords = (numBits+WordBitSize-1) / WordBitSize;
words = new Word[ numWords ];
memset( words, 0, numWords*sizeof(Word) );
}
BitScale::BitScale( const BitScale& arg )
{
numBits = arg.numBits;
words = new Word[ numWords = arg.numWords ];
memcpy( words, arg.words, numWords*sizeof(Word) );
}
BitScale::~BitScale()
{
delete [] words;
}
void BitScale::Print()
{
char oldFill = cout.fill( '0' );
for( int i=numWords-1; i>=0; i-- )
{
cout << hex << setw( sizeof(Word)*2 );
cout << words[i] << " ";
}
 cout << dec << setfill( oldFill ) << endl;
}
bool BitScale::hasBit( int ixBit )
{
if( ixBit < 0 || ixBit >= numBits ) return false;
return ( words[ ixBit / WordBitSize ] & 
( 1 << ixBit % WordBitSize ) ) != 0;
}
BitScale& BitScale::setBit( int ixBit )
{
if( ixBit < 0 || ixBit >= numBits )
throw out_of_range( "Cannot set the bit that "
"is out of bit scale range" );
words[ ixBit / WordBitSize ] |= ( 1 << ixBit % WordBitSize );
return *this;
}
BitScale& BitScale::clearBit( int ixBit )
{
if( ixBit < 0 || ixBit >= numBits )
throw out_of_range( "Cannot set the bit that "
"is out of bit scale range" );
words[ ixBit / WordBitSize ] &= ~( 1 << ixBit % WordBitSize 
);
return *this;
}
BitScale& BitScale::inverse()
{
for( int i=numWords-1; i>=0; i-- )
{
words[ i ] = ~words[ i ];
}
return *this;
}
BitScale& BitScale::operator |=( const BitScale& arg )
{
if( numBits < arg.numBits )
throw out_of_range( "Incomparable bit scales" );
for( int i=arg.numWords-1; i>=0; i-- )
{
words[ i ] |= arg.words[ i ];
}
return *this;
}
BitScale& BitScale::operator &=( const BitScale& arg )
{
for( int i=numWords-1; i>=0; i-- )
{
words[ i ] &= arg.words[ i ];
}
return *this;
}
BitScale& BitScale::operator -=( const BitScale& arg )
{
for( int i=numWords-1; i>=0; i-- )
{
words[ i ] &= ~arg.words[ i ];
}
return *this;
}
