#include <iostream>
#include <string>
// ��� ��������!
#include <io.h>
#include <fcntl.h>
#include <stdexcept>
// ��� ��������� �������!
#include <conio.h> 

void MainMenu();
int getVariant(int count);
wchar_t digitToSuperscript(unsigned int digit);


class Polynom {

private:
	int degree = 0;                                       // ������������ ������� ���������� .
	// int* polynomial�oefficient = new int[degree + 1]; // ����������� ����������, ������� ����� ��������� � �������.
	int* polynomial�oefficient = nullptr;
	int* newPolynomials = nullptr;

public:
	void inputDegree();         // ����������� ������������ ������� ����������.
	void input�oefficient();    // ����������� ��� ������������ ����������.
	std::wstring outputPolinom();    //������� ��������� ���������.
	std::wstring outputNewPolynomials();    //������� ����� ���������.
	std::wstring varDegree(int i); // ��������� ������� ���������� � ���������� ������ ���� x^i.

	static Polynom sumPolynomials(Polynom& n1, Polynom& n2); // ��������� �������� ��������!
	static Polynom defferencePolynomials(Polynom& n1, Polynom& n2); // ��������� ������� ���������!

	friend Polynom operator+(Polynom& n1, Polynom& n2); // �������� �������� ��������!
	friend Polynom operator-(Polynom& n1, Polynom& n2); // �������� �������� ���������!
	friend void reverse�oefficient(Polynom& n); // ������ ������������ � ������� ����� �������!

	void productPolynomials(Polynom& n1, Polynom& n2); // ������������ ����������!
	static void comparisonPolynomials(Polynom& n1, Polynom& n2); // ��������� �����������!
	void polynomialDifferentiation(Polynom& n1); //����������������� ����������!

	int GetDegree() {
		return degree;
	}

	Polynom() {
		inputDegree();
		polynomial�oefficient = new int[degree + 1];
	}
	Polynom(int degree) {
		this->degree = degree;
		polynomial�oefficient = new int[degree + 1];
	}

	Polynom(int d1, int d2) {
		degree = d1 + d2;
		newPolynomials = new int[degree];
	}

	Polynom(Polynom&& other) {
		this->degree = other.degree;
		this->polynomial�oefficient = other.polynomial�oefficient;
		other.degree = 0;
		other.polynomial�oefficient = nullptr;
	}
	// other - ��������� �� ����������/������������ ������ � ������ ������!
	Polynom(Polynom& other) {
		this->degree = other.degree;
		this->polynomial�oefficient = other.polynomial�oefficient;
		other.degree = 0;
		other.polynomial�oefficient = nullptr;
	}// =

	~Polynom() {
		delete[] polynomial�oefficient;
		polynomial�oefficient = nullptr;
	}
};

int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "rus");

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	std::wcout << L"������ ���������!\n";
	Polynom number1;
	number1.input�oefficient();
	std::wcout << number1.outputPolinom();

	std::wcout << L"\n\n������ ���������!\n";
	Polynom number2;
	number2.input�oefficient();
	std::wcout << number2.outputPolinom();

	reverse�oefficient(number1);
	reverse�oefficient(number2);

	std::wcout << L"\n\n������� Enter ��� �����������!\n";
	_getch(); // ����������� �������.

	int variant;
	do {
		MainMenu();
		variant = getVariant(6);


		switch (variant)
		{
		case 1: {
			std::wcout << L"������ ���������!\n";
			reverse�oefficient(number1);
			std::wcout << number1.outputPolinom();
			reverse�oefficient(number1);

			std::wcout << L"\n\n������ ���������!\n";
			reverse�oefficient(number2);
			std::wcout << number2.outputPolinom();
			reverse�oefficient(number2);

			std::wcout << L"\n\n����� ���� �����������!\n";
			//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // ������ ������ ������� ��������
			Polynom number3 = number1 + number2;
			reverse�oefficient(number3);
			std::wcout << number3.outputPolinom();
			std::wcout << "\n\n";
			break;
		}
		case 2: {
			std::wcout << L"������ ���������!\n";
			reverse�oefficient(number1);
			std::wcout << number1.outputPolinom();
			reverse�oefficient(number1);

			std::wcout << L"\n\n������ ���������!\n";
			reverse�oefficient(number2);
			std::wcout << number2.outputPolinom();
			reverse�oefficient(number2);

			std::wcout << L"\n\n�������� ���� �����������!\n";
			//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // ������ ������ ������� ��������
			Polynom number4 = number1 - number2;
			reverse�oefficient(number4);
			std::wcout << number4.outputPolinom();
			std::wcout << L"\n\n";
			break;
		}
		case 3: {
			std::wcout << L"������ ���������!\n";
			reverse�oefficient(number1);
			std::wcout << number1.outputPolinom();
			reverse�oefficient(number1);

			std::wcout << L"\n\n������ ���������!\n";
			reverse�oefficient(number2);
			std::wcout << number2.outputPolinom();
			reverse�oefficient(number2);

			std::wcout << L"\n\n������������: ";
			Polynom number5(number1.GetDegree(), number2.GetDegree());
			number5.productPolynomials(number1, number2);
			reverse�oefficient(number5);
			std::wcout << number5.outputNewPolynomials();
			std::wcout << "\n\n";
			break;
		}
		case 4: {
			std::wcout << L"������ ���������!\n";
			reverse�oefficient(number1);
			std::wcout << number1.outputPolinom();
			reverse�oefficient(number1);

			std::wcout << L"\n\n������ ���������!\n";
			reverse�oefficient(number2);
			std::wcout << number2.outputPolinom();
			reverse�oefficient(number2);

			Polynom::comparisonPolynomials(number1, number2);
			std::wcout << "\n\n";
			break;
		}
		case 5: {
			std::wcout << L"������ ���������!\n";
			reverse�oefficient(number1);
			std::wcout << number1.outputPolinom();
			reverse�oefficient(number1);

			std::wcout << L"\n\n������ ���������!\n";
			reverse�oefficient(number2);
			std::wcout << number2.outputPolinom();
			reverse�oefficient(number2);

			std::wcout << L"\n\n������������������� ����������: \n";
			Polynom number6(number1.GetDegree());
			number6.polynomialDifferentiation(number1);
			reverse�oefficient(number6);
			std::wcout << number6.outputPolinom();
			std::wcout << "\n";
			Polynom number7(number2.GetDegree());
			number7.polynomialDifferentiation(number2);
			reverse�oefficient(number7);
			std::wcout << number7.outputPolinom();
			std::wcout << "\n\n";
			break;
		}
		}
		if (variant != 6) {
			system("pause"); // ����������� ����������, ����� ������������ ��� ������� ��������� ���������� ���������� ������
		}
	} while (variant != 6);

	std::wcout << "\n\n";
	system("pause");
	return 0;
}

