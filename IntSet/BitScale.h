/*
* INCLUDE-файл : BitScale.h
* 
* Язык программирования: C++
* 
* Назначение: Определение класса "шкала битов"
*
*/
#ifndef _BitScale_h_
#define _BitScale_h_

class BitScale
{
protected:
// Базовый тип "слово шкалы битов"
typedef unsigned short Word;
// Размер слова шкалы битов (в битах)
static const int WordBitSize;
Word *words; // Массив слов

int numWords; // Число слов
int numBits; // Число битов
public:
// Конструкторы
BitScale( int numBits = 256 );
BitScale( const BitScale& );
~BitScale();
bool hasBit( int ixBit ); // Проверка принадлежности
BitScale& setBit( int ixBit ); // Установка бита
BitScale& clearBit( int ixBit ); // Очистка бита
BitScale& inverse(); // Операция инвертирования
// Операция занесения элемента 
// (то же , что установка бита)
BitScale& operator |=( int ixBit )
{
return setBit( ixBit );
}
// Операция удаления элемента 
// (то же , что очистка бита)
BitScale& operator -=( int ixBit )
{
return clearBit( ixBit );
}
// Операции над множествами
BitScale& operator |=( const BitScale& arg ); // Объединение
BitScale& operator &=( const BitScale& arg ); // Пересечение
BitScale& operator -=( const BitScale& arg ); // Разность
void Print(); // Печать содержимого шкалы битов
};
#endif
