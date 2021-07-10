#include <iostream>
#include <string>
using namespace std;
int main()
{
	char a[100];
	for (int i = 0; i < 100; i++)
	{
	    char k;
		cin.get(k);
		switch (k)
		{
			case 49:k = ';'; break;
			case 50:k = 49; break;
			case 51:k = 50; break;
			case 52:k = 51; break;
			case 53:k = 52; break;
			case 54:k = 53; break;
			case 55:k = 54; break;
			case 56:k = 55; break;
			case 57:k = 56;	break;
		    case 87:k = 81; break;
			case 69:k = 87; break;
			case 82:k = 69; break;
			case 84:k = 82; break;
			case 89:k = 84; break;
			case 85:k = 89; break;
			case 73:k = 85; break;
			case 79:k = 73; break;
			case 80:k = 79; break;
			case 91:k = 80; break;
			case 93:k = 91; break;
			case 92:k = 93; break;
			case 83:k = 65; break;
			case 68:k = 83; break;
			case 70:k = 68; break;
			case 71:k = 70; break;
			case 72:k = 71; break;
			case 74:k = 72; break;
			case 75:k = 74; break;
			case 76:k = 75; break;
			case 59:k = 76; break;
			case 96:k = '`'; break;
			case 88:k = 90; break;
			case 67:k = 88; break;
			case 86:k = 67; break;
			case 66:k = 86; break;
			case 78:k = 66; break;
			case 77:k = 78; break;
			case 44:k = 77; break;
			case 46:k = 44; break;
			case 47:k = 46; break;
			case 45:k = 48; break;
			case 61:k = 45; break;
		}
		a[i] = k;
		cout << a[i];
	}
	return 0;
	
}


