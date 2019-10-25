// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <valarray>
#include <ctime>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  valarray<int> data;       //valarray that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
void operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,7,3,7,4,-5,3,-5,5};
  int data2 [] = {1,2,3,4,5,6,7,8};
  int data3 [] = {10,100,10,100,10,100,10,100};
  int a;
  matrix mat1, mat2, mat3;
  createMatrix (3, 3, data1, mat1);
  createMatrix (4, 2, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  cout<<" enter"<<endl;
  cin>>a;
  switch (a) {

  case 1:
       cout<< operator== ( mat1, mat2)<<endl;// True if identical
       break;
  case 2:
    operator+=(mat1,mat2); // mat1 changes & return// new matrix with the sum
    break;
  case 3:
    operator-=(mat1,mat2); // mat1 changes + return new
					     // matrix with difference
    break;
  case 4:
    int b;
    cin>>b;
    operator+= (mat1, b);// change mat & return new matrix
    break;
  case 5:
    int c;
    cin>>c;
    operator-= (mat1, c);
    break;
  case 6:
    cout<<operator!=(mat1,mat2);// True if not same
    break;
  case 7:
    cout<<isSquare (mat1);// True if square matrix
    break;
  case 8:
    operator++(mat1);
    break;
  case 9:
    operator--(mat1);
    break;
  case 10:
   cout<<isSymetric (mat1);// True if square and symmetric
   break;
  case 11:
    cout<<isIdentity(mat1);// True if square and identity
    break;
  case 12:
     transpose(mat1); // Return new matrix with the transpose
     break;
  case 13:
    ostream& operator<< (ostream& out, matrix mat);
    cout<<mat1<<endl;
     break;
  case 14:
    operator+(mat1,mat2);
    break;
  case 15:
    operator-(mat1,mat2);
    break;
  case 16:
    cout << "please enter a number:"<<endl;
      int x;
      cin >>x;
    operator+(mat1,x);
    break;
  case 17:
     cout << "please enter a number:"<<endl;
    int y;
    cin >>y;
    operator-(mat1,y);
    break;
  case 18:
     cout <<"please enter a number:"<<endl;
    int m;
    cin >> m;
    operator*(mat1,m);
    default:
return a;
  }

//matrix transpose( mat)<<endl; // Return new matrix with the transpose
// The next code will not work until you write the functions
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

/*  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
  return 0;
}
//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
/* int x =sizeof num;
 if(row*col!=2*x){
    cout<<"error return this step please?!!!"<<endl;
 }
 else{*/
  mat.row = row;
  mat.col = col;
  mat.data.resize (row * col);
  for (int i = 0; i < row * col; i++){
    mat.data [i] = num [i];}
}
ostream& operator<< (ostream& out, matrix mat){
    int x[mat.row][mat.col],y=0,b=0;
    for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
            x[i][j]=mat.data[b];
            b++;
            out<<setw(4)<<x[i][j];
        }
            out<<endl;}
    return out;
}
bool operator==(matrix mat1, matrix mat2){
    int x=0;
    if(mat1.row == mat2.row && mat1.col==mat2.col){
  for (int i = 0; i <=mat1. row * mat1.col; i++){
   if( mat1.data[i] != mat2.data[i]){
                x++;
        }}

if(x==0){
    return true;
}
else{return false;}}
else{return false;}

}
bool operator!=(matrix mat1, matrix mat2){
    int x=0;
    if(mat1.row == mat2.row && mat1.col==mat2.col){
  for (int i = 0; i <=mat1. row * mat1.col; i++){
   if( mat1.data[i] != mat2.data[i]){
                x++;
        }}
if(x==0){
    return false;
}
else{return true;}}
else{return false;}

}
bool   isSquare(matrix mat){
if(mat.row==mat.col){
    return true;
}
else{return false;}
}
bool   isIdentity (matrix mat){
if(mat.row==mat.col){
    int x[mat.row][mat.col],y=0,a=0,b=0;
    for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
            x[i][j]=mat.data[b];
            b++;
        }}
        for(int i=0;i<mat.col;i++){
         y+=x[i][i];
        }
        for(int i=0;i<mat.row;i++){
            for(int j=0;j<mat.col;j++){
               a+=x[i][j];
}
}
if(a-y==0&& y%3==0){
    return true;
}
else{return false;}
}
else{return false;}
}
bool  isSymetric (matrix mat){
    if(mat.row==mat.col){
    int x[mat.row][mat.col],y=0,b=0;
    for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
            x[i][j]=mat.data[b];
            b++;
        }}
     for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
            if(x[i][j]==x[j][i]){
                y++;
            }
        }
     }
     if(y==mat.col*mat.row){
        return true;
     }
     else{return false;}

}
else{return false;}
}
matrix transpose(matrix mat){
if(mat.row==mat.col){
    int x[mat.row][mat.col],y=0,b=0;
    for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
            x[i][j]=mat.data[b];
            b++;
        }}

     for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
                    cout<<setw(4)<<x[j][i];}
                    cout<<endl;
}
}
else{cout<<"syntax error";;}
}
matrix operator+= (matrix& mat1, matrix mat2){
if(mat1.row == mat2.row && mat1.col==mat2.col){
   cout<<"{";
for(int i=0;i< mat1.row *mat1.col;i++){
    mat1.data[i]+=mat2.data[i];
    cout<<mat1.data[i]<<",";
}
cout<<"}";
return mat1;}

else {cout<<"those matrices cant add to each other"<<endl;}



}
matrix operator-= (matrix& mat1, matrix mat2){
if(mat1.row == mat2.row && mat1.col==mat2.col){
   cout<<"{";
for(int i=0;i< mat1.row *mat1.col;i++){
    mat1.data[i]-=mat2.data[i];
    cout<<mat1.data[i]<<",";
}
cout<<"}";}

else {cout<<"those matrices cant add to each other"<<endl;}
}
matrix operator+= (matrix& mat, int scalar){
    cout<<"{";
for(int i=0;i< mat.row *mat.col;i++){
    mat.data[i]+=scalar;
    cout<<mat.data[i]<<",";
}
cout<<"}";
}
matrix operator-= (matrix& mat, int scalar){
    cout<<"{";
for(int i=0;i< mat.row *mat.col;i++){
    mat.data[i]-=scalar;
    cout<<mat.data[i]<<",";
}
cout<<"}";
}
void   operator++ (matrix& mat){
        cout<<"{";
for(int i=0;i<(mat.col*mat.row);i++){
mat.data[i]+=1;
cout<<mat.data[i]<<",";
}
cout<<"}";
}
void   operator-- (matrix& mat){
        cout<<"{";
for(int i=0;i<(mat.col*mat.row);i++){
mat.data[i]-=1;
cout<<mat.data[i]<<",";
}
cout<<"}";
}
void operator+(matrix mat1,matrix mat2){
    matrix mat4;
    mat4.row=mat1.row;
    mat4.col=mat1.col;
    mat4.data.resize(mat1.row*mat1.col);
    if (mat1.row==mat2.row && mat1.col==mat2.col){
    cout << "{";
for (int i =0;i<mat1.row*mat1.col;i++){

    mat4.data[i]=mat1.data[i]+mat2.data[i];
    cout<<mat4.data[i]<<",";

}
cout << "}";}
else{cout<<"syntax error"<<endl;}
}
matrix operator-(matrix mat1,matrix mat2){
    matrix mat4;
    mat4.row=mat1.row;
    mat4.col=mat1.col;
    mat4.data.resize(mat1.row*mat1.col);
    if (mat1.row==mat2.row && mat1.col==mat2.col)
    cout << "{";
for (int i =0;i<mat1.row*mat1.col;i++){

    mat4.data[i]=mat1.data[i]-mat2.data[i];
    cout<<mat4.data[i]<<",";

}
cout << "}";
return mat4;
}
matrix operator+(matrix mat1,int scalar){
    matrix mat4;
    mat4.row=mat1.row;
    mat4.col=mat1.col;
    mat4.data.resize(mat1.row*mat1.col);
    cout << "{";
for (int i =0;i<mat1.row*mat1.col;i++){

    mat4.data[i]=mat1.data[i]+scalar;
    cout<<mat4.data[i]<<",";

}
cout << "}";
return mat4;
}
matrix operator-(matrix mat1,int scalar){
    matrix mat4;
    mat4.row=mat1.row;
    mat4.col=mat1.col;
    mat4.data.resize(mat1.row*mat1.col);
    cout << "{";
for (int i =0;i<mat1.row*mat1.col;i++){

    mat4.data[i]=mat1.data[i]-scalar;
    cout<<mat4.data[i]<<",";

}
cout << "}";
return mat4;
}
matrix operator*(matrix mat1,int scalar){
    matrix mat4;
    mat4.row=mat1.row;
    mat4.col=mat1.col;
    mat4.data.resize(mat1.row*mat1.col);
    cout << "{";
for (int i =0;i<mat1.row*mat1.col;i++){

    mat4.data[i]=mat1.data[i]*scalar;
    cout<<mat4.data[i]<<",";

}
cout << "}";
return mat4;
}
