#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int imag;
public:
	void SetReal(int);
	void Setimag(int);
	int GetReal();
	int Getimag();
	void print();
	Complex add(Complex);
	Complex sub(Complex);
};
void Complex::SetReal(int x) {
	real = x;
}
void Complex::Setimag(int x) {
	imag = x;
}
int Complex::GetReal() {
	int temp;
	temp = real;
	return temp;
}
int Complex::Getimag() {
	int temp;
	temp = imag;
	return temp;
}
void Complex::print() {
	cout << real << " + " << imag << "i\n";
}
Complex Complex::add(Complex c) {
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}
Complex Complex::sub(Complex c) {
	Complex temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;
	return temp;
}
int main() {
		Complex myComp1, myComp2, resultComp;
		myComp1.SetReal(7);
		myComp1.Setimag(2);
		myComp2.SetReal(5);
		myComp2.Setimag(3);
		resultComp = myComp1.add(myComp2);
		resultComp.print();
		resultComp = myComp1.sub(myComp2);
		resultComp.print();
		return 0;
	}
	