// This code has been copied from http://www.hertaville.com/introduction-to-accessing-the-raspberry-pis-gpio-in-c.html
// It's been modified.

#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

#include <string>
using namespace std;
/* GPIO Class
 * Purpose: Each object instantiated from this class will control a GPIO pin
 * The GPIO pin number must be passed to the overloaded class constructor
 */
class GPIOClass
{
public:
    GPIOClass();                  // create a GPIO object that controls GPIO4 (default
    GPIOClass(string x);          // create a GPIO object that controls GPIOx, where x is passed to this constructor
    bool export_gpio();            // exports GPIO
    bool unexport_gpio();          // unexport GPIO
    bool setdir_gpio(string dir);  // Set GPIO Direction
    bool setval_gpio(string val);  // Set GPIO Value (putput pins)
    bool setval_gpiob(bool);
    bool getval_gpio(string& val); // Get GPIO Value (input/ output pins)
    bool getval_gpio(bool& val);
    string get_gpionum();         // return the GPIO number associated with the instance of an object
private:
    string gpionum;               // GPIO number associated with the instance of an object
    bool Success;
};

#endif
