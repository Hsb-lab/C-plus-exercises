#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
double Round(double);
int gcd(int, int);
class Matrix
{
public:
	Matrix(int newrow, int newcol);
	Matrix();
	Matrix display_Matrix();
	Matrix adjust_format(Matrix);
	Matrix copy_Matrix(Matrix);
	Matrix add(Matrix);
	Matrix minus(Matrix M);
	Matrix multi(Matrix& M);
	Matrix multi_number(double k);
	Matrix power(int n);
	Matrix transpose();
	Matrix elementary_row_operations_1(int row1, double k, int row2);
	Matrix elementary_row_operations_2(int row1, int row2);
	Matrix elementary_row_operations_3(int row1, double k);
	Matrix elementary_col_operations_1(int col1, double k, int col2);
	Matrix elementary_col_operations_2(int col1, int col2);
	Matrix elementary_col_operations_3(int col1, double k);
	Matrix row_echelon_form();
	Matrix ViolentSolve();
	Matrix LU();
	Matrix invert();
	Matrix pre_check_col(int col1, int row_start);
	Matrix Get_Q();
	Matrix QR_display();
	Matrix QR_algorithm();
	Matrix ev_Matrix();
	Matrix Jacobi(Matrix, Matrix, Matrix);
	Matrix Cramer();
	Matrix Cramer(Matrix);
	Matrix Unit();
	Matrix Gram_Schmidt();
	int rank();
	int Get_row();
	int Get_col();
	double Get_ele(int row, int col);
	double all_convergence(Matrix);
	double determinant();
	double inner_product(Matrix, Matrix);
	double pre_check_dia(int start, double k);
	void Print_invert(Matrix);
	void equation();
	void reduce_error();
	bool check_QR();
	bool is_zero(int col1, int row_start);
	bool judge_convergence(Matrix, Matrix);
	bool is_normal();
	bool is_pdm();
private:
	int row;
	int col;
	double** m;
	string judge;
	struct principal_element
	{
		int row;
		int col;
	};
};