#include"head.h"
int main()
{
out:
	Matrix m1;
	m1.display_Matrix();
	string op;
	cout << "输入 'h' 以查看帮助手册" << endl;
	while (cin >> op)
	{
		if (op == "h")
		{
			system("cls");
			cout << "the input and the operation:" << endl;
			cout << "row        查看当前矩阵的行数" << endl;
			cout << "col        查看当前矩阵的列数" << endl;
			cout << "+          矩阵加法" << endl;
			cout << "-          矩阵减法" << endl;
			cout << "*          矩阵乘法" << endl;
			cout << "^          求矩阵的n次幂" << endl;
			cout << "t          求转置矩阵(tranpose) " << endl;
			cout << "ero1       倍加行变换(用某一行的倍数加到某一行)" << endl;
			cout << "ero2       对换行变换(交换两行)" << endl;
			cout << "ero3       倍乘行变换(用非零数乘某行的所有元素)" << endl;
			cout << "eco1       倍加列变换(用某一列的倍数加到某一列)" << endl;
			cout << "eco2       对换列变换(交换两列)" << endl;
			cout << "eco3       倍乘列变换(用非零数乘某列的所有元素)" << endl;
			cout << "ech		求矩阵的简化阶梯形(row echelon form)" << endl;
			cout << "r          求矩阵的秩" << endl;
			cout << "i          求逆矩阵(invert)" << endl;
			cout << "d          求行列式(determinant)" << endl;
			cout << "LU         求矩阵(方阵)的LU分解" << endl;
			cout << "x          求线性方程组的解(Jacobi迭代法和Cramer法则，解Ax=b，分别输入系数矩阵和向量b)" << endl;
			cout << "QR         求矩阵的QR分解" << endl;
			cout << "ev         求矩阵的非零近似实特征值（QR分解法,保留三位小数,若有复特征值则会出现增根)" << endl;
			cout << "pdm        正定矩阵的判定" << endl;
			cout << "c          清屏" << endl;
			cout << "a          重新输入并计算" << endl;
		}
		else if (op == "row")
		{
			cout << "矩阵的行数为:" << endl;
			cout << m1.Get_row();
		}
		else if (op == "col")
		{
			cout << "矩阵的列数为:" << endl;
			cout << m1.Get_col();
		}
		else if (op == "c")
		{
			system("cls");
		}
		else if (op == "a")
		{
			goto out;
		}
		else if (op == "+")
		{
			Matrix m2;
			m2.display_Matrix();
			if (m1.Get_row() == m2.Get_row() && m1.Get_col() == m2.Get_col())
			{
				cout << "矩阵相加的结果为:" << endl;
				m1 = m1.add(m2).display_Matrix();
			}
			else
			{
				cout << "Error" << endl;
			}
		}
		else if (op == "-")
		{
			Matrix m2;
			m2.display_Matrix();
			if (m1.Get_row() == m2.Get_row() && m1.Get_col() == m2.Get_col())
			{
				cout << "矩阵相减的结果为:" << endl;
				m1 = m1.minus(m2).display_Matrix();
			}
			else
			{
				cout << "Error" << endl;
			}
		}
		else if (op == "*")
		{
			Matrix m2;
			m2.display_Matrix();
			if (m1.Get_col() == m2.Get_row())
			{
				cout << "矩阵相乘的结果为:" << endl;
				m1 = m1.multi(m2).display_Matrix();
			}
			else
			{
				cout << "Error" << endl;
			}
		}
		else if (op == "^")
		{
			int n;
			cout << "请输入矩阵的n次正幂:" << endl;
			cin >> n;
			if (n >= 0)
			{
				m1.power(n).display_Matrix();
			}
			else
			{
				cout << "n小于0!" << endl;
			}
		}
		else if (op == "t")
		{
			cout << "矩阵转置的结果为:" << endl;
			m1 = m1.transpose().display_Matrix();
		}
		else if (op == "ero1")
		{
			cout << "请依次输入需要倍乘的行数、倍数、加至的行数:" << endl;
			int row1, row2;
			double k;
			cin >> row1 >> k >> row2;
			cout << "倍加变换的结果为:" << endl;
			m1.elementary_row_operations_1(row1 - 1, k, row2 - 1).display_Matrix();
		}
		else if (op == "ero2")
		{
			cout << "请输入需要对换的两行的行数:" << endl;
			int row1, row2;
			cin >> row1 >> row2;
			cout << "对换变换的结果为:" << endl;
			m1.elementary_row_operations_2(row1 - 1, row2 - 1).display_Matrix();
		}
		else if (op == "ero3")
		{
			cout << "请依次输入需要倍乘的行数、倍数:" << endl;
			int row1;
			double k;
			cin >> row1 >> k;
			cout << "倍乘变换的结果为:" << endl;
			m1.elementary_row_operations_3(row1 - 1, k).display_Matrix();
		}
		else if (op == "eco1")
		{
			cout << "请依次输入需要倍乘的列数、倍数、加至的列数:" << endl;
			int col1, col2;
			double k;
			cin >> col1 >> k >> col2;
			cout << "倍加变换的结果为:" << endl;
			m1.elementary_col_operations_1(col1 - 1, k, col2 - 1).display_Matrix();
		}
		else if (op == "eco2")
		{
			cout << "请输入需要对换的两列的列数:" << endl;
			int col1, col2;
			cin >> col1 >> col2;
			cout << "对换变换的结果为:" << endl;
			m1.elementary_col_operations_2(col1 - 1, col2 - 1).display_Matrix();
		}
		else if (op == "eco3")
		{
			cout << "请依次输入需要倍乘的列数、倍数:" << endl;
			int col1;
			double k;
			cin >> col1 >> k;
			cout << "倍乘变换的结果为:" << endl;
			m1.elementary_col_operations_3(col1 - 1, k).display_Matrix();
		}
		else if (op == "d")
		{
			if (m1.Get_col() != m1.Get_row())
			{
				cout << "Error" << endl;
			}
			else
			{
				cout << "矩阵的行列式为:" << endl;
				cout << m1.determinant() << endl;
			}
		}
		else if (op == "i")
		{
			m1.Print_invert(m1.invert());
		}
		else if (op == "ech")
		{
			m1.row_echelon_form().display_Matrix();
		}
		else if (op == "r")
		{
			cout << "矩阵的秩为：" << m1.rank() << endl;
		}
		else if (op == "LU")
		{
			m1.LU();
		}
		else if (op == "x")
		{
			m1.equation();
			//m1.ViolentSolve().display_Matrix();
		}
		else if (op == "QR")
		{
			m1.QR_display();
		}
		else if (op == "ev")
		{
			m1.ev_Matrix();
		}
		else if (op == "pdm")
		{
			bool j = m1.is_pdm();
			if (j)
			{
				cout << "该矩阵是正定矩阵" << endl;
			}
			else
			{
				cout << "该矩阵不是正定矩阵" << endl;
			}
		}
	}
	system("pause");
}