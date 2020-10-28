#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
 ifstream file1, file2, file3; 
 ofstream fileOut;
 char* endptr; 
 long liczba, max;
 string liczba1, liczba2;
 file1.open("dane_systemy1.txt");
 file2.open("dane_systemy2.txt"); 
 file3.open("dane_systemy3.txt");
 fileOut.open("wyjscie.txt");
 bool pierwszy = true;  
 int recordDay = 0;
 
 if(file2.good())
     while(!file2.eof())
     {
               file2>>liczba1 >> liczba2;
               liczba =  strtol(liczba2.c_str(), &endptr, 4);
        
               if(pierwszy)
               {
                            max = liczba;
                            pierwszy = false;
               }
               else
                  if(liczba > max)
                       max = liczba;
                       recordDay = recordDay + 1;
     }
     
     
     

if(file1.good()) 
     while(!file1.eof())      
     {
               file1>>liczba1 >> liczba2;
               liczba =  strtol(liczba2.c_str(), &endptr, 2);
        
               if(pierwszy)
               {
                            max = liczba;
                            pierwszy = false;
               }
               else
                  if(liczba > max)
                       max = liczba;
                       recordDay = recordDay + 1;
     }
     
     
     
if(file3.good())
     while(!file3.eof())  
     {
               file3>>liczba1 >> liczba2;
               liczba =  strtol(liczba2.c_str(), &endptr, 8);
               if(pierwszy)
               {
                            max = liczba;
                            pierwszy = false;
               }
               else
                  if(liczba > max) 
                       max = liczba; 
                       recordDay = recordDay + 1;
     }
     
     


 fileOut<< "58.3: " << max <<endl; 
 fileOut<< "Liczba dni rekordowych wynosi: " << recordDay << endl;
 file1.close();
 fileOut.close();
 return 0;
}
