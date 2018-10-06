#include "sol.hpp"

int main(){
  Sol SOL;
  SOL.Initialize();
  
  do{
    SOL.Execute();
  }while(1);
}