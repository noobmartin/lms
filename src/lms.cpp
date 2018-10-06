#include "sol.hpp"

int main(){
  Sol SOL;
  SOL.Initialize();
  
  do{
    SOL.Execute();
    SOL.Serviceable();
  }while(1);
}