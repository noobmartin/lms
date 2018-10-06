// This code has been copied from http://www.hertaville.com/introduction-to-accessing-the-raspberry-pis-gpio-in-c.html

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "gpioclass.hpp"

using namespace std;

GPIOClass::GPIOClass(){
    this->gpionum = "4"; //GPIO4 is default
}

GPIOClass::GPIOClass(string gnum){
    this->gpionum = gnum; 
}

bool GPIOClass::export_gpio(){
  ofstream exportgpio("/sys/class/gpio/export"); // Open "export" file.
    
  if(!exportgpio.is_open()){
    cout << " OPERATION FAILED: Unable to export GPIO"<< this->gpionum <<" ."<< endl;
    Success = false;
  }
  else{
    exportgpio << this->gpionum ; //write GPIO number to export
    exportgpio.close();
    
    Success = true;
  }
    
  return Success;
}

bool GPIOClass::unexport_gpio(){
  ofstream unexportgpio("/sys/class/gpio/unexport"); //Open unexport file
  
  if(!unexportgpio.is_open()){
    cout << " OPERATION FAILED: Unable to unexport GPIO"<< this->gpionum <<" ."<< endl;
    Success = false; 
  }
  else{
    unexportgpio << this->gpionum ; //write GPIO number to unexport
    unexportgpio.close();
    Success = true;
  }
  
  return Success;
}

bool GPIOClass::setdir_gpio(string dir){
  string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "/direction";
  ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
    
  if(!setdirgpio.is_open()){
    cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< endl;
    Success = false;
  }
  else{
    setdirgpio << dir; //write direction to direction file
    setdirgpio.close();
    Success = true;
  }
    
  return Success;
}

bool GPIOClass::setval_gpio(bool val){
  if(val){
    Success = setval_gpio("1");
  } 
  else{
    Success = setval_gpio("0");
  }
  
  return Success;
}

bool GPIOClass::setval_gpio(string val){
  string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
  ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
    
  if(!setvalgpio.is_open()){
    cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< endl;
    Success = false; 
  }
  else{
    setvalgpio << val ;//write value to value file
    setvalgpio.close();
    Success = true;
  }

  return Success;
}

bool GPIOClass::getval_gpio(bool& val){
  string vals;
  Success = getval_gpio(vals);
  
  if(vals == "0"){
    val = false;
  }
  else{
    val = true;
  }
  
  return Success;
}

bool GPIOClass::getval_gpio(string& val){
  string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
  ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    
  if(!getvalgpio.is_open()){
    cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< endl;
    Success = false;
  }
  else{
    getvalgpio >> val ;  //read gpio value

    if(val != "0"){
      val = "1";
    }
    else{
      val = "0";
    }

    getvalgpio.close();
    Success = true;
  }
    
  return Success;
}

string GPIOClass::get_gpionum(){
  return this->gpionum;
}