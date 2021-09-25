#include <iostream>
#include <string>

void MainMenu();
int getVariant(int count);

class Polynom {

private:
	int degree = 0;                                       // ������������ ������� ���������� .
	// int* polynomial�oefficient = new int[degree + 1]; // ����������� ����������, ������� ����� ��������� � �������.
	int* polynomial�oefficient = nullptr;
	int* newPolynomials = nullptr;

public:
	void inputDegree();         // ����������� ������������ ������� ����������.
	void input�oefficient();    // ����������� ��� ������������ ����������.
	std::string outputPolinom();    //������� ��������� ���������.
	std::string outputNewPolynomials();    //������� ����� ���������.
	std::string varDegree(int i); // ��������� ������� ���������� � ���������� ������ ���� x^i.

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

int main() {
	setlocale(LC_ALL, "rus");

	std::cout << "������ ���������!\n";
	Polynom number1;
	number1.input�oefficient();
	std::cout << number1.outputPolinom();

	std::cout << "\n\n������ ���������!\n";
	Polynom number2;
	number2.input�oefficient();
	std::cout << number2.outputPolinom();

	int variant;
	do {
		MainMenu();
		variant = getVariant(6);
		switch (variant)
		{
		case 1: {
			std::cout << "������ ���������!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\n������ ���������!\n";
			std::cout << number2.outputPolinom();
			reverse�oefficient(number1);
			reverse�oefficient(number2);

			std::cout << "\n\n����� ���� �����������!\n";
			//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // ������ ������ ������� ��������
			Polynom number3 = number1 + number2;
			reverse�oefficient(number3);
			std::cout << number3.outputPolinom();
			std::cout << "\n\n";
			break;
		}
		case 2: {
			std::cout << "������ ���������!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\n������ ���������!\n";
			std::cout << number2.outputPolinom();
			reverse�oefficient(number1);
			reverse�oefficient(number2);

			std::cout << "\n\n�������� ���� �����������!\n";
			//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // ������ ������ ������� ��������
			Polynom number4 = number1 - number2;
			reverse�oefficient(number4);
			std::cout << number4.outputPolinom();
			std::cout << "\n\n";
			break;
		}
		case 3: {
			std::cout << "������ ���������!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\n������ ���������!\n";
			std::cout << number2.outputPolinom();
			reverse�oefficient(number1);
			reverse�oefficient(number2);

			Polynom number5(number1.GetDegree(), number2.GetDegree());
			number5.productPolynomials(number1, number2);
			reverse�oefficient(number5);
			std::cout << number5.outputNewPolynomials();
			std::cout << "\n\n";
			break;
		}
		case 4: {
			std::cout << "������ ���������!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\n������ ���������!\n";
			std::cout << number2.outputPolinom();
			reverse�oefficient(number1);
			reverse�oefficient(number2);

			Polynom::comparisonPolynomials(number1, number2);
			std::cout << "\n\n";
			break;
		}
		case 5: {
			std::cout << "������ ���������!\n";
			std::cout << number1.outputPolinom();
			reverse�oefficient(number1);

			std::cout << "\n\n������������������� ���������: \n";
			Polynom number6(number1.GetDegree());
			number6.polynomialDifferentiation(number1);
			reverse�oefficient(number6);
			std::cout << number6.outputPolinom();
			std::cout << "\n\n";
			break;
		}
		}
		if (variant != 6) {
			system("pause"); // ����������� ����������, ����� ������������ ��� ������� ��������� ���������� ���������� ������
		}
	} while (variant != 6);

	std::cout << "\n\n";
	system("pause");
	return 0;
}

void Polynom::inputDegree() {
	std::cout << "������� ������������ ������� ����������: ";
	std::cin >> degree;
}

void Polynom::input�oefficient() {
	for (int i = 0; i < degree + 1; i++) {
		if (i == 0) {
			std::cout << "������� ����������� ��� ������������ �������: ";
			std::cin >> polynomial�oefficient[i];
			std::cout << "����������� ������� ������������ ���������������:\n";
		}
		else if (i == degree) {
			std::cout << "������� ��������� ������� ����������: ";
			std::cin >> polynomial�oefficient[degree];
		}
		else {
			std::cin >> polynomial�oefficient[i];
		}
	}
}

std::string Polynom::outputPolinom() {
	std::string resultPolinim = "";
	std::cout << "�������� ��������� ����: ";
	for (int i = 0; i < degree + 1; i++) {
		if (polynomial�oefficient[i] != 1) {
			resultPolinim += std::to_string(polynomial�oefficient[i]) + varDegree(degree - i);
		}
		else {
			if (polynomial�oefficient[i] == 1 && (degree - i == 0)) {
				resultPolinim += "1";
			}
			else {
				resultPolinim += varDegree(degree - i);
			}
		}
		if (polynomial�oefficient[i + 1] >= 0 && i >= 0 && i < degree) {
			resultPolinim += ("+");
		}
		else {
			resultPolinim += ("");
		}
	}
	return resultPolinim;
}

std::string Polynom::varDegree(int i) {
	std::string temp;
	if (i == 1) {
		temp = "x";
	}
	else if (i == 0)
	{
		temp = "";
	}
	else {
		temp = "x^" + std::to_string(i);
	}
	return temp;
}

std::string Polynom::outputNewPolynomials()
{
	std::string resultPolinim = "";
	std::cout << "\n\n������������ �����������: ";
	for (int i = 0; i < degree + 1; i++) {
		if (newPolynomials[i] != 1) {
			resultPolinim += std::to_string(newPolynomials[i]) + varDegree(degree - i);
		}
		else {
			if (newPolynomials[i] == 1 && (degree - i == 0)) {
				resultPolinim += "1";
			}
			else {
				resultPolinim += varDegree(degree - i);
			}
		}
		if (newPolynomials[i + 1] >= 0 && i >= 0 && i < degree) {
			resultPolinim += ("+");
		}
		else {
			resultPolinim += ("");
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
		std::cout << "\n\n���������� �����!\n";
	}
	else {
		std::cout << "\n\n���������� �� �����!\n";
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
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++)
	{
		n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] + n2.polynomial�oefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++)
	{
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
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++)
	{
		n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] - n2.polynomial�oefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++)
	{
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
	std::cout << "\n�������� �������� ��� ������������: \n";
	std::cout << "1. ������� ����������.\n";
	std::cout << "2. ������� ����������.\n";
	std::cout << "3. ����������� ����������.\n";
	std::cout << "4. �������� ����������.\n";
	std::cout << "5. ������������������� ����������.\n";
	std::cout << "6. ����� �� ����.\n";
}

int getVariant(int count) {
	int variant;
	std::string str; // ������ ��� ���������� �������� ������
	std::cin >> str; // ��������� ������

	// ���� ���� �����������, �������� �� ���� � ������ ��������� ���
	variant = std::stoi(str); // string to integer!
	while (variant < 1 || variant > count) {
		std::cout << "������!\n����� �������� ���!\n�������� ������ ��������!\n"; // ������� ��������� �� ������
		std::cin >> str; // ��������� ������ ��������
		variant = std::stoi(str);
	}

	return variant;
}
