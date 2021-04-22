/*
* INCLUDE-файл : intSet.h
* 
* Язык программирования: C++
* 
* Назначение: Определение класса "множество целых чисел"
*
* Дата создания : 22/04/2021
*
*/
#ifndef _IntSet_h_
#define _IntSet_h_
#include "BitScale.h"


class IntSet
{
BitScale bitScale;
int ixBegin;
int ixLast;
public:

IntSet( int ixBegin = 0, int ixLast = 255 ) : 
bitScale( ixLast-ixBegin+1 )
{
if( ixBegin < ixLast )
{
this->ixBegin = ixBegin;
this->ixLast = ixLast;
}
else
{
this->ixLast = ixBegin;
this->ixBegin = ixLast;
}
}
IntSet( const IntSet& arg ) : bitScale( arg.bitScale )
{
ixBegin = arg.ixBegin;
ixLast = arg.ixLast;
}
// Проверка принадлежности элемента множеству
bool in( int item )
{
return bitScale.hasBit( item - ixBegin ); 
}
IntSet& operator |=( int item )
{
bitScale.setBit( item - ixBegin );
return *this;
}
IntSet& operator -=( int item )
{
bitScale.clearBit( item - ixBegin );
return *this;
}
IntSet& operator |=( const IntSet& arg )
{
bitScale |= arg.bitScale;
return *this;
}
};
#endif
