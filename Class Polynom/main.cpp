#include <iostream>
#include <string>
// äëÿ ñòåïåíåé!
#include <io.h>
#include <fcntl.h>
#include <stdexcept>
// äëÿ îñòàíîâêè êîíñîëè!
#include <conio.h> 

void MainMenu();
int getVariant(int count);
wchar_t digitToSuperscript(unsigned int digit);


class Polynom {

private:
	int degree = 0;                                       // ìàêñèìàëüíàÿ ñòåïåíü ìíîãî÷ëåíà .
	// int* polynomialÑoefficient = new int[degree + 1]; // êîıôôèöåíòû ìíîãî÷ëåíà, êîòîğûå áóäóò õğàíèòüñÿ â ìàññèâå.
	int* polynomialÑoefficient = nullptr;
	int* newPolynomials = nullptr;

public:
	void inputDegree();         // çàïğàùèâàåò ìàêñèìàëüíóş ñòåïåíü ìíîãî÷ëåíà.
	void inputÑoefficient();    // çàïğàøèâàåò âñå êîıôôèöèåíòû ìíîãî÷ëåíà.
	std::wstring outputPolinom();    //âûâîäèò ââåäåííûé ìíîãî÷ëåí.
	std::wstring outputNewPolynomials();    //âûâîäèò íîâûé ìíîãî÷ëåí.
	std::wstring varDegree(int i); // ïğèíèìàåò ñòåïåíü ìíîãî÷ëåíà è âîçâğàùàåò ñòğîêó òèïà x^i.

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

int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "rus");

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	std::wcout << L"Ïåğâûé ìíîãî÷ëåí!\n";
	Polynom number1;
	number1.inputÑoefficient();
	std::wcout << number1.outputPolinom();

	std::wcout << L"\n\nÂòîğîé ìíîãî÷ëåí!\n";
	Polynom number2;
	number2.inputÑoefficient();
	std::wcout << number2.outputPolinom();

	reverseÑoefficient(number1);
	reverseÑoefficient(number2);

	std::wcout << L"\n\nÍàæìèòå Enter äëÿ ïğîäîëæåíèÿ!\n";
	_getch(); // Ñîâğåìåííûé âàğèàíò.

	int variant;
	do {
		MainMenu();
		variant = getVariant(6);


		switch (variant)
		{
		case 1: {
			std::wcout << L"Ïåğâûé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number1);
			std::wcout << number1.outputPolinom();
			reverseÑoefficient(number1);

			std::wcout << L"\n\nÂòîğîé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number2);
			std::wcout << number2.outputPolinom();
			reverseÑoefficient(number2);

			std::wcout << L"\n\nÑóììà äâóõ ìíîãî÷ëåíîâ!\n";
			//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // âòîğîé ñïîñîá ñëîæèòü ïîëèíîìû
			Polynom number3 = number1 + number2;
			reverseÑoefficient(number3);
			std::wcout << number3.outputPolinom();
			std::wcout << "\n\n";
			break;
		}
		case 2: {
			std::wcout << L"Ïåğâûé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number1);
			std::wcout << number1.outputPolinom();
			reverseÑoefficient(number1);

			std::wcout << L"\n\nÂòîğîé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number2);
			std::wcout << number2.outputPolinom();
			reverseÑoefficient(number2);

			std::wcout << L"\n\nĞàçíîñòü äâóõ ìíîãî÷ëåíîâ!\n";
			//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // âòîğîé ñïîñîá âû÷åñòü ïîëèíîìû
			Polynom number4 = number1 - number2;
			reverseÑoefficient(number4);
			std::wcout << number4.outputPolinom();
			std::wcout << L"\n\n";
			break;
		}
		case 3: {
			std::wcout << L"Ïåğâûé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number1);
			std::wcout << number1.outputPolinom();
			reverseÑoefficient(number1);

			std::wcout << L"\n\nÂòîğîé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number2);
			std::wcout << number2.outputPolinom();
			reverseÑoefficient(number2);

			std::wcout << L"\n\nÏğîèçâåäåíèå: ";
			Polynom number5(number1.GetDegree(), number2.GetDegree());
			number5.productPolynomials(number1, number2);
			reverseÑoefficient(number5);
			std::wcout << number5.outputNewPolynomials();
			std::wcout << "\n\n";
			break;
		}
		case 4: {
			std::wcout << L"Ïåğâûé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number1);
			std::wcout << number1.outputPolinom();
			reverseÑoefficient(number1);

			std::wcout << L"\n\nÂòîğîé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number2);
			std::wcout << number2.outputPolinom();
			reverseÑoefficient(number2);

			Polynom::comparisonPolynomials(number1, number2);
			std::wcout << "\n\n";
			break;
		}
		case 5: {
			std::wcout << L"Ïåğâûé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number1);
			std::wcout << number1.outputPolinom();
			reverseÑoefficient(number1);

			std::wcout << L"\n\nÂòîğîé ìíîãî÷ëåí!\n";
			reverseÑoefficient(number2);
			std::wcout << number2.outputPolinom();
			reverseÑoefficient(number2);

			std::wcout << L"\n\nÏğîäèôôåğåíöèğîâàëè ìíîãî÷ëåíû: \n";
			Polynom number6(number1.GetDegree());
			number6.polynomialDifferentiation(number1);
			reverseÑoefficient(number6);
			std::wcout << number6.outputPolinom();
			std::wcout << "\n";
			Polynom number7(number2.GetDegree());
			number7.polynomialDifferentiation(number2);
			reverseÑoefficient(number7);
			std::wcout << number7.outputPolinom();
			std::wcout << "\n\n";
			break;
		}
		}
		if (variant != 6) {
			system("pause"); // çàäåğæèâàåì âûïîëíåíèå, ÷òîáû ïîëüçîâàòåëü ìîã óâèäåòü ğåçóëüòàò âûïîëíåíèÿ âûáğàííîãî ïóíêòà
		}
	} while (variant != 6);

	std::wcout << "\n\n";
	system("pause");
	return 0;
}

