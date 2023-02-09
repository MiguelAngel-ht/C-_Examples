//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80;          //Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX], int &);           //Outputs row and columns detected from input
void sort(char [][COLMAX], int, int);         //Sort by row
void print(const char [][COLMAX], int, int);  //Print the sorted 2-D array



//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;               //Only 20 required
    char array[ROW][COLMAX];        //Bigger than necessary 
    int colIn, colDet, rowIn, rowDet;  //Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array, rowDet);

    // Compare the size input vs. size detected and sort if same
    // Else output different size
    if(rowDet == rowIn && colDet == colIn){
        sort(array, rowIn, colIn);
        cout << "The Sorted Array" << endl;
        print(array, rowIn, colIn);
    }else{
        if(rowDet != rowIn)
        cout << (rowDet < rowIn ? "Row Input size less than specified.":
            "Row Input size greater than specified.") << endl;
        if(colDet != colIn)
        cout << (colDet < colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.") << endl;
    }
    
    //Exit
    return 0;
}




int read(char array[][COLMAX], int &rowDet){
    int colDet = rowDet;
    
    for(int i=0; i<rowDet; i++){
        cin >> array[i];
    }
    
    return colDet;
}



void sort(char array[][COLMAX], int rowIn, int colIn){
    
    int int_array[rowIn][colIn];
    
    // casting char to int
    for(int i=0; i<rowIn; i++){
        for(int j=0; j<colIn; j++){
            int_array[i][j] = int(array[i][j]);
        }
    }
    
    for (int ia=0; ia < rowIn; ia++)
      for (int ja=0; ja < rowIn; ja++)
        for (int i=0; i < colIn; i++)
          
            if(int_array[ia][i] < int_array[ja][i])
            {
                int aux = int_array[ia][i];
                int_array[ia][i] = int_array[ja][i];
                int_array[ja][i] = aux;
            }
            
            
    // casting int to char
    for(int i=0; i<rowIn; i++){
        for(int j=0; j<colIn; j++){
            array[i][j] = int_array[i][j];
        }
    }

}




void print(const char array[][COLMAX], int rowIn, int colIn){
    for(int i=0; i<rowIn; i++){
        cout << array[i] << endl;
    }
    
}