void Polynom::inputDegree() {
	std::wcout << L"������� ������������ ������� ����������: ";
	std::wcin >> degree;
}

void Polynom::input�oefficient() {
	for (int i = 0; i < degree + 1; i++) {
		if (i != degree) {
			std::wcout << L"������� ����������� ��� " << degree - i << L" �������: ";
			std::wcin >> polynomial�oefficient[i];
		}
		else {
			std::wcout << L"������� ��������� �������: ";
			std::wcin >> polynomial�oefficient[i];
		}
	}
}

std::wstring Polynom::outputPolinom() {
	// ������� �� ������!
	//std::wstring resultPolinim = L"";
	//std::wcout << L"�������� ��������� ����: ";
	//for (int i = 0; i < degree + 1; i++) {
	//	if (polynomial�oefficient[i] == 0)
	//	{
	//		resultPolinim += L"";
	//	}
	//	else if (polynomial�oefficient[i] == 1 && (degree - i == 0)) {
	//		resultPolinim += L"1";
	//	}
	//	else if (polynomial�oefficient[i] == -1 && (degree - i != 0)) {
	//		resultPolinim += L"-x";
	//		resultPolinim += digitToSuperscript(degree - i);
	//	}
	//	else if (polynomial�oefficient[i] == 1 && (degree - i != 0)) {
	//		resultPolinim += L"x";
	//		resultPolinim += digitToSuperscript(degree - i);
	//	}
	//	else if (polynomial�oefficient[i] == 1 && (degree - i == 1)) {
	//		resultPolinim += L"x";
	//	}
	//	else if (polynomial�oefficient[i] != 1 && (degree - i == 0)) {
	//		resultPolinim += std::to_wstring(polynomial�oefficient[i]);
	//	}
	//	else if (polynomial�oefficient[i] != 1 && (degree - i != 0)) {
	//		resultPolinim += std::to_wstring(polynomial�oefficient[i]);
	//		resultPolinim += L"x";
	//		resultPolinim += digitToSuperscript(degree - i);
	//	}
	//	if (polynomial�oefficient[i + 1] != 0) {
	//		if (polynomial�oefficient[i + 1] >= 0 && i >= 0 && i < degree) {
	//			resultPolinim += L"+";
	//		}
	//		else {
	//			resultPolinim += L"";
	//		}
	//	}
	//}
	//return resultPolinim;
	std::wstring resultPolinim = L"";
	std::wcout << L"�������� ��������� ����: ";
	for (int i = 0; i < degree + 1; i++) {
		if (polynomial�oefficient[i] != 0) {
			if (abs(polynomial�oefficient[i]) != 1 || degree - i == 0) {
				resultPolinim += std::to_wstring(polynomial�oefficient[i]);
			}
			else if (polynomial�oefficient[i] == -1) {
				resultPolinim += L"-";
			}
			if ((degree - i != 0)) {
				resultPolinim += L"x";
				resultPolinim += digitToSuperscript(degree - i);
			}
		}
		if (i != degree && polynomial�oefficient[i + 1] > 0) {
			resultPolinim += L"+";
		}
	}

	return resultPolinim;
}

std::wstring Polynom::varDegree(int i) {
	std::wstring temp;
	if (i == 1) {
		temp = L"x";
	}
	else if (i == 0)
	{
		temp = L"";
	}
	else {
		temp = L"x^" + std::to_wstring(i);
	}
	return temp;
}

