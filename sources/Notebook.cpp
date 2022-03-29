#include "Notebook.hpp"
using namespace std;
using namespace ariel;
#include "string.h"
#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
using ariel::Direction;
#include <cctype>
const int MEA_DA = 100;
const int abcone = 32;
const int abct = 126;
void Notebook ::write(int page, int row, int col, Direction h, string abc)
{

   int abcsize = (int)abc.length();
   if (page < 0 || row < 0 || col < 0 || col >= MEA_DA)
   {
      throw runtime_error("negative");
   }
   if ("\n" == abc)
   {
      throw runtime_error("size");
   }

   if (h == Direction::Horizontal)
   { // write Horizontal

      if (((long)col + abcsize) > MEA_DA)
      {

         throw runtime_error("another letter1");
      }

      int j = 0;
      for (int i = col; i < ((int)abc.length() + (long)col); i++)
      {
         /// cout <<this->notebook[page][row][i];

         if (this->notebook[page][row].count(i) != 0)
         {
            if (this->notebook[page][row][i] == '_')
            {
               break;
            }
            throw runtime_error("another letter2");
         }
         if (abc.at((unsigned long)j) < abcone || abc.at((unsigned long)j) > abct || abc.at((unsigned long)j) == '~')
         {
            throw runtime_error("not abc");
         }

         this->notebook.at(page).at(row).insert(std::make_pair(i, abc.at((unsigned long)j)));
         j++;
      };
   }

   if (h == Direction::Vertical)
   { // write vertical
      int j = 0;

      for (int i = row; i < ((int)abc.length() + (long)row); i++)
      {

         if (this->notebook[page][i].count(col) != 0)
         {

            if (this->notebook[page][i][col] == '_')
            {

               break;
            }
            // cout << abcsize;
            throw runtime_error("another letter3");
         }

         if (abc.at((unsigned long)j) < abcone || abc.at((unsigned long)j) > abct || abc.at((unsigned long)j) == '~')
         {
            throw runtime_error("not abc");
         }
         this->notebook.at(page).at(i).insert(std::make_pair(col, abc.at((unsigned long)j)));
         j++;
      };
   }
}

string Notebook ::read(int page, int row, int col, Direction h, int lenght)
{

   if (page < 0 || row < 0 || col < 0 || lenght < 0 || col >= MEA_DA)
   {
      throw runtime_error("negative");
   }
   string s;
   if ((col + lenght) > MEA_DA && h == Direction::Horizontal)
   {
      throw runtime_error("negative");
   }
   if ((col + lenght) <= MEA_DA)
   {

      if (h == Direction::Horizontal)
      { // write Horizontal

         for (int i = col; i < (col + lenght); i++)
         {

            if (this->notebook[page][row].count(i) == 0)
            {

               s += '_';
            }
            else
            {

               s += this->notebook.at(page).at(row).at(i);
            }
         };
      }
   }
   if (h == Direction::Vertical)
   { // write vertical
      // write Horizontal

      for (int i = row; i < (row + lenght); i++)
      {

         if (this->notebook[page][i].count(col) == 0)
         {

            s += '_';
         }
         else
         {
            // cout <<"Suka";
            s += this->notebook.at(page).at(i).at(col);
         }
      };
   }
   return s;
}

void Notebook ::erase(int page, int row, int col, Direction h, int lenght)
{

   if (page < 0 || row < 0 || col < 0 || lenght < 0 || col >= MEA_DA)
   {
      throw runtime_error("negative");
   }
   if ((col + lenght) > MEA_DA && h == Direction::Horizontal)
   {
      throw runtime_error("negative");
   }
   if ((col + lenght) <= MEA_DA)
   {

      if (h == Direction::Horizontal)
      { // write Horizontal

         int j = 0;
         for (int i = col; i < (col + lenght); i++)
         {

            this->notebook[page][row][i] = '~';
            j++;
         };
      }
   }
   if (h == Direction::Vertical)
   { // write vertical j
      int j = 0;
      for (int i = row; i <= (col + lenght); i++)
      {

         this->notebook[page][i][col] = '~';
         j++;
      };
   }
}

void Notebook ::show(int page)
{
   if (page < 0)
   {
      throw runtime_error("negative");
   }
   for(int i=100;i<200;i++){
      cout << i <<":";
      for(int j=0;j<100;j++){
       
       cout << this->notebook[page][i][j];
      }
     cout <<endl;
   }
   
}