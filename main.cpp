/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here
#include <string>

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;                   //No more than 80 rows
    int array[ROW][COLMAX];             //Really, just an 80x2 array, even vs. odd
    vector<int> even(0), odd(0);        //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even, odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even, odd, 10);             //Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even, odd, array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array, even.size(), odd.size(), 10);            //Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    int lim;
    char input[100];
    int i = 0;

    cout << "Input the number of integers to input." << endl;
    cin >> lim;
    
    cout << "Input each number." << endl;

    while(i < lim){
        cin >> input[i];
        i++;
    }
    
    for(int i=0; i<lim; i++){
        int value = int(input[i]) - 48;
        
        if(value % 2 == 0){
            even.push_back(value);
        }
        else{
            odd.push_back(value);
        }
    }
}


void prntVec(vector<int> even, vector<int> odd, int n){
    int j = 0;
    int max, min;
    string label;
    cout << setw(n) << "Vector" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    
    if(even.size() >= odd.size()){
        max = even.size();
        min = odd.size();
        label = "odd";
    }
    else{
        max = odd.size();
        min = even.size();
        label = "even";
    }
    
    while(j < max){
        if(j < min){
            cout << setw(2*n) << even.at(j) << setw(n) << odd.at(j) << endl;            
        }
        else{
            if(label == "odd"){
                cout << setw(2*n) << even.at(j) << setw(2*n) << endl;    
            }
            else{
                cout << setw(4*n) << odd.at(j) << endl;    
            }
        
        }

        j++;
    }
    
    
}




void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    int i = 0;
    while(i < even.size()){
        array[i][0] = even.at(i);
        i ++;
    }
    
    i = 0;
    while(i < odd.size()){
        array[i][1] = odd.at(i);
        i++;
    }
    
}


void prntAry(const int array[][COLMAX], int even_size, int odd_size, int n){
    int j = 0;
    int max, min;
    string label;
    cout << setw(n) << "Array" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    
    if(even_size >= odd_size){
        max = even_size;
        min = odd_size;
        label = "odd";
    }
    else{
        max = odd_size;
        min = even_size;
        label = "even";
    }
    
    while(j < max){
        if(j < min){
            cout << setw(2*n) << array[j][0] << setw(n) << array[j][1] << endl;            
        }
        else{
            if(label == "odd"){
                cout << setw(2*n) << array[j][0] << setw(2*n) << endl;    
            }
            else{
                cout << setw(4*n) << array[j][1] << endl;    
            }
        
        }

        j++;
    }
    

}







