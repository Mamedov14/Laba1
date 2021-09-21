// ñğàâíåíèå è äèôôåğåíöèğîâàíèå!

#include <iostream>
#include <string>

class Polynom {
private:
	int degree = 0;                                       // ìàêñèìàëüíàÿ ñòåïåíü ìíîãî÷ëåíà .
	// int* polynomialÑoefficient = new int[degree + 1]; // êîıôôèöåíòû ìíîãî÷ëåíà, êîòîğûå áóäóò õğàíèòüñÿ â ìàññèâå.
	int* polynomialÑoefficient = nullptr;
	int* newPolynomials = nullptr;
public:
	void inputDegree();         // çàïğàùèâàåò ìàêñèìàëüíóş ñòåïåíü ìíîãî÷ëåíà.
	void inputÑoefficient();    // çàïğàøèâàåò âñå êîıôôèöèåíòû ìíîãî÷ëåíà.
	std::string outputPolinom();    //âûâîäèò ââåäåííûé ìíîãî÷ëåí.
	std::string outputNewPolynomials();    //âûâîäèò íîâûé ìíîãî÷ëåí.
	std::string varDegree(int i); // ïğèíèìàåò ñòåïåíü ìíîãî÷ëåíà è âîçâğàùàåò ñòğîêó òèïà x^i.

	static Polynom sumPolynomials(Polynom& n1, Polynom& n2); // îòäåëüíàÿ îïåğàöèÿ ñëîæåíèÿ!
	static Polynom defferencePolynomials(Polynom& n1, Polynom& n2); // îòäåëüíàÿ ôóíêöèÿ âû÷èòàíèÿ!

	friend Polynom operator+(Polynom& n1, Polynom& n2); // áèíàğíàÿ îïåğàöèÿ ñëîæåíèÿ!
	friend Polynom operator-(Polynom& n1, Polynom& n2); // áèíàğíàÿ îïåğàöèÿ âû÷èòàíèÿ!
	friend void reverseÑoefficient(Polynom& n); // ìåíÿåò êîıôôèöèåíòû â ìàññèâå çàäîì íàïåğåä!

	void productPolynomials(Polynom& n1, Polynom& n2);

	int GetDegree() {
		return degree;
	}

	Polynom() {
		inputDegree();
		polynomialÑoefficient = new int[degree + 1];
	}
	Polynom(int degree) {
		this->degree = degree;
		polynomialÑoefficient = new int[degree + 1];
	}

	Polynom(int d1, int d2) {
		degree = d1 + d2;
		newPolynomials = new int[degree];
	}

	Polynom(Polynom&& other) {
		this->degree = other.degree;
		this->polynomialÑoefficient = other.polynomialÑoefficient;
		other.degree = 0;
		other.polynomialÑoefficient = nullptr;
	}
	// other - óêàçûâàåò íà êîïèğóåìûé/ïåğåìåùàåìûé îáúåêò â äğóãîé îáúåêò!
	Polynom(Polynom& other) {
		this->degree = other.degree;
		this->polynomialÑoefficient = other.polynomialÑoefficient;
		other.degree = 0;
		other.polynomialÑoefficient = nullptr;
	}// =

