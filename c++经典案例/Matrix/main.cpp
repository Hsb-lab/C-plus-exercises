#include"head.h"
int main()
{
out:
	Matrix m1;
	m1.display_Matrix();
	string op;
	cout << "���� 'h' �Բ鿴�����ֲ�" << endl;
	while (cin >> op)
	{
		if (op == "h")
		{
			system("cls");
			cout << "the input and the operation:" << endl;
			cout << "row        �鿴��ǰ���������" << endl;
			cout << "col        �鿴��ǰ���������" << endl;
			cout << "+          ����ӷ�" << endl;
			cout << "-          �������" << endl;
			cout << "*          ����˷�" << endl;
			cout << "^          ������n����" << endl;
			cout << "t          ��ת�þ���(tranpose) " << endl;
			cout << "ero1       �����б任(��ĳһ�еı����ӵ�ĳһ��)" << endl;
			cout << "ero2       �Ի��б任(��������)" << endl;
			cout << "ero3       �����б任(�÷�������ĳ�е�����Ԫ��)" << endl;
			cout << "eco1       �����б任(��ĳһ�еı����ӵ�ĳһ��)" << endl;
			cout << "eco2       �Ի��б任(��������)" << endl;
			cout << "eco3       �����б任(�÷�������ĳ�е�����Ԫ��)" << endl;
			cout << "ech		�����ļ򻯽�����(row echelon form)" << endl;
			cout << "r          ��������" << endl;
			cout << "i          �������(invert)" << endl;
			cout << "d          ������ʽ(determinant)" << endl;
			cout << "LU         �����(����)��LU�ֽ�" << endl;
			cout << "x          �����Է�����Ľ�(Jacobi��������Cramer���򣬽�Ax=b���ֱ�����ϵ�����������b)" << endl;
			cout << "QR         ������QR�ֽ�" << endl;
			cout << "ev         �����ķ������ʵ����ֵ��QR�ֽⷨ,������λС��,���и�����ֵ����������)" << endl;
			cout << "pdm        ����������ж�" << endl;
			cout << "c          ����" << endl;
			cout << "a          �������벢����" << endl;
		}
		else if (op == "row")
		{
			cout << "���������Ϊ:" << endl;
			cout << m1.Get_row();
		}
		else if (op == "col")
		{
			cout << "���������Ϊ:" << endl;
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
				cout << "������ӵĽ��Ϊ:" << endl;
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
				cout << "��������Ľ��Ϊ:" << endl;
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
				cout << "������˵Ľ��Ϊ:" << endl;
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
			cout << "����������n������:" << endl;
			cin >> n;
			if (n >= 0)
			{
				m1.power(n).display_Matrix();
			}
			else
			{
				cout << "nС��0!" << endl;
			}
		}
		else if (op == "t")
		{
			cout << "����ת�õĽ��Ϊ:" << endl;
			m1 = m1.transpose().display_Matrix();
		}
		else if (op == "ero1")
		{
			cout << "������������Ҫ���˵�����������������������:" << endl;
			int row1, row2;
			double k;
			cin >> row1 >> k >> row2;
			cout << "���ӱ任�Ľ��Ϊ:" << endl;
			m1.elementary_row_operations_1(row1 - 1, k, row2 - 1).display_Matrix();
		}
		else if (op == "ero2")
		{
			cout << "��������Ҫ�Ի������е�����:" << endl;
			int row1, row2;
			cin >> row1 >> row2;
			cout << "�Ի��任�Ľ��Ϊ:" << endl;
			m1.elementary_row_operations_2(row1 - 1, row2 - 1).display_Matrix();
		}
		else if (op == "ero3")
		{
			cout << "������������Ҫ���˵�����������:" << endl;
			int row1;
			double k;
			cin >> row1 >> k;
			cout << "���˱任�Ľ��Ϊ:" << endl;
			m1.elementary_row_operations_3(row1 - 1, k).display_Matrix();
		}
		else if (op == "eco1")
		{
			cout << "������������Ҫ���˵�����������������������:" << endl;
			int col1, col2;
			double k;
			cin >> col1 >> k >> col2;
			cout << "���ӱ任�Ľ��Ϊ:" << endl;
			m1.elementary_col_operations_1(col1 - 1, k, col2 - 1).display_Matrix();
		}
		else if (op == "eco2")
		{
			cout << "��������Ҫ�Ի������е�����:" << endl;
			int col1, col2;
			cin >> col1 >> col2;
			cout << "�Ի��任�Ľ��Ϊ:" << endl;
			m1.elementary_col_operations_2(col1 - 1, col2 - 1).display_Matrix();
		}
		else if (op == "eco3")
		{
			cout << "������������Ҫ���˵�����������:" << endl;
			int col1;
			double k;
			cin >> col1 >> k;
			cout << "���˱任�Ľ��Ϊ:" << endl;
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
				cout << "���������ʽΪ:" << endl;
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
			cout << "�������Ϊ��" << m1.rank() << endl;
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
				cout << "�þ�������������" << endl;
			}
			else
			{
				cout << "�þ�������������" << endl;
			}
		}
	}
	system("pause");
}