std::wstring Polynom::outputNewPolynomials() {
	std::wstring resultPolinim = L"";
	std::wcout << L"�������� ��������� ����: ";
	for (int i = 0; i < degree + 1; i++) {
		if (newPolynomials[i] != 0) {
			if (abs(newPolynomials[i]) != 1 || degree - i == 0) {
				resultPolinim += std::to_wstring(newPolynomials[i]);
			}
			else if (newPolynomials[i] == -1) {
				resultPolinim += L"-";
			}
			if (degree - i != 0) {
				resultPolinim += L"x";
				resultPolinim += digitToSuperscript(degree - i);
			}
		}
		if (i != degree && newPolynomials[i + 1] > 0) {
			resultPolinim += L"+";
		}
	}

	return resultPolinim;
}

Polynom Polynom::sumPolynomials(Polynom& n1, Polynom& n2) { // �� ������������ �������, ����� ��� �����
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] + n2.polynomial�oefficient[i];
		}
	}
	return n3;
}

Polynom Polynom::defferencePolynomials(Polynom& n1, Polynom& n2) { // �� ������������ �������, ����� ��� �����
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] - n2.polynomial�oefficient[i];
		}
	}
	return n3;
}

void Polynom::productPolynomials(Polynom& n1, Polynom& n2) {
	for (int i = 0; i < n1.degree + n2.degree + 1; i++)
	{
		newPolynomials[i] = 0;
	}
	for (int i = 0; i < n1.degree + 1; i++) {
		for (int j = 0; j < n2.degree + 1; j++) {
			newPolynomials[i + j] += n1.polynomial�oefficient[i] * n2.polynomial�oefficient[j];
		}
	}
}

void Polynom::comparisonPolynomials(Polynom& n1, Polynom& n2) {
	int j = 0;
	bool l = true;
	for (int i = 0; i < n1.degree + 1; i++) {
		if (n1.degree == n2.degree) {
			if (n1.polynomial�oefficient[i] == n2.polynomial�oefficient[j]) {
				l = true;
				j++;
			}
			else {
				l = false;
				break;
			}
		}
		else {
			l = false;
			break;
		}
	}
	if (l) {
		std::wcout << L"\n\n���������� �����!\n";
	}
	else {
		std::wcout << L"\n\n���������� �� �����!\n";
	}
}

void Polynom::polynomialDifferentiation(Polynom& n1) {
	for (int i = 0; i < n1.degree + 1; i++) {
		polynomial�oefficient[i] = 0;
	}
	for (int i = 0; i < n1.degree + 1; i++) {
		polynomial�oefficient[i] = i * n1.polynomial�oefficient[i];
	}
	for (int i = 0; i < n1.degree; i++) {
		polynomial�oefficient[i] = polynomial�oefficient[i + 1];
	}
	degree--;
}


Polynom operator+(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++) {
		n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] + n2.polynomial�oefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree > n2.degree) {
			n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i];
		}
		else {
			n3.polynomial�oefficient[i] = n2.polynomial�oefficient[i];
		}
	}

	return n3;
}

Polynom operator-(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++) {

		n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] - n2.polynomial�oefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++) {

		if (n1.degree > n2.degree) {
			n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i];
		}
		else {
			n3.polynomial�oefficient[i] = -n2.polynomial�oefficient[i];
		}
	}

	return n3;
}

void reverse�oefficient(Polynom& n)
{
	if (n.polynomial�oefficient != nullptr) {
		std::reverse((n.polynomial�oefficient), (n.polynomial�oefficient + n.degree + 1));
	}
	else if (n.newPolynomials != nullptr) {
		std::reverse((n.newPolynomials), (n.newPolynomials + n.degree + 1));
	}
}

void MainMenu() {
	system("cls"); // ������� �����
	std::wcout << L"\n�������� �������� ��� ������������: \n";
	std::wcout << L"1. ������� ����������.\n";
	std::wcout << L"2. ������� ����������.\n";
	std::wcout << L"3. ����������� ����������.\n";
	std::wcout << L"4. �������� ����������.\n";
	std::wcout << L"5. ������������������� ����������.\n";
	std::wcout << L"6. ����� �� ����.\n";
}

int getVariant(int count) {
	int variant;
	std::wstring str; // ������ ��� ���������� �������� ������
	std::wcin >> str; // ��������� ������

	// ���� ���� �����������, �������� �� ���� � ������ ��������� ���
	variant = std::stoi(str); // string to integer!
	while (variant < 1 || variant > count) {
		std::wcout << L"������!\n����� �������� ���!\n�������� ������ ��������!\n"; // ������� ��������� �� ������
		std::wcin >> str; // ��������� ������ ��������
		variant = std::stoi(str);
	}

	return variant;
}

wchar_t digitToSuperscript(unsigned int digit) {
	char s = '\0';
	switch (digit) {
	case 0:
		return s;
	case 1:
		return s;
	case 2:
		return 0x00B2;
	case 3:
		return 0x00B3;
	case 10:
		return 0x00B2 + s;
	default:
		return 0x2070 + digit;
	}
}