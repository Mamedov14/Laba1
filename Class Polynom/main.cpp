#include <iostream>
#include <string>

class Polynom {
private:
	int degree = 0;                                       // ������������ ������� ���������� .
	// int* polynomial�oefficient = new int[degree + 1]; // ����������� ����������, ������� ����� ��������� � �������.
	int* polynomial�oefficient = nullptr;

public:
	void inputDegree();         // ����������� ������������ ������� ����������.
	void input�oefficient();    // ����������� ��� ������������ ����������.
	std::string outputPolinom();    //������� ��������� ���������.
	std::string varDegree(int i); // ��������� ������� ���������� � ���������� ������ ���� x^i.

	static Polynom sumPolynomials(Polynom& n1, Polynom& n2); // ��������� �������� ��������!
	static Polynom defferencePolynomials(Polynom& n1, Polynom& n2); // ��������� ������� ���������!

	friend Polynom operator+(Polynom& n1, Polynom& n2); // �������� �������� ��������!
	friend Polynom operator-(Polynom& n1, Polynom& n2); // �������� �������� ���������!

	Polynom() {
		inputDegree();
		polynomial�oefficient = new int[degree + 1];
	}
	Polynom(int degree) {
		polynomial�oefficient = new int[degree + 1];
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
	//number1.inputDegree();
	number1.input�oefficient();
	std::cout << number1.outputPolinom();

	std::cout << "\n\n������ ���������!\n";
	Polynom number2;
	//number2.inputDegree();
	number2.input�oefficient();
	std::cout << number2.outputPolinom();

	std::cout << "\n\n����� ���� �����������!\n";
	//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // ������ ������ ������� ��������
	Polynom number3 = number1 + number2;
	std::cout << number3.outputPolinom();

	std::cout << "\n\n�������� ���� �����������!\n";
	//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // ������ ������ ������� ��������
	Polynom number4 = number1 - number2;
	std::cout << number4.outputPolinom();

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
		if (i != degree) {
			resultPolinim += std::to_string(polynomial�oefficient[i]) + varDegree(degree - i);
		}
		else {
			resultPolinim += std::to_string(polynomial�oefficient[i]);

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
	std::string temp = "x^" + std::to_string(i);
	return temp;
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

Polynom operator+(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] + n2.polynomial�oefficient[i];
		}
	}
	return n3;
}

Polynom operator-(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial�oefficient[i] = n1.polynomial�oefficient[i] - n2.polynomial�oefficient[i];
		}
	}
	return n3;
}
