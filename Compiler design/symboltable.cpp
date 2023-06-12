#ifndef _SYMBOLTABLE_
#define _SYMBOLTABLE_

#define MAX 24576

#include <iostream>
#include <string>
using namespace std;

class Entry
{
        string key;
        int address;
    public:
        Entry(string key, int address);
        void setAddr(int addr)
        {
            this->address = addr;
        }
        void print();
        friend class SymbolTable; //This means Symbol Table class can access all private members of Entry class
};


class SymbolTable
{
        Entry* entryHead[MAX];
    public:
        SymbolTable();
        void addEntry(string& key, int address);
        bool contains(string key);
        int getAddress(string key);
        bool setAddress(string key, int newAddress);
        void display();
};

#endif //_SYMBOLTABLE_