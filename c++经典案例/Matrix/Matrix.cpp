#include "head.h"
double Round(double r)
{
	return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}
int gcd(int x, int y)
{
	if (y)
		return gcd(y, x % y);
	else
		return x;
}
Matrix Matrix::adjust_format(Matrix a)
{
	double d = this->determinant();
	a.multi_number(d);
	for (int i = 0; i < a.row; ++i)
	{
		for (int j = 0; j < a.col; ++j)
		{
			a.m[i][j] = Round(a.m[i][j]);
			double s1 = a.m[i][j] / gcd(a.m[i][j], d);
			double s2 = d / gcd(a.m[i][j], d);
			cout << setw(10) << s1 << "/" << s2;
		}
		cout << endl << endl;
	}
	return a;
}
Matrix::Matrix(int newrow, int newcol)
{
	row = newrow;
	col = newcol;
	m = new double* [row];
	for (int i = 0; i < row; i++)
		m[i] = new double[col];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m[i][j] = 0;
		}
	}
}
Matrix::Matrix()
{
	cout << "请分别输入矩阵的行数和列数:" << endl;
	while (true)
	{
		cin >> row >> col;
		if (row <= 0 || col <= 0)
		{
			cout << "行数和列数必须为正数!" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		break;
	}
	m = new double* [row];
	for (int i = 0; i < row; i++)
		m[i] = new double[col];
	cout << "请输入矩阵的各个元素(绝对值超过9999的数字无效)" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			do
			{
				cin >> m[i][j];
			} while (m[i][j] > 999 || m[i][j] < -999);
		}
	}
}
int Matrix::Get_row()
{
	return row;
}
int Matrix::Get_col()
{
	return col;
}
double Matrix::Get_ele(int row, int col)
{
	return m[row][col];
}
Matrix Matrix::display_Matrix()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (fabs(m[i][j]) < 1e-8)
			{
				m[i][j] = 0;
			}
			cout << setw(11) << Get_ele(i, j);
		}
		cout << endl << endl;
	}
	return *this;
}
Matrix Matrix::copy_Matrix(Matrix tmp)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			tmp.m[i][j] = m[i][j];
		}
	}
	return tmp;
}
Matrix Matrix::add(Matrix M)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->m[i][j] = this->m[i][j] + M.m[i][j];
		}
	}
	return *this;
}
Matrix Matrix::minus(Matrix M)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->m[i][j] = this->m[i][j] - M.m[i][j];
		}
	}
	return *this;
}
Matrix Matrix::multi(Matrix& M)
{
	Matrix m_ret(this->row, M.col);
	for (int p_row = 0; p_row < this->row; p_row++)
	{
		for (int p_col = 0; p_col < M.col; p_col++)
		{
			for (int i = 0; i < this->col; i++)
			{
				m_ret.m[p_row][p_col] += (this->m[p_row][i]) * (M.m[i][p_col]);
			}
		}
	}
	return m_ret;
}
Matrix Matrix::multi_number(double k)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			this->m[i][j] *= k;
		}
	}
	return *this;
}
Matrix Matrix::power(int n)
{
	if (col != row)
	{
		cout << "该矩阵不是方阵!" << endl;
		return *this;
	}
	if (n == 0)
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i == j)
				{
					m[i][j] = 1;
				}
				else
				{
					m[i][j] = 0;
				}
			}
		}
		cout << "矩阵的" << n << "次幂为:" << endl;
		return *this;
	}
	else
	{
		for (int i = 1; i < n; ++i)
		{
			*this = multi(*this);
		}
		cout << "矩阵的" << n << "次幂为:" << endl;
		return *this;
	}
}
Matrix Matrix::transpose()
{
	Matrix m_ret(this->col, this->row);
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			m_ret.m[j][i] = m[i][j];
		}
	}
	return m_ret;
}
Matrix Matrix::elementary_row_operations_1(int row1, double k, int row2)
{
	for (int j = 0; j < this->col; j++)
	{
		m[row2][j] = m[row1][j] * k + m[row2][j];
	}
	return *this;
}
Matrix Matrix::elementary_row_operations_2(int row1, int row2)
{
	for (int j = 0; j < this->col; j++)
	{
		swap(m[row1][j], m[row2][j]);
	}
	return *this;
}
Matrix Matrix::elementary_row_operations_3(int row1, double k)
{
	for (int j = 0; j < this->col; j++)
	{
		m[row1][j] = m[row1][j] * k;
	}
	return *this;
}
Matrix Matrix::elementary_col_operations_1(int col1, double k, int col2)
{
	for (int j = 0; j < this->row; j++)
	{
		m[j][col2] = m[j][col1] * k + m[j][col2];
	}
	return *this;
}
Matrix Matrix::elementary_col_operations_2(int col1, int col2)
{
	for (int j = 0; j < this->row; j++)
	{
		swap(m[j][col1], m[j][col2]);
	}
	return *this;
}
Matrix Matrix::elementary_col_operations_3(int col1, double k)
{
	for (int j = 0; j < this->row; j++)
	{
		m[j][col1] = m[j][col1] * k;
	}
	return *this;
}
Matrix Matrix::row_echelon_form()
{
	vector<principal_element>v;
	int pcol = 0, prow = 0;
	while (pcol < col && prow < row)
	{
		if (is_zero(pcol, prow))
		{
			++pcol;
			continue;
		}
		for (int i = prow; i < row; ++i)
		{
			if (m[i][pcol] != 0)
			{
				elementary_row_operations_2(i, prow);
				break;
			}
		}
		double base = m[prow][pcol];
		principal_element p;
		p.row = prow;
		p.col = pcol;
		v.push_back(p);
		for (int i = prow + 1; i < row; ++i)
		{
			if (m[i][pcol] != 0)
			{
				elementary_row_operations_1(prow, -m[i][pcol] / base, i);
			}
		}
		++prow;
		++pcol;
	}
	for (int i = v.size() - 1; i >= 0; --i)
	{
		elementary_row_operations_3(v[i].row, 1 / m[v[i].row][v[i].col]);
		for (int j = 0; j < v[i].row; ++j)
		{
			elementary_row_operations_1(v[i].row, -m[j][v[i].col], j);
		}
	}
	v.clear();
	return *this;
}
int Matrix::rank()
{
	int rank = 0;
	int pcol = 0, prow = 0;
	while (pcol < col && prow < row)
	{
		if (is_zero(pcol, prow))
		{
			++pcol;
			continue;
		}
		for (int i = prow; i < row; ++i)
		{
			if (m[i][pcol] != 0)
			{
				elementary_row_operations_2(i, prow);
				break;
			}
		}
		double base = m[prow][pcol];
		rank++;
		for (int i = prow + 1; i < row; ++i)
		{
			if (m[i][pcol] != 0)
			{
				elementary_row_operations_1(prow, -m[i][pcol] / base, i);
			}
		}
		++prow;
		++pcol;
	}
	return rank;
}
void Matrix::reduce_error()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			if (fabs(m[i][j]) < 1e-6)
			{
				m[i][j] = 0;
			}
		}
	}
}
double Matrix::pre_check_dia(int start, double k)
{
	for (int check_row = start, check_col = start; check_row < this->row; check_row++, check_col++)
	{
		if (m[check_row][check_col] == 0)
		{
			for (int p = check_row; p < this->row; p++)
			{
				if (m[p][check_col] != 0)
				{
					k = k * (-1);
					this->elementary_row_operations_2(check_row, p);
					break;
				}
			}
			for (int p = check_row; p >= start; p--)
			{
				if (m[p][check_col] != 0)
				{
					k = k * (-1);
					this->elementary_row_operations_2(check_row, p);
					break;
				}
			}
		}
	}
	return k;
}
double Matrix::determinant()
{
	double k = 1; //k表示目前行列式为原行列式的k倍
	double ret = 0;
	int p_row = this->row, p_col = this->col;
	Matrix p(p_row, p_col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			p.m[i][j] = m[i][j];
		}
	}
	for (int j = 0; j < p_col; j++)
	{
		k = p.pre_check_dia(j, k);
		for (int i = j; i < p_row; i++)
		{
			if (p.m[i][j] != 0)
			{
				k = k * p.m[i][j];
				p.elementary_row_operations_3(i, 1 / p.m[i][j]);
			}
		}
		for (int i = j + 1; i < p_row; i++)
		{
			if (p.m[i][j] != 0)
			{
				p.elementary_row_operations_1(j, -1, i);
			}
		}
	}
	p.reduce_error();
	int judge = 0;   //判断对角矩阵主对角线是否有0
	for (int check_row = 0, check_col = 0; check_row < this->row; check_row++, check_col++)
	{
		if (p.m[check_row][check_col] == 0)
		{
			judge = 1;
			break;
		}
	}
	if (!judge)
		if (fabs(k) < 1e-6)
		{
			return 0;
		}
		else
		{
			return k;
		}
	else
	{
		return 0;
	}
}
Matrix Matrix::invert()
{
	if (col != row)
	{
		cout << "该矩阵不可逆!" << endl;
		return *this;
	}
	Matrix p(row, 2 * col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p.m[i][j] = m[i][j];
		}
	}
	for (int i = 0, j = col; j < 2 * col; i++, j++)
	{
		p.m[i][j] = 1;
	}

	for (int j = 0; j < col; j++)
	{
		for (int check_row = j, check_col = j; check_row < this->row; check_row++, check_col++)
		{
			if (m[check_row][check_col] == 0)
			{
				for (int s = check_row; s < this->row; s++)
				{
					if (m[s][check_col] != 0)
					{
						p.elementary_row_operations_2(check_row, s);
						break;
					}
				}
				for (int s = check_row; s >= j; s--)
				{
					if (m[s][check_col] != 0)
					{
						p.elementary_row_operations_2(check_row, s);
						break;
					}
				}
			}
		}
		for (int i = j; i < row; i++)
		{
			if (p.m[i][j] != 0)
			{
				p.elementary_row_operations_3(i, 1 / p.m[i][j]);
			}
		}
		for (int i = j + 1; i < row; i++)
		{
			if (p.m[i][j] != 0)
			{
				p.elementary_row_operations_1(j, -1, i);
			}
		}
	}
	p.reduce_error();
	for (int i = row - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			p.elementary_row_operations_1(i, -p.m[j][i], j);
		}
	}
	for (int i = 0, j = 0; j < col; i++, j++)
	{
		if (p.m[i][j] != 1)
		{
			cout << "该矩阵不可逆!" << endl;
			judge = "no";
			return *this;
		}
	}
	p.reduce_error();
	Matrix ret(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ret.m[i][j] = p.m[i][j + col];
		}
	}
	return ret;
}
void Matrix::Print_invert(Matrix ret)
{
	if (judge == "no")
	{
		return;
	}
	judge.clear();
	cout << "矩阵的逆矩阵为:(正常解)" << endl;
	for (int i = 0; i < ret.row; i++)
	{
		for (int j = 0; j < ret.col; j++)
		{
			cout << setw(12) << ret.m[i][j];
		}
		cout << endl << endl;
	}
	cout << endl << endl << "矩阵的逆矩阵为:(分数近似解)" << endl;
	adjust_format(ret);
}
Matrix Matrix::pre_check_col(int col1, int row_start)
{
	for (int i = row_start + 1; i < row; i++)
	{
		if (m[row_start][col1] == 0)
		{
			if (m[i][col1] != 0)
			{
				elementary_row_operations_2(row_start, i);
				break;
			}
		}
	}
	return *this;
}
bool Matrix::is_zero(int col1, int row_start)   //判断是否为零列
{
	for (int i = row_start; i < row && col1 < col; i++)
	{
		if (isnormal(m[i][col1]) != 0)
		{
			return false;
		}
	}
	return true;
}
Matrix Matrix::LU()
{

	if (row != col)
	{
		cout << "该矩阵不是方阵！" << endl;
		return *this;
	}
	if (!is_pdm())
	{
		cout << "该矩阵不可LU分解!" << endl;
		return *this;
	}
	Matrix L(this->col, this->row);
	for (int i = 0; i < L.row; ++i)
	{
		for (int j = 0; j < L.col; ++j)
		{
			if (i == j)
			{
				L.m[i][j] = 1;
			}
			else
			{
				L.m[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < col; ++i)
	{
		if (m[i][i] == 0)
		{
			cout << "该矩阵不可LU分解!" << endl;
			return *this;
		}
		for (int j = i + 1; j < row; ++j)
		{
			L.m[j][i] = m[j][i] / m[i][i];
			elementary_row_operations_1(i, -m[j][i] / m[i][i], j);
		}
	}
	this->reduce_error();
	L.reduce_error();
	cout << "L: " << endl;
	L.display_Matrix();
	cout << "U :" << endl;
	this->display_Matrix();
	Matrix MatrixLU(this->row, 2 * this->col);
	for (int i = 0; i < L.row; ++i)
	{
		for (int j = 0; j < L.col; ++j)
		{
			MatrixLU.m[i][j] = L.m[i][j];
		}
		for (int j = L.col; j < MatrixLU.col; ++j)
		{
			MatrixLU.m[i][j] = this->m[i][j - L.col];
		}
	}
	return MatrixLU;
}
void Matrix::equation()
{
	if (col != row)
	{
		cout << "该系数矩阵不是方阵!" << endl;
		return;
	}
	if (this->determinant() == 0)
	{
		cout << "该线性方程组无解或有无穷多解!" << endl;
		return;
	}
	cout << "请输入向量b的各个元素:" << endl;
	Matrix b(this->row, 1);
	for (int i = 0; i < row; ++i)
	{
		cin >> b.m[i][0];
	}
	int judge = 0;
	for (int i = 0; i < row; ++i)
	{
		if (m[i][i] == 0)
		{
			judge = 1;
			break;
		}
	}
	if (judge == 0)
	{
		Matrix B(this->row, this->col);
		Matrix L(this->row, this->col);
		Matrix U(this->row, this->col);
		Matrix F(this->row, this->col);
		Matrix N(this->row, this->col);
		for (int i = 0; i < row; ++i)
		{
			B.m[i][i] = this->m[i][i];
			N.m[i][i] = -1;
		}
		B = B.invert();
		F = B.multi(b);
		for (int i = 0; i < col; ++i)
		{
			for (int j = i + 1; j < row; ++j)
			{
				L.m[j][i] = this->m[j][i];
			}
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = i + 1; j < row; ++j)
			{
				U.m[i][j] = this->m[i][j];
			}
		}
		L = L.add(U);
		B = B.multi(L).multi(N);
		this->Jacobi(B, F, b);
	}
	else
	{
		this->Cramer(b);
	}
	return;
}
Matrix Matrix::Cramer(Matrix b)
{
	Matrix ret(row, 1);
	double det = this->determinant();
	for (int i = 0; i < col; ++i)
	{
		Matrix replace(row, col);
		for (int j = 0; j < row; ++j)
		{
			for (int k = 0; k < col; ++k)
			{
				replace.m[j][k] = m[j][k];
			}
		}
		for (int j = 0; j < row; ++j)
		{
			replace.m[j][i] = b.m[j][0];
			ret.m[i][0] = replace.determinant() / det;
		}
	}
	cout << "线性方程组的解为:" << endl;
	ret.display_Matrix();
	return ret;
}
Matrix Matrix::Cramer()
{
	if (col != row)
	{
		cout << "该系数矩阵不是方阵!" << endl;
		return *this;
	}
	if (this->determinant() == 0)
	{
		cout << "该线性方程组无解或有无穷多解!" << endl;
		return *this;
	}
	cout << "请输入向量b的各个元素:" << endl;
	Matrix b(this->row, 1);
	for (int i = 0; i < row; ++i)
	{
		cin >> b.m[i][0];
	}
	Matrix ret(row, 1);
	double det = this->determinant();
	for (int i = 0; i < col; ++i)
	{
		Matrix replace(row, col);
		for (int j = 0; j < row; ++j)
		{
			for (int k = 0; k < col; ++k)
			{
				replace.m[j][k] = m[j][k];
			}
		}
		for (int j = 0; j < row; ++j)
		{
			replace.m[j][i] = b.m[j][0];
			ret.m[i][0] = replace.determinant() / det;
		}
	}
	cout << "线性方程组的解为:" << endl;
	ret.display_Matrix();
	return ret;
}
Matrix Matrix::Jacobi(Matrix B, Matrix F, Matrix b)
{
	Matrix x(this->row, 1);
	for (int i = 0; i < row; ++i)
	{
		x.m[i][0] = 0;
	}
	for (int j = 0; j < 1000; ++j)
	{
		if (fabs(x.m[0][0]) >= 1e7)
		{
			this->Cramer(b);				//更换方法
			return *this;
		}
		x = B.multi(x).add(F);
	}
	cout << "线性方程组的解为:" << endl;
	x.display_Matrix();
	return x;
}
Matrix Matrix::ViolentSolve()
{
	if (col != row)
	{
		cout << "该系数矩阵不是方阵!" << endl;
		return *this;
	}
	if (this->determinant() == 0)
	{
		cout << "该线性方程组无解或有无穷多解!" << endl;
		return *this;
	}
	cout << "请输入向量b的各个元素:" << endl;
	Matrix b(this->row, 1);
	for (int i = 0; i < row; ++i)
	{
		cin >> b.m[i][0];
	}
	Matrix x(this->row, 1);
	x = this->invert().multi(b);
	return x;
}
Matrix Matrix::Unit()
{
	for (int i = 0; i < col; ++i)
	{
		double mod = 0;
		for (int j = 0; j < row; ++j)
		{
			if (abs(m[j][i]) < 1e-8)
			{
				m[j][i] = 0;
			}
			mod += m[j][i] * m[j][i];
		}
		mod = sqrt(mod);
		this->elementary_col_operations_3(i, 1 / mod);
	}
	return *this;
}
double Matrix::inner_product(Matrix a, Matrix b)
{
	return a.transpose().multi(b).m[0][0];
}
Matrix Matrix::Gram_Schmidt()
{
	if (!check_QR())
	{
		return *this;
	}
	vector<Matrix>v;
	vector<Matrix>x;
	Matrix e(row, 1);
	for (int i = 0; i < col; ++i)
	{
		v.push_back(e);
		x.push_back(e);
	}
	for (int i = 0; i < col; ++i)
	{
		Matrix tmp(row, 1);
		for (int j = 0; j < row; ++j)
		{
			tmp.m[j][0] = this->m[j][i];
		}
		x[i] = tmp;
	}
	v[0] = x[0];
	for (int i = 1; i < col; ++i)
	{
		Matrix tmpx = x[i];
		for (int j = 1; j <= i; ++j)
		{
			double k = -inner_product(x[i], v[j - 1]) / inner_product(v[j - 1], v[j - 1]);
			Matrix tmpv = v[j - 1];
			tmpv.elementary_col_operations_3(0, k);
			tmpx.add(tmpv);
		}
		v[i] = tmpx;
	}
	Matrix ret(row, col);
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			ret.m[j][i] = v[i].m[j][0];
		}
	}
	ret.Unit();
	return ret;
}
Matrix Matrix::QR_display()
{
	int judge = 0;
	if (!check_QR())
	{
		judge = 1;
	}
	Matrix tmp(*this);
	cout << "Q:" << endl;
	tmp = tmp.Gram_Schmidt().display_Matrix();
	tmp = tmp.transpose().multi(*this);
	cout << "R:" << endl;
	if (judge)
	{
		int newrow = tmp.Get_row();
		int newcol = tmp.Get_col();
		Matrix E(newrow, newcol);
		for (int i = 0; i < newrow; ++i)
		{
			E.m[i][i] = 1;
		}
		E.display_Matrix();
		return E;
	}
	else
	{
		tmp.display_Matrix();
		return tmp;
	}
}
bool Matrix::check_QR()
{
	for (int i = 0; i < col; ++i)
	{
		for (int j = i + 1; j < row; ++j)
		{
			if (fabs(m[j][i]) >= 1e-7)
				return true;
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = i + 1; j < col; ++j)
		{
			if (fabs(m[i][j]) >= 1e-7)
				return true;
		}
	}
	return false;
}
Matrix Matrix::Get_Q()
{
	return this->Gram_Schmidt();
}
Matrix Matrix::QR_algorithm()
{
	Matrix A(*this);
	Matrix Q = A.Get_Q();
	Matrix QT = Q.transpose();
	return QT.multi(*this).multi(Q);
}
bool Matrix::is_normal()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (m[i][j] == 0)
			{
				continue;
			}
			if (isnormal(m[i][j]) == 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Matrix::judge_convergence(Matrix a, Matrix b)
{
	int count = 0;
	for (int i = 0; i < a.row; ++i)
	{
		for (int j = 0; j < a.col; ++j)
		{
			if (fabs(a.m[i][j] - b.m[i][j]) <= 5e-8)
			{
				count++;
			}
		}
	}
	if (count == a.row * a.col)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double Matrix::all_convergence(Matrix a)
{
	double sum = 0;
	for (int i = 0; i < row; ++i)
	{
		sum += fabs(a.m[i][i] - Round(a.m[i][i]));
	}
	return sum;
}
Matrix Matrix::ev_Matrix()
{
	if (this->determinant() == 0)
	{
		cout << "矩阵的特征值含有0,不能计算出所有特征值" << endl << endl;
		return *this;
	}
	int cnt = 0;
	for (int i = 0;; ++i)
	{
		double s1, s2;
		Matrix a(*this);
		s1 = all_convergence(a);
		Matrix b(a.QR_algorithm());
		s2 = all_convergence(b);
		if (s2 > s1)
		{
			cnt++;
			if (cnt >= 4)
			{
				break;
			}
		}
		else
		{
			cnt = 0;
		}
		if (!this->is_normal() || (i > 1e5))
		{
			vector<double>rec;
			for (int i = 0; i < row; ++i)
			{
				if (isnormal(m[i][i]) == 1)
				{
					rec.push_back(m[i][i]);
				}
			}
			if (rec.size() == 0)
			{
				cout << "该矩阵无实特征值！" << endl;
			}
			else
			{
				cout << "矩阵可能的近似特征值为:" << endl << endl;
				for (int i = 0; i < rec.size(); ++i)
				{
					cout << setprecision(3) << fixed << rec[i] << endl << endl;
				}
			}
			return *this;
		}
		if (!this->check_QR() || judge_convergence(*this, b))
		{
			break;
		}
		*this = b;
	}
	//this->display_Matrix();
	cout << "矩阵可能的近似特征值为:" << endl << endl;
	for (int i = 0; i < col; ++i)
	{
		cout << setprecision(3) << fixed << this->m[i][i] << endl << endl;
	}
	return *this;
}
bool Matrix::is_pdm()
{
	if (col != row)
	{
		cout << "该矩阵不是方阵,故不是正定矩阵!" << endl;
		return false;
	}
	for (int i = 0; i < row; ++i)
	{
		Matrix tmp(i + 1, i + 1);
		for (int j = 0; j <= i; ++j)
		{
			for (int k = 0; k <= i; ++k)
			{
				tmp.m[j][k] = m[j][k];
			}
		}
		if (tmp.determinant() <= 0)
		{
			return false;
		}
	}
	return true;
}