#include <iostream>
using namespace std;
 
// Function to print the Pascal's Triangle
void print_pascal(int row_num){
 
    // Loop to print each row
    for(int n = 1; n <= row_num; n++){
 
        // Loop to print spaces for triangular display
        for(int r = 1; r < row_num-n+1; r++)
            cout<<"  ";
 
        // Loop to print values using the Combinations formula
        int val = 1;
        for(int r = 1; r <= n; r++){
            cout<<val<<"   ";
             
            val = val * (n - r)/r;
        }
        cout<<endl;
    }
}
 
int main(){
 
    int row_num = 8;
    print_pascal(row_num);
 
    return 1;
}