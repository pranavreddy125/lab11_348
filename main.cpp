/*
Pranav Reddy
main.cpp
Lab 11 348
Runs program: reads input, performs matrix operations, and displays answer
*/
#include "Matrix.h" //include Matrix.h

int main() {
    string filename; //file name typed in
    ifstream file;   //to read data

    bool fileOpened = false; //for opening the file
    while(!fileOpened) {
        cout<<"Enter file name: ";
        cin>>filename;

        file.open(filename); //try to open the file

        //check if file opened correctly
        if(file.is_open()) {
            fileOpened = true; //exit the loop if file opened
        } else {
            cout<<"Could not open file, try again."<<endl; //print out
        }
    }

    int N; 
    file >> N; //read matrix size 

   
    Matrix A(N);  //create Matrix A with given size
    A.readMatrix(file); //read first matrix values

    Matrix B(N); //same but for B
    B.readMatrix(file); 

    cout<<"Matrix A:"<<endl; //show both matrix
    A.printMatrix();
    cout<<endl;

    cout<<"Matrix B:"<<endl;
    B.printMatrix();
    cout<<endl;

    cout<<"A + B:"<<endl; //add both using our +
    Matrix C = A + B; //new matrix that holds the ans
    C.printMatrix();
    cout<<endl;

    cout<<"A * B:"<<endl; //next multiply using our overloaded *
    Matrix D = A * B;
    D.printMatrix();
    cout<<endl;

    
    cout<<"Diagonal sum of A: "<<A.diagonalSum()<<endl<<endl;

    //ask user which two rows to swap part 5
    int r1, r2;
    cout<<"Enter two row indices to swap (0-"<<N-1<<"), separated by space: ";
    cin>>r1>>r2;

    //if invalid input, default to 0 and 1
    if(cin.fail() || r1<0 || r1>=N || r2<0 || r2>=N) {
        cout<<"Invalid input, using defaults"<<endl;
        r1 = 0;
        r2 = 1;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout<<"Swapped Matrix (rows "<<r1<<" and "<<r2<<"):"<<endl;
    Matrix AR = A.swapRows(r1, r2);
    AR.printMatrix();
    cout<<endl;

    //ask user which two columns to swap
    int c1, c2;
    cout<<"Enter two column indices to swap (0-"<<N-1<<"), separated by space: ";
    cin>>c1>>c2;

    //if invalid input, default to 0 and 1
    if(cin.fail() || c1<0 || c1>=N || c2<0 || c2>=N) {
        cout<<"Invalid input, using defaults"<<endl;
        c1 = 0;
        c2 = 1;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout<<"Swapped Matrix (columns "<<c1<<" and "<<c2<<"):"<<endl;
    Matrix AC = A.swapCols(c1, c2);
    AC.printMatrix();
    cout<<endl;

    //ask user which element to update and to what value
    int row, col, newVal;
    cout<<"Enter row index (0-"<<N-1<<"): ";
    cin>>row;
    cout<<"Enter column index (0-"<<N-1<<"): ";
    cin>>col;
    cout<<"Enter new value: ";
    cin>>newVal;

    //if user just presses enter, use defaults (row&col = 0 and default 100)
    if(cin.fail() || row<0 || row>=N || col<0 || col>=N) {
        cout<<"Invalid input, using defaults (0,0,100)."<<endl;
        row = 0;
        col = 0;
        newVal = 100;
        cin.clear(); //reset cin
        cin.ignore(1000, '\n');
    }

    cout<<"Updated Matrix A:"<<endl;
    Matrix AU = A.updateValue(row, col, newVal);
    AU.printMatrix();
    cout<<endl;

    file.close();
    return 0; //program ends
}