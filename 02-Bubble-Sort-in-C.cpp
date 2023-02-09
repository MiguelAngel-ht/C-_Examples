//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here
#include <string>

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 80;          //Larger than needed
    char array[SIZE];           //Character array larger than needed
    int sizeIn, sizeDet;        //Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout << "Read in a 1 dimensional array of characters and sort" << endl;
    cout << "Input the array size where size <= 20" << endl;
    cin >> sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout << "Now read the Array" << endl;
    sizeDet = read(array);          //Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array, sizeIn);        //Sort the array
        print(array, sizeIn);       //Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}



int read(char array[]){
    int sizeDet;
    
    cin >> array;
    
    sizeDet = strlen(array);
    return sizeDet;
    
}



void sort(char array[], int sizeIn){
    
    int aux;
    int int_array[sizeIn];
    
    // casting char to int
    for(int i = 0; i < sizeIn; i++){
        int_array[i] = int(array[i]);
    }
    
    
    // Bubble sort 
    for(int i = 0; i < sizeIn-1; i++){
        for(int j = 0; j < sizeIn-i-1; j++){
            
            if(int_array[j] > int_array[j+1]){
                
                aux = int_array[j];
                int_array[j] = int_array[j+1];
                int_array[j+1] = aux;
            }
        }   
    }
    
    
    // casting int to char
    for (int i = 0 ; i < sizeIn; i++){
        array[i] = int_array[i];
    }
    
    
}



void print(const char array[], int sizeIn){
    printf("%s", array);
}







