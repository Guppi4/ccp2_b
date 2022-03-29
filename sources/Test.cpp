/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Kirill Perevalov>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "Notebook.hpp"
#include "doctest.h"
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;
using namespace ariel;
using ariel::Direction;
#include <bits/stdc++.h>
 const std::array<int,30>arr={217,209,51,219,210,53,2,3,58,213,208,51,250,10,11,260,11,23,270,14,85,333,57,66,350,43,7,450,33,56};
 const int tent=28;
/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

TEST_CASE("Good input")
{
    ariel::Notebook notebook;
    
    //1
    
    for(size_t i=0;i<=tent;i+=3){
        int a=arr.at(i);
        int b=arr.at(i+1);
        int c=arr.at(i+2);
        notebook.write(a,b, c,Direction::Horizontal,"abcd");
        CHECK(notebook.read(a,b, c,Direction::Horizontal, 4)=="abcd");
        //1cout <<a <<" " <<b << " "<<c << "  ";
       
    }

   
    
    
    
                                                
                                                 
                                                           
 

}
TEST_CASE("Bad input")
{
    ariel::Notebook notebook1;
    //1
    CHECK_THROWS(notebook1.read(-7,0,0, Direction::Horizontal, 5));
    //2
    CHECK_THROWS(notebook1.read(-111,0,0, Direction::Horizontal, 5));
    //3
    CHECK_THROWS(notebook1.read(-111,0,0, Direction::Horizontal, 5));
    //4
    CHECK_THROWS(notebook1.read(-11,0,0, Direction::Horizontal, 5));
    //5
    CHECK_THROWS(notebook1.read(-111,0,0, Direction::Horizontal, 5));
    //6
    CHECK_THROWS(notebook1.read(-113,0,0, Direction::Horizontal, 5));
    //7
    CHECK_THROWS(notebook1.read(1-14,0,0, Direction::Horizontal, 5));
    //8
    CHECK_THROWS(notebook1.read(-114,0,0, Direction::Horizontal, 5));
    //9
    CHECK_THROWS(notebook1.read(-115,0,0, Direction::Horizontal, 5));
    //10
    CHECK_THROWS(notebook1.read(-117,0,0, Direction::Horizontal, 5));
    
 
}