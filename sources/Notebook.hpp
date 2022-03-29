#include "string.h"
#include <iostream>
#include "Direction.hpp"
#include <unordered_map>
using namespace std;
using ariel::Direction;
namespace ariel
{
    class Notebook
    {
    
        std::unordered_map<int, unordered_map<int, unordered_map<int,char>>> notebook;
        
    public:
       
        void write( int page,int row,int col,Direction h,string abc);
        string read(int page,int row,int col,Direction h,int lenght);
        void erase(int page,int row,int col,Direction h,int lenght);
        void show(int page);
        
    };//fgut
}