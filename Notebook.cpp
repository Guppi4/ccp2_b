#include "Notebook.hpp"
using namespace std;
using namespace ariel;
#include "string.h"
#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
using ariel::Direction;


void Notebook :: write( int page,int row,int col,Direction h,string abc) 
{
  if(((long)col+int(abc.size()))<=100){
     
     if(h==Direction::Horizontal){//write Horizontal
      
         int j=0;
         for(int i=col;i<((int)abc.size()+(long)col);i++){
            
            if(this->notebook[page][row].count(i)!=0){
                
               throw runtime_error("another letter");
            }
             
            this->notebook.at(page).at(row).insert(std::make_pair(i,abc.at( ( unsigned long )j)));
            j++;
         };
     }
     
  
  }
  if(h==Direction::Vertical){//write vertical
         int j=0;
         for(int i=row;i<=((int)abc.size()+(long)row);i++){
            if(this->notebook[page][i].count(col)!=0){
               throw runtime_error("another letter");
            }
            this->notebook.at(page).at(i).insert(std::make_pair(col,abc.at( ( unsigned long )j)));
            j++;
         };
     }
     
     

}

string Notebook :: read(int page,int row,int col,Direction h,int lenght) 
{
   
   string s="";
  if((col+lenght)<=100){
     
     if(h==Direction::Horizontal){//write Horizontal
      
         
         for(int i=col;i<(col+lenght);i++){
            
            if(this->notebook[page][row].count(i)==0){
                
               s+='_';
            }
            else{ 
              
              s+=this->notebook.at(page).at(row).at(i);
            
            }
         };
     }
     
  
  }
  if(h==Direction::Vertical){//write vertical
        //write Horizontal
      
         
         for(int i=row;i<(row+lenght);i++){
            
            if(this->notebook[page][i].count(col)==0){
                
               s+='_';
            }
            else{ 
              //cout <<"Suka";
              s+=this->notebook.at(page).at(i).at(col);
            
            }
         };
     
     }
  return s;
}

 void Notebook :: erase(int page,int row,int col,Direction h,int lenght) 
{
     if((col+lenght)<=100){
     
     if(h==Direction::Horizontal){//write Horizontal
      
         int j=0;
         for(int i=col;i<(col+lenght);i++){
            
           
             
            this->notebook[page][row][i]='~';
            j++;
         };
     }
     
  
  }
  if(h==Direction::Vertical){//write vertical
         int j=0;
         for(int i=row;i<=(col+lenght);i++){
            
            this->notebook[page][i][col]='~';
            j++;
         };
     }
     
}

 void Notebook :: show(int page) 
{
 
}