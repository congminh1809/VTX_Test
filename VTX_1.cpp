#include<iostream>
using namespace std;
#include<string>


class Matrix
{
private:
	int rowNumber;
	int colNumber;
	float matrix[100][100];
public:

	void Import();
	void Export();
	float addition();
	float subtraction();
	float multiplication();

	Matrix();
	~Matrix();
};

void Matrix::Import()
{
	cin.ignore();
	cin >> rowNumber;
	cin >> colNumber;
	
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			cin >> matrix[rowNumber][colNumber];
		}
	}

}

void Matrix::Export()
{
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			cout << matrix[rowNumber][colNumber] << "	";
		}
		cout << endl;
	}
}

// Constructor function
Matrix::Matrix()
{

}
// Destructor function
Matrix::~Matrix()
{

}

void Menu(Matrix* matrixArray[], int matrixNumber)
{
	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ====== Matrix ======";
		cout << "\n1. Import matrix";
		cout << "\n2. Export matrix";
		cout << "\n0. End";
		cout << "\n\n\t\t ======= END =======";

		cout << "\nNhap lua chon: ";
		cin >> choice;
		if (choice < 0 || choice > 2)
		{
			cout << "\nInvalid Choice";
		}
		else if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			Matrix* matrix = new Matrix(); // đối tượng con trỏ
			cout << "\n\n\t\t Import matrix\n";
			matrix->Import();

			matrixArray[matrixNumber] = matrix;
			matrixNumber++;
		}
		
		else if (choice == 2)
		{
			
			for (int i = 0; i < matrixNumber; i++)
			{
				cout << "\n\n\t Export matrix number: " << i + 1 << endl;
				matrixArray[i]->Export();
			}
			
			system("pause");
		}
		
	}

	// giải phóng các đối tượng con trỏ 
	for (int i = 0; i < matrixNumber; i++)
	{
		delete matrixArray[i]; // truy xuất đến miền giá trị của con trỏ <=> địa chỉ của đối tượng cấp phát ban đầu
	}

}

int main()
{
	Matrix* matrixArray[10];
	int matrixNumber = 0;

	Menu(matrixArray, matrixNumber);

	system("pause");
	return 0;
}