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
	void addition(Matrix* matrix1, Matrix* matrix2);
	void subtraction(Matrix* matrix1, Matrix* matrix2);
	void multiplication(Matrix* matrix1, Matrix* matrix2);
	int getRowNum() {
		return this->rowNumber;
	}

	int getColNum() {
		return this->colNumber;
	}

	Matrix();
	~Matrix();
};

void Matrix::Import()
{
	cin.ignore();
	cout << "Row Number: ";
	cin >> rowNumber;
	cout << "Column Number: ";
	cin >> colNumber;

	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			cout << "Matrix" << "[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
			cout << endl;
		}
	}

}

void Matrix::Export()
{
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			cout << matrix[i][j] << "	";
		}
		cout << endl << endl;
	}
}

// Addition 2 matrix
void Matrix::addition(Matrix* matrix1, Matrix* matrix2) {
	//Matrix *tempMatrix;
	float a[100][100];
	for (int i = 0; i < matrix1->rowNumber; i++)
	{
		for (int j = 0; j < matrix1->colNumber; j++)
		{
			//tempMatrix->matrix[i][i] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
			a[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
		}
	}
	//tempMatrix->Export();
	for (int i = 0; i < matrix1->rowNumber; i++)
	{
		for (int j = 0; j < matrix1->colNumber; j++)
		{
			cout << a[i][j] << "	";
		}
		cout << endl << endl;
	}
}


// Subtraction 2 matrix
void Matrix::subtraction(Matrix* matrix1, Matrix* matrix2) {
	//Matrix *tempMatrix;
	float a[100][100];
	for (int i = 0; i < matrix1->rowNumber; i++)
	{
		for (int j = 0; j < matrix1->colNumber; j++)
		{
			//tempMatrix->matrix[i][i] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
			a[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
		}
	}
	//tempMatrix->Export();
	for (int i = 0; i < matrix1->rowNumber; i++)
	{
		for (int j = 0; j < matrix1->colNumber; j++)
		{
			cout << a[i][j] << "	";
		}
		cout << endl << endl;
	}
}

// Multiplication 2 matrix
void Matrix::multiplication(Matrix* matrix1, Matrix* matrix2) {
	//Matrix *tempMatrix;
	float a[100][100];
	for (int i = 0; i < matrix1->rowNumber; i++)
	{
		for (int j = 0; j < matrix2->colNumber; j++)
		{
			//tempMatrix->matrix[i][i] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
			a[i][j] = 0;
			for (int k = 0; k < matrix1->rowNumber; k++)
			{
				a[i][j] = a[i][j] + (matrix1->matrix[i][k] * matrix2->matrix[k][j]);
			}
		}
		cout << endl;
	}
	//tempMatrix->Export();
	for (int i = 0; i < matrix1->rowNumber; i++)
	{
		for (int j = 0; j < matrix1->colNumber; j++)
		{
			cout << a[i][j] << "	";
		}
		cout << endl << endl;
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
		cout << "\n3. Addition 2 matrix";
		cout << "\n4. Subtraction 2 matrix";
		cout << "\n5. Multiplication 2 matrix";
		cout << "\n0. End";
		cout << "\n\n\t\t ======= END =======";

		cout << "\nNhap lua chon: ";
		cin >> choice;
		if (choice < 0 || choice > 5)
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

		else if (choice == 3)
		{
			int matrix1, matrix2;
			cout << "Number of 1st Matrix: ";
			cin >> matrix1;
			matrix1 = matrix1 - 1;
			cout << "Number of 2nd Matrix: ";
			cin >> matrix2;
			matrix2 = matrix2 - 1;
			if (matrixArray[matrix1]->getRowNum() == matrixArray[matrix2]->getRowNum() && matrixArray[matrix1]->getColNum() == matrixArray[matrix2]->getColNum())
			{
				Matrix* addMatrix = new Matrix();
				addMatrix->addition(matrixArray[matrix1], matrixArray[matrix2]);

				system("pause");
			}
			else
			{
				cout << "Row number and Column number of two matrixs are not valid." << endl;
				system("pause");
			}
			
		}

		else if (choice == 4)
		{
			int matrix1, matrix2;
			cout << "Number of 1st Matrix: ";
			cin >> matrix1;
			matrix1 = matrix1 - 1;
			cout << "Number of 2nd Matrix: ";
			cin >> matrix2;
			matrix2 = matrix2 - 1;
			if (matrixArray[matrix1]->getRowNum() == matrixArray[matrix2]->getRowNum() && matrixArray[matrix1]->getColNum() == matrixArray[matrix2]->getColNum())
			{
				Matrix* subMatrix = new Matrix();
				subMatrix->subtraction(matrixArray[matrix1], matrixArray[matrix2]);

				system("pause");
			}
			else
			{
				cout << "Row number and Column number of two matrixs are not valid." << endl;
				system("pause");
			}
			
		}

		else if (choice == 5)
		{
			int matrix1, matrix2;
			cout << "Number of 1st Matrix: ";
			cin >> matrix1;
			matrix1 = matrix1 - 1;
			cout << "Number of 2nd Matrix: ";
			cin >> matrix2;
			matrix2 = matrix2 - 1;
			if (matrixArray[matrix1]->getColNum() == matrixArray[matrix2]->getRowNum())
			{
				Matrix* mulMatrix = new Matrix();
				mulMatrix->multiplication(matrixArray[matrix1], matrixArray[matrix2]);

				system("pause");
			}
			else
			{
				cout << "Row number and Column number of two matrixs are not valid." << endl;
				system("pause");
			}
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