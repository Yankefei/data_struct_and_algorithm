#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cstring>

#define Raw     4
#define Column  5

char letter_array[Raw][Column] =
    {
        {'t', 'h', 'i', 's', 'o'},
        {'w', 'a', 't', 's', 't'},
        {'o', 'a', 'h', 'g', 'b'},
        {'f', 'g', 'd', 't', 'c'},
    };

const char* GetN(char array[][Column], int raw, int column, int max_word_len)
{
    int length = raw + 2;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int r = raw; r >=0 && max_word_len > 0 ; r--, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[r][column];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* GetNE(char array[][Column], int raw, int column, int max_word_len)
{
    int length = std::min(raw + 1, Column - column) + 1;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int r = raw, c = column; r >= 0 && c < Column && max_word_len > 0 ; r--, c++, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[r][c];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* GetE(char array[][Column], int raw, int column, int max_word_len)
{
    int length = Column - column + 1;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int c = column; c < Column && max_word_len > 0 ; c++, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[raw][c];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* GetES(char array[][Column], int raw, int column, int max_word_len)
{
    int length = std::min(Raw - raw, Column - column) + 1;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int r = raw, c = column; r < Raw && c < Column && max_word_len > 0 ; r++, c++, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[r][c];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* GetS(char array[][Column], int raw, int column, int max_word_len)
{
    int length = Raw - raw + 1;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int r = raw; r < Raw && max_word_len > 0 ; r++, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[r][column];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* GetSW(char array[][Column], int raw, int column, int max_word_len)
{
    int length = std::min(Raw - raw, column + 1) + 1;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int r = raw, c = column; r < Raw && c >= 0 && max_word_len > 0 ; r++, c--, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[r][c];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* GetW(char array[][Column], int raw, int column, int max_word_len)
{
    int length = column + 2;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int c = column; c >= 0 && max_word_len > 0 ; c--, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[raw][c];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* GetWN(char array[][Column], int raw, int column, int max_word_len)
{
    int length = std::min(raw, column) + 2;
    char * ptr = new char[length];
    int ptr_i = 0;
    for (int r = raw, c = column; r >= 0 && c >= 0 && max_word_len > 0 ; r--, c--, ptr_i++, max_word_len --)
    {
        ptr[ptr_i] = array[r][c];
    }
    ptr[ptr_i] = '\0';
    return ptr;
}

const char* (*direction_array[8])(char array[][Column], int raw, int column, int max_word_len) = {
    GetN,
    GetNE,
    GetE,
    GetES,
    GetS,
    GetSW,
    GetW,
    GetWN
};

const char* GetWord(char array[][Column], int raw, int column, int direction_array_index, int max_word_len)
{
    assert(direction_array_index >= 0 && direction_array_index <= 8);
    return direction_array[direction_array_index](array, raw, column, max_word_len);
}

void PrintWordInfo(const char* word, int raw, int column, int direct)
{
    int diff_word_len = strlen(word) - 1;
    int raw_end = raw;
    int column_end = column;
    switch(direct)
    {
        case 0:
            raw_end = raw - diff_word_len;
            break;
        case 1:
            raw_end = raw - diff_word_len;
            column_end = column + diff_word_len;
            break;
        case 2:
            column_end = column + diff_word_len;
            break;
        case 3:
            raw_end = raw + diff_word_len;
            column_end = column + diff_word_len;
            break;
        case 4:
            raw_end = raw + diff_word_len;
            break;
        case 5:
            raw_end = raw + diff_word_len;
            column_end = column - diff_word_len;
            break;
        case 6:
            column_end = column - diff_word_len;
            break;
        case 7:
            raw_end = raw - diff_word_len;
            column_end = column - diff_word_len;
            break;
        default:
            assert(false);
            break;
    }
    std::cout << word << ", from (" << raw + 1 << ", " << column + 1 << "), to(" << raw_end + 1 << ", "<< column_end + 1 << ")";
}

void CheckProbablyWord(char array[][Column], int raw, int column, const char* word[], int word_num, int max_len)
{
    for (int i = 0; i < 8; i ++)
    {
        const char* get_word = GetWord(array, raw, column, i, max_len);
        
        for (int j = 0; j < word_num; j++)
        {
            if (0 ==strncmp(get_word, word[j], strlen(word[j])))
            {
                std::cout <<"Find Word: ";
                PrintWordInfo(word[j], raw, column, i);
                std::cout << std::endl; 
            }
        }

        delete[] get_word;
    }
}

void FindWord(char array[][Column], const char* word[], int word_num)
{
    int max_word_len = 0;
    for (int i = 0; i < word_num; i++)
    {
        max_word_len = std::max(max_word_len, (int)strlen(word[i]));
    }

    // (行，列，方向，字符数)
    for (int i = 0; i < Raw; i++)
    {
        for (int j = 0; j < Column; j ++)
        {
            CheckProbablyWord(array, i, j, word, word_num, max_word_len);
        }
    }
}

