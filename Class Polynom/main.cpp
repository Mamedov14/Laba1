#include <iostream>
#include <string>

void MainMenu();
int getVariant(int count);

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

	void productPolynomials(Polynom& n1, Polynom& n2); // ïğîèçâåäåíèå ìíîãîëåíîâ!
	static void comparisonPolynomials(Polynom& n1, Polynom& n2); // ñğàâíåíèå ìíîãî÷ëåíîâ!
	void polynomialDifferentiation(Polynom& n1); //äèôôåğåíöèğîâàíèå ìíîãî÷ëåíà!


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

	int variant;
	do {
		MainMenu();
		variant = getVariant(6);
		switch (variant)
		{
		case 1: {
			std::cout << "Ïåğâûé ìíîãî÷ëåí!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\nÂòîğîé ìíîãî÷ëåí!\n";
			std::cout << number2.outputPolinom();
			reverseÑoefficient(number1);
			reverseÑoefficient(number2);

			std::cout << "\n\nÑóììà äâóõ ìíîãî÷ëåíîâ!\n";
			//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // âòîğîé ñïîñîá ñëîæèòü ïîëèíîìû
			Polynom number3 = number1 + number2;
			reverseÑoefficient(number3);
			std::cout << number3.outputPolinom();
			std::cout << "\n\n";
			break;
		}
		case 2: {
			std::cout << "Ïåğâûé ìíîãî÷ëåí!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\nÂòîğîé ìíîãî÷ëåí!\n";
			std::cout << number2.outputPolinom();
			reverseÑoefficient(number1);
			reverseÑoefficient(number2);

			std::cout << "\n\nĞàçíîñòü äâóõ ìíîãî÷ëåíîâ!\n";
			//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // âòîğîé ñïîñîá âû÷åñòü ïîëèíîìû
			Polynom number4 = number1 - number2;
			reverseÑoefficient(number4);
			std::cout << number4.outputPolinom();
			std::cout << "\n\n";
			break;
		}
		case 3: {
			std::cout << "Ïåğâûé ìíîãî÷ëåí!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\nÂòîğîé ìíîãî÷ëåí!\n";
			std::cout << number2.outputPolinom();
			reverseÑoefficient(number1);
			reverseÑoefficient(number2);

			Polynom number5(number1.GetDegree(), number2.GetDegree());
			number5.productPolynomials(number1, number2);
			reverseÑoefficient(number5);
			std::cout << number5.outputNewPolynomials();
			std::cout << "\n\n";
			break;
		}
		case 4: {
			std::cout << "Ïåğâûé ìíîãî÷ëåí!\n";
			std::cout << number1.outputPolinom();
			std::cout << "\n\nÂòîğîé ìíîãî÷ëåí!\n";
			std::cout << number2.outputPolinom();
			reverseÑoefficient(number1);
			reverseÑoefficient(number2);

			Polynom::comparisonPolynomials(number1, number2);
			std::cout << "\n\n";
			break;
		}
		case 5: {
			std::cout << "Ïåğâûé ìíîãî÷ëåí!\n";
			std::cout << number1.outputPolinom();
			reverseÑoefficient(number1);

			std::cout << "\n\nÏğîäèôôåğåíöèğîâàëè ìíîãî÷ëåí: \n";
			Polynom number6(number1.GetDegree());
			number6.polynomialDifferentiation(number1);
			reverseÑoefficient(number6);
			std::cout << number6.outputPolinom();
			std::cout << "\n\n";
			break;
		}
		}
		if (variant != 6) {
			system("pause"); // çàäåğæèâàåì âûïîëíåíèå, ÷òîáû ïîëüçîâàòåëü ìîã óâèäåòü ğåçóëüòàò âûïîëíåíèÿ âûáğàííîãî ïóíêòà
		}
	} while (variant != 6);

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
		if (polynomialÑoefficient[i] != 1) {
			resultPolinim += std::to_string(polynomialÑoefficient[i]) + varDegree(degree - i);
		}
		else {
			if (polynomialÑoefficient[i] == 1 && (degree - i == 0)) {
				resultPolinim += "1";
			}
			else {
				resultPolinim += varDegree(degree - i);
			}
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
	std::cout << "\n\nÏğîèçâåäåíèå ìíîãî÷ëåíîâ: ";
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

void Polynom::comparisonPolynomials(Polynom& n1, Polynom& n2) {
	int j = 0;
	bool l = true;
	for (int i = 0; i < n1.degree + 1; i++) {
		if (n1.degree == n2.degree) {
			if (n1.polynomialÑoefficient[i] == n2.polynomialÑoefficient[j]) {
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
		std::cout << "\n\nÌíîãî÷ëåíû ğàâíû!\n";
	}
	else {
		std::cout << "\n\nÌíîãî÷ëåíû íå ğàâíû!\n";
	}
}

void Polynom::polynomialDifferentiation(Polynom& n1) {
	for (int i = 0; i < n1.degree + 1; i++) {

		polynomialÑoefficient[i] = 0;
	}
	for (int i = 0; i < n1.degree + 1; i++) {

		polynomialÑoefficient[i] = i * n1.polynomialÑoefficient[i];
	}
	for (int i = 0; i < n1.degree; i++) {

		polynomialÑoefficient[i] = polynomialÑoefficient[i + 1];
	}
	degree--;
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

void MainMenu() {
	system("cls"); // î÷èùàåì ıêğàí
	std::cout << "\nÂûáåğåòè îïåğàöèş íàä ìíîãî÷ëåíàìè: \n";
	std::cout << "1. Ñëîæèòü ìíîãî÷ëåíû.\n";
	std::cout << "2. Âû÷åñòü ìíîãî÷ëåíû.\n";
	std::cout << "3. Ïåğåìíîæèòü ìíîãî÷ëåíû.\n";
	std::cout << "4. Ñğàâíèòü ìíîãî÷ëåíû.\n";
	std::cout << "5. Ïğîäèôôåğåíöèğîâàòü ìíîãî÷ëåíû.\n";
	std::cout << "6. Âûõîä èç ìåíş.\n";
}

int getVariant(int count) {
	int variant;
	std::string str; // ñòğîêà äëÿ ñ÷èòûâàíèÿ ââåä¸ííûõ äàííûõ
	std::cin >> str; // ñ÷èòûâàåì ñòğîêó

	// ïîêà ââîä íåêîğğåêòåí, ñîîáùàåì îá ıòîì è ïğîñèì ïîâòîğèòü åãî
	variant = std::stoi(str); // string to integer!
	while (variant < 1 || variant > count) {
		std::cout << "Îøáèêà!\nÒàêîé îïåğàöèè íåò!\nÂûáåğåòå äğóãóş îïåğàöèş!\n"; // âûâîäèì ñîîáùåíèå îá îøèáêå
		std::cin >> str; // ñ÷èòûâàåì ñòğîêó ïîâòîğíî
		variant = std::stoi(str);
	}

	return variant;
}