void Polynom::inputDegree() {
	std::wcout << L"Ââåäèòå ìàêñèìàëüíóş ñòåïåíü ìíîãî÷ëåíà: ";
	std::wcin >> degree;
}

void Polynom::inputÑoefficient() {
	for (int i = 0; i < degree + 1; i++) {
		if (i != degree) {
			std::wcout << L"Ââåäèòå êîıôôèöèåíò ïğè " << degree - i << L" ñòåïåíè: ";
			std::wcin >> polynomialÑoefficient[i];
		}
		else {
			std::wcout << L"Ââåäèòå ñâîáîäíûé ıëåìåíò: ";
			std::wcin >> polynomialÑoefficient[i];
		}
	}
}

std::wstring Polynom::outputPolinom() {
	// ÎÑÒÀÂÈË ÍÀ ÏÀÌßÒÜ!
	//std::wstring resultPolinim = L"";
	//std::wcout << L"Ïîëó÷èëè ìíîãî÷ëåí âèäà: ";
	//for (int i = 0; i < degree + 1; i++) {
	//	if (polynomialÑoefficient[i] == 0)
	//	{
	//		resultPolinim += L"";
	//	}
	//	else if (polynomialÑoefficient[i] == 1 && (degree - i == 0)) {
	//		resultPolinim += L"1";
	//	}
	//	else if (polynomialÑoefficient[i] == -1 && (degree - i != 0)) {
	//		resultPolinim += L"-x";
	//		resultPolinim += digitToSuperscript(degree - i);
	//	}
	//	else if (polynomialÑoefficient[i] == 1 && (degree - i != 0)) {
	//		resultPolinim += L"x";
	//		resultPolinim += digitToSuperscript(degree - i);
	//	}
	//	else if (polynomialÑoefficient[i] == 1 && (degree - i == 1)) {
	//		resultPolinim += L"x";
	//	}
	//	else if (polynomialÑoefficient[i] != 1 && (degree - i == 0)) {
	//		resultPolinim += std::to_wstring(polynomialÑoefficient[i]);
	//	}
	//	else if (polynomialÑoefficient[i] != 1 && (degree - i != 0)) {
	//		resultPolinim += std::to_wstring(polynomialÑoefficient[i]);
	//		resultPolinim += L"x";
	//		resultPolinim += digitToSuperscript(degree - i);
	//	}
	//	if (polynomialÑoefficient[i + 1] != 0) {
	//		if (polynomialÑoefficient[i + 1] >= 0 && i >= 0 && i < degree) {
	//			resultPolinim += L"+";
	//		}
	//		else {
	//			resultPolinim += L"";
	//		}
	//	}
	//}
	//return resultPolinim;
	std::wstring resultPolinim = L"";
	std::wcout << L"Ïîëó÷èëè ìíîãî÷ëåí âèäà: ";
	for (int i = 0; i < degree + 1; i++) {
		if (polynomialÑoefficient[i] != 0) {
			if (abs(polynomialÑoefficient[i]) != 1 || degree - i == 0) {
				resultPolinim += std::to_wstring(polynomialÑoefficient[i]);
			}
			else if (polynomialÑoefficient[i] == -1) {
				resultPolinim += L"-";
			}
			if ((degree - i != 0)) {
				resultPolinim += L"x";
				resultPolinim += digitToSuperscript(degree - i);
			}
		}
		if (i != degree && polynomialÑoefficient[i + 1] > 0) {
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
	std::wcout << L"Ïîëó÷èëè ìíîãî÷ëåí âèäà: ";
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
		std::wcout << L"\n\nÌíîãî÷ëåíû ğàâíû!\n";
	}
	else {
		std::wcout << L"\n\nÌíîãî÷ëåíû íå ğàâíû!\n";
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
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++) {
		n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i] + n2.polynomialÑoefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++) {
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
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++) {

		n3.polynomialÑoefficient[i] = n1.polynomialÑoefficient[i] - n2.polynomialÑoefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++) {

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
	std::wcout << L"\nÂûáåğåòè îïåğàöèş íàä ìíîãî÷ëåíàìè: \n";
	std::wcout << L"1. Ñëîæèòü ìíîãî÷ëåíû.\n";
	std::wcout << L"2. Âû÷åñòü ìíîãî÷ëåíû.\n";
	std::wcout << L"3. Ïåğåìíîæèòü ìíîãî÷ëåíû.\n";
	std::wcout << L"4. Ñğàâíèòü ìíîãî÷ëåíû.\n";
	std::wcout << L"5. Ïğîäèôôåğåíöèğîâàòü ìíîãî÷ëåíû.\n";
	std::wcout << L"6. Âûõîä èç ìåíş.\n";
}

int getVariant(int count) {
	int variant;
	std::wstring str; // ñòğîêà äëÿ ñ÷èòûâàíèÿ ââåä¸ííûõ äàííûõ
	std::wcin >> str; // ñ÷èòûâàåì ñòğîêó

	// ïîêà ââîä íåêîğğåêòåí, ñîîáùàåì îá ıòîì è ïğîñèì ïîâòîğèòü åãî
	variant = std::stoi(str); // string to integer!
	while (variant < 1 || variant > count) {
		std::wcout << L"Îøáèêà!\nÒàêîé îïåğàöèè íåò!\nÂûáåğåòå äğóãóş îïåğàöèş!\n"; // âûâîäèì ñîîáùåíèå îá îøèáêå
		std::wcin >> str; // ñ÷èòûâàåì ñòğîêó ïîâòîğíî
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