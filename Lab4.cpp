# include <iostream >
# include "vector.h" // header file for all functions relating to vector operations
# include "matrix.h" // header file for all functions relating to matrix operations
using namespace std;

int main()
{

	const int p_INF = 100000;
	double alpha = 0;
	/*
	 * 1. create vectors and matrices
	 */
	Matrix A(5, 4), B(5, 4), C(5, 4),
	D(4, 5), E(5, 5);
	Vector v(5), w(5), t(5);
	/*
	 * 2. initialize vectors and matrices
	 */
	v.random();
	w.random();
	t.zeros();
	A.random();
	B.random();
	C.zeros();
	D.random();
	E.zeros();
	/*
	 * 3. print out the initialized vectors and matrices
	 */
	v.print(" Vector v: ");
	w.print(" Vector w: ");
	t.print(" Vector t: ");
	A.print(" Matrix A: ");
	B.print(" Matrix B: ");
	C.print(" Matrix C: ");
	D.print(" Matrix D: ");
	E.print(" Matrix E: ");
	 /*
	  * 4. compute vector norms
	  */
	cout << "|| v || _2 = " << v.norm(2) << endl;
	cout << "|| v || _max = " << v.norm(p_INF) << endl;
	 /*
	  * 5. operations
	  */
	  // ====== for vectors ========
	  // === adding 2 vectors
	t = v + w;
	t.print(" Vector t = v + w: ");
	 // === scalar - vector multiplication
	t = v * alpha;
	t.print(" Vector t = v* alpha : ");
	 // === increament
	++t;
	t.print(" Vector ++t: ");
	 // === dot product of 2 vectors of the same size
	double beta = dot(v, w);
	cout << " beta = dot (v, w) = " << beta << endl;
	 // ====== for matrices ========
	 // ==== adding 2 matrices
	E.zeros();
	C = A + B;
	C.print(" Matrix C = A + B: ");
	//E = C + B; // should return error
	// ==== matrix - matrix multiplication
	E = A * D;
	E.print(" Matrix E = A * D: ");
	// ==== matrix - scalar multiplication
	E = E * alpha;
	E.print(" Matrix E = E* alpha : ");
	// ==== increament
	++E;
	E.print(" Matrix ++E: ");
	// ==== complex matrix operation
	Matrix F(5, 5, 0.0);
	F = E * (A * transpose(B) + C * D);
	F.print("++E *(( A* transpose (B)) + (C*D )): ");
// ==== matrix - vector multiplication
	t = E * v;
	t.print(" Vector t = E*v: ");
	return 0;
}