	~Polynom() {
		delete[] polynomialÑoefficient;
		polynomialÑoefficient = nullptr;
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	std::cout << "Ïåğâûé ìíîãî÷ëåí!\n";
	Polynom number1;
	number1.inputÑoefficient();
	std::cout << number1.outputPolinom();

	std::cout << "\n\nÂòîğîé ìíîãî÷ëåí!\n";
	Polynom number2;
	number2.inputÑoefficient();
	std::cout << number2.outputPolinom();

	reverseÑoefficient(number1);
	reverseÑoefficient(number2);

	std::cout << "\n\nÑóììà äâóõ ìíîãî÷ëåíîâ!\n";
	//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // âòîğîé ñïîñîá ñëîæèòü ïîëèíîìû
	Polynom number3 = number1 + number2;
	reverseÑoefficient(number3);
	std::cout << number3.outputPolinom();

	std::cout << "\n\nĞàçíîñòü äâóõ ìíîãî÷ëåíîâ!\n";
	//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // âòîğîé ñïîñîá âû÷åñòü ïîëèíîìû
	Polynom number4 = number1 - number2;
	reverseÑoefficient(number4);
	std::cout << number4.outputPolinom();

	Polynom number5(number1.GetDegree(), number2.GetDegree());
	number5.productPolynomials(number1, number2);
	reverseÑoefficient(number5);
	std::cout << number5.outputNewPolynomials();

	std::cout << "\n\n";
	system("pause");
	return 0;
}

void Polynom::inputDegree() {
	std::cout << "Ââåäèòå ìàêñèìàëüíóş ñòåïåíü ìíîãî÷ëåíà: ";
	std::cin >> degree;
}

void Polynom::inputÑoefficient() {
	for (int i = 0; i < degree + 1; i++) {
		if (i == 0) {
			std::cout << "Ââåäèòå êîıôôèöèåíò ïğè ìàêñèìàëüíîé ñòåïåíè: ";
			std::cin >> polynomialÑoefficient[i];
			std::cout << "Ïğîäîëæàéòå ââîäèòü êîıôôèöèåíòû ïîñëåäîâàòåëüíî:\n";
		}
		else if (i == degree) {
			std::cout << "Ââåäèòå ñâîáîäíûé ıëåìåíò ìíîãî÷ëåíà: ";
			std::cin >> polynomialÑoefficient[degree];
		}
		else {
			std::cin >> polynomialÑoefficient[i];
		}
	}
}

std::string Polynom::outputPolinom() {
	std::string resultPolinim = "";
	std::cout << "Ïîëó÷èëè ìíîãî÷ëåí âèäà: ";
	for (int i = 0; i < degree + 1; i++) {
		if (i != degree) {
			resultPolinim += std::to_string(polynomialÑoefficient[i]) + varDegree(degree - i);
		}
		else {
			resultPolinim += std::to_string(polynomialÑoefficient[i]);
		}
		if (polynomialÑoefficient[i + 1] >= 0 && i >= 0 && i < degree) {
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

std::string Polynom::outputNewPolynomials()
{
	std::string resultPolinim = "";
	std::cout << "\n\nÏğîèçâåäåíèå ìíîãî÷ëåíîâ: ";
	for (int i = 0; i < degree + 1; i++) {
		if (i != degree) {
			resultPolinim += std::to_string(newPolynomials[i]) + varDegree(degree - i);
		}
		else {
			resultPolinim += std::to_string(newPolynomials[i]);

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

Polynom Polynom::sumPolynomials(Polynom& n1, Polynom& n2) { // íå îáÿçàòåëüíàÿ ôóíêöèÿ, ÷èñòî äëÿ îïûòà
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i] + n2.polynomialÑoefficient[i];
		}
	}
	return n3;
}

Polynom Polynom::defferencePolynomials(Polynom& n1, Polynom& n2) { // íå îáÿçàòåëüíàÿ ôóíêöèÿ, ÷èñòî äëÿ îïûòà
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i] - n2.polynomialÑoefficient[i];
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
			newPolynomials[i + j] += n1.polynomialÑoefficient[i] * n2.polynomialÑoefficient[j];
		}
	}
}

Polynom operator+(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++)
	{
		n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i] + n2.polynomialÑoefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++)
	{
		if (n1.degree > n2.degree) {
			n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i];
		}
		else {
			n3.polynomialÑoefficient[i] = n2.polynomialÑoefficient[i];
		}
	}
	return n3;
}

Polynom operator-(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++)
	{
		n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i] - n2.polynomialÑoefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++)
	{
		if (n1.degree > n2.degree) {
			n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i];
		}
		else {
			n3.polynomialÑoefficient[i] = -n2.polynomialÑoefficient[i];
		}
	}

	return n3;
}

void reverseÑoefficient(Polynom& n)
{
	if (n.polynomialÑoefficient != nullptr) {
		std::reverse((n.polynomialÑoefficient), (n.polynomialÑoefficient + n.degree + 1));
	}
	else if (n.newPolynomials != nullptr) {
		std::reverse((n.newPolynomials), (n.newPolynomials + n.degree + 1));
	}

}
