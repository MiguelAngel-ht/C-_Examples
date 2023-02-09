/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */
 
//System Libraries Here
#include <iostream>         //cin,cout,endl
#include <cstring>          //strlen()
using namespace std;

//User Libraries Here
#include <string>           // c_str(), to_string()

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [], unsigned short &);      //Output true,unsigned or false
int convertToInt(const char []);
bool  reverse(unsigned short,signed short &);       //Output true,short or false
short subtrct(signed short,int);


//Program Execution Begins Here
int main()
{
    //Declare all Variables Here
    const int SIZE = 80;          //More than enough
    char  digits[SIZE];         //Character digits or not
    unsigned short unShort;     //Unsigned short
    short snShort;              //Signed short
    
   //Input or initialize values Here
    cout << "Reverse a number and subtract if possible." << endl;
    cout << "Input a number in the range of an unsigned short" << endl;
    cin >> digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout << "No Conversion Possible" << endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout << "No Conversion Possible" << endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort = subtrct(snShort,999);
    
    //Output the result
    if(snShort){
        cout << "The result is " << snShort << endl;
    }
    else{
        cout << "No Conversion Possible" << endl;
        return 0;
    }
    
    //Exit
    return 0;
    
}

//Output true,unsigned or false
bool  inRange(const char digits[], unsigned short &unShort){
    if(strlen(digits) > 5){
        return false;
    }
    for(int i = 0; i < 5; i++){
        if (isalpha(digits[i])){
            return false;
        }
    }
    unShort = convertToInt(digits);
    return true;
};

//Output true,short or false
bool  reverse(unsigned short unShort,signed short &snShort){
    
    int arr[5];
    const char* arrrep;
    int num;
    int space = 5 - to_string(unShort).length();     // how many ceros we're going to put in the left side
    
    // first 0's in the left side          [0,0,...]
    for(int i = 0; i < space; i++){
        arr[i] = 0;
    }
    // append the integer in the array with 0's [0,0,1,2,8]
    for (int i = 4; i > space-1; i--){
        num = unShort % 10;
        unShort /= 10;
        arr[i] = num;
     }
    
    // changing char array to string  "00128" and inverting "82100"
    string s;
    for(int j = 5; j > 0; j--)
            s += to_string(arr[j-1]);
            
    // changing string to const char  
    arrrep = s.c_str();

    // const char to integer
    snShort = convertToInt(arrrep);
    
    return true;
}



int convertToInt(const char a[1000]){
    int i = 0;
    unsigned short num = 0;
    while (a[i] != 0)
    {
        num =  (a[i] - '0')  + (num * 10);
        i++;
    }
    return num;
};

short subtrct(signed short snShort, int sub){
    
    snShort -= sub;
    
    // if subtract is negative return false
    if(snShort < 0){
        return false;
    }
    return snShort;
}