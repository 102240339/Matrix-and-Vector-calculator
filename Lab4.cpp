# include <iostream>
# include "vector.h" 
# include "matrix.h" 
using namespace std;

int main()
{
	int a;
	do {
		cout << "1. Matrix" << endl << "2. Vector" << endl << "3. Quit" << endl
			<< "Your choice: ";cin >> a;
		int b = 1;
		switch (a) {
		case 1: {
			while (b != 0) {
				int c;
				cout << "This is matrix calculation mode!!" << endl
					<< "You want to continue ?" << endl
					<< "(press any number to continue and press 0 to exit)";cin >> c;
				if (c == 0) {
					b = 0;
					break;
				}
				else {
					int col, row; int d;
					cout << "Please enter number of rows for A: "; cin >> row;
					cout << "Please enter number of columns for A: "; cin >> col;
					Matrix A(row, col);
					cout << "1. Enter mannually\t2. Random" << endl
						<< "Please choose an option: "; cin >> d;
					if (d == 0) {
						A.random(); cout << endl;
					}
					else {
						for (int i = 0; i < row;++i) {
							for (int j = 0; j < col; ++j) {
								double entry;
								cout << "Enter the value for A(" << i + 1 << ")(" << j + 1 << "): "; cin >> entry;
								A.setEntry(i, j, entry);cout << endl;
							}
						}
					}
					cout << "Please enter number of rows for B: "; cin >> row;
					cout << "Please enter number of columns for B: "; cin >> col;
					Matrix B(row, col);
					cout << "1. Enter mannually\t2. Random" << endl
						<< "Please choose an option: "; cin >> d;
					if (d == 0) {
						B.random();cout << endl;
					}
					else {
						for (int i = 0; i < row;++i) {
							for (int j = 0; j < col; ++j) {
								double entry;
								cout << "Enter the value for B(" << i + 1 << ")(" << j + 1 << "): "; cin >> entry;
								B.setEntry(i, j, entry);cout << endl;
							}
						}
					}
					cout << "Please enter number of rows for C: "; cin >> row;
					cout << "Please enter number of columns for C: "; cin >> col;
					Matrix C(row, col);
					cout << "1. Enter mannually\t2. Random" << endl
						<< "Please choose an option: "; cin >> d;
					if (d == 0) {
						C.random(); cout << endl;
					}
					else {
						for (int i = 0; i < row;++i) {
							for (int j = 0; j < col; ++j) {
								double entry;
								cout << "Enter the value for C(" << i + 1 << ")(" << j + 1 << "): "; cin >> entry;
								C.setEntry(i, j, entry);cout << endl;
							}
						}
					}
					cout << endl;
					int e = 1;
					while (e != 0) {
						int f = 0; double det;
						cout << "0. Closed program" << endl
							<< "1. mA + nB\t2. mA + nC\t3. mB + nC" << endl
							<< "4. mA + nB + kC" << endl
							<< "5. mA x nB\t6. mA x nC\t7. mB x nC" << endl
							<< "8. det(A)\t9. det(B)\t10. det(C)" << endl
							<< "11. Re-edit the matrices\t12. Back to choosing modes stage" << endl
							<< "m,n,k are scalar. If you want substracting matrices please enter scalar as nagative number." << endl
							<< "det -> determinant" << endl << "Choose an option: "; cin >> f;
						switch (f) {
						case 0:
							e = 0; b = 0;
							a = 3; break;
						case 1: {
							if (A.getCol() != B.getCol() || A.getRow() != B.getRow()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Matrix ans(A.getRow(), A.getCol());
								ans = A * m + B * n;
								ans.print("ans");
							}
							break;
						}
						case 2: {
							if (A.getCol() != C.getCol() || A.getRow() != C.getRow()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Matrix ans(A.getRow(), A.getCol());
								ans = A * m + C * n;
								ans.print("ans");
							}
							break;
						}
						case 3: {
							if (C.getCol() != B.getCol() || C.getRow() != B.getRow()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Matrix ans(B.getRow(), B.getCol());
								ans = B * m + C * n;
								ans.print("ans");
							}
							break;
						}
						case 4: {
							if (A.getCol() != B.getCol() || A.getRow() != B.getRow() 
								|| B.getCol()!=C.getCol() || B.getRow()!=C.getRow()
								|| A.getCol() != C.getCol() || A.getRow() != C.getRow()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n,k;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								cout << "Please enter k: ";cin >> k;
								Matrix ans(A.getCol(), A.getRow());
								ans = A * m + B * n + C*k;
								ans.print("ans");
							}
							break;
						}
						case 5: {
							if (A.getCol() != B.getRow()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Matrix ans(A.getRow(), B.getCol());
								ans = (A * m) * (B * n);
								ans.print("ans");
							}
							break;
						}
						case 6: {
							if (A.getCol() != C.getRow()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Matrix ans(A.getRow(), C.getCol());
								ans = (A * m) *( C * n);
								ans.print("ans");
							}
							break;
						}
						case 7: {
							if (B.getCol() != C.getRow()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Matrix ans(B.getRow(), C.getCol());
								ans = (B* m) * (C * n);
								ans.print("ans");
							}
							break;
						}
						case 8:
							if (A.getCol() != A.getRow()) {
								cout << "A must be square matrix. Please try another calculation." << endl<<endl;
							}
							else {
								det = getDet(A, A.getCol());
								cout << "det(A) = " << det << endl;
							}
							break;
						case 9:
							if (B.getCol() != B.getRow()) {
								cout << "B must be square matrix. Please try another calculation." << endl << endl;
							}
							else {
								det = getDet(B, B.getCol());
								cout << "det(B) = " << det << endl;
							}
							break;
						case 10:
							if (C.getCol() != C.getRow()) {
								cout << "C must be square matrix. Please try another calculation." << endl << endl;
							}
							else {
								det = getDet(C, C.getCol());
								cout << "det(A) = " << det << endl;
							}
							break;
						case 11:
							e = 0; break;
						case 12:
							e = 0; b = 0;
							break;
						default:
							cout << endl << "Your selection is out of scope !!!" << endl << "Pleas choose again" << endl << endl;
							break;
						}

					}
				}
			}
			break;
		}
		case 2: {
			while (b != 0) {
				int c;
				cout << "This is vector calculation mode!!" << endl
					<< "You want to continue ?" << endl
					<< "(press any number to continue and press 0 to exit)";cin >> c;
				if (c == 0) {
					b = 0;
					break;
				}
				else {
					int size; int d;
					cout << "Please enter size for vector A: "; cin >> size;
					Vector A(size);
					cout << "1. Enter mannually\t2. Random" << endl
						<< "Please choose an option: "; cin >> d;
					if (d == 0) {
						A.random(); cout << endl;
					}
					else {
						for (int i = 0; i < size;++i) {
							double entry;
							cout << "Enter the value for A(" << i + 1 << "): "; cin >> entry;
							A.setEntry(i, entry);cout << endl;
						}
					}
					cout << "Please enter size for vector B: "; cin >> size;
					Vector B(size);
					cout << "1. Enter mannually\t2. Random" << endl
						<< "Please choose an option: "; cin >> d;
					if (d == 0) {
						B.random(); cout << endl;
					}
					else {
						for (int i = 0; i < size;++i) {
							double entry;
							cout << "Enter the value for B(" << i + 1 << "): "; cin >> entry;
							B.setEntry(i, entry);cout << endl;
						}
					}
					cout << "Please enter size for vector C: "; cin >> size;
					Vector C(size);
					cout << "1. Enter mannually\t2. Random" << endl
						<< "Please choose an option: "; cin >> d;
					if (d == 0) {
						C.random(); cout << endl;
					}
					else {
						for (int i = 0; i < size;++i) {
							double entry;
							cout << "Enter the value for C(" << i + 1 << "): "; cin >> entry;
							B.setEntry(i, entry);cout << endl;
						}
					}
					cout << endl;
					int e = 1;
					while (e != 0) {
						int f = 0; double dotp;
						cout << "0. Closed program" << endl
							<< "1. mA + nB\t2. mA + nC\t3. mB + nC" << endl
							<< "4. mA + nB + kC" << endl
							<< "5. mA x nB\t6. mA x nC\t7. mB x nC" << endl
							<< "8. dot(A,B)\t9. dot(B,C)\t10. dot(A,C)" << endl
							<< "11. Re-edit the matrices\t12. Back to choosing modes stage" << endl
							<< "m,n,k are scalar. If you want substracting matrices please enter scalar as nagative number." << endl
							<< "det -> determinant" << endl << "Choose an option: "; cin >> f;
						switch (f) {
						case 0:
							e = 0; b = 0;
							a = 3; break;
						case 1: {
							if (A.getSize() != B.getSize()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Vector ans(A.getSize());
								ans = A * m + B * n;
								ans.print("ans");
							}
							break;
						}
						case 2: {
							if (A.getSize() != C.getSize()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Vector ans(A.getSize());
								ans = A * m + C * n;
								ans.print("ans");
							}
							break;
						}
						case 3: {
							if (C.getSize() != B.getSize()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Vector ans(A.getSize());
								ans = B * m + C * n;
								ans.print("ans");
							}
							break;
						}
						case 4: {
							if (A.getSize() != B.getSize() || A.getSize() != C.getSize() || B.getSize() != C.getSize()) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n, k;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								cout << "Please enter k: ";cin >> k;
								Vector ans(A.getSize());
								ans = A * m + B * n + C * k;
								ans.print("ans");
							}
							break;
						}
						case 5: {
							if (B.getSize() != A.getSize() || A.getSize() != 3 || B.getSize() != 3) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Vector ans(3);
								ans = (A * m) * (B * n);
								ans.print("ans");
							}
							break;
						}
						case 6: {
							if (A.getSize() != C.getSize() || C.getSize() != 3 || A.getSize() != 3) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Vector ans(3);
								ans = (A * m) * (C * n);
								ans.print("ans");
							}
							break;
						}
						case 7: {
							if (B.getSize() != C.getSize() || C.getSize() != 3 || B.getSize() != 3) {
								cout << "Syntax error.Please try another calculation." << endl << endl;
							}
							else {
								int m, n;
								cout << "Please enter m: ";cin >> m;
								cout << "Please enter n: ";cin >> n;
								Vector ans(3);
								ans = (B * m) * (C * n);
								ans.print("ans");
							}
							break;
						}
						case 8:
							if (A.getSize() != B.getSize()) {
								cout << "Syntax eror. Please try another calculation." << endl << endl;
							}
							else {
								dotp = dot(A, B);
								cout << "dot(A,c) = " << dotp << endl;
							}
							break;
						case 9:
							if (C.getSize() != B.getSize()) {
								cout << "Syntax eror. Please try another calculation." << endl << endl;
							}
							else {
								dotp = dot(B, C);
								cout << "dot(A,c) = " << dotp << endl;
							}
							break;
						case 10:
							if (C.getSize() != A.getSize()) {
								cout << "Syntax eror. Please try another calculation." << endl << endl;
							}
							else {
								dotp = dot(A,C);
								cout << "dot(A,c) = " << dotp << endl;
							}
							break;
						case 11:
							e = 0; break;
						case 12:
							e = 0; b = 0;
							break;
						default:
							cout << endl << "Your selection is out of scope !!!" << endl << "Pleas choose again" << endl << endl;
							break;
						}

					}
				}
			}
			break;
		}
		default:
			cout << endl << "Your selection is out of scope !!!" << endl << "Pleas choose again" << endl << endl;
			break;
		}
	} while (a != 3);
}
