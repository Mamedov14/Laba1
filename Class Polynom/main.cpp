#include <iostream>
#include <string>

class Polynom {

private:
	int degree = 0;                                       // Ï‡ÍÒËÏ‡Î¸Ì‡ˇ ÒÚÂÔÂÌ¸ ÏÌÓ„Ó˜ÎÂÌ‡ .
	// int* polynomial—oefficient = new int[degree + 1]; // ÍÓ˝ÙÙËˆÂÌÚ˚ ÏÌÓ„Ó˜ÎÂÌ‡, ÍÓÚÓ˚Â ·Û‰ÛÚ ı‡ÌËÚ¸Òˇ ‚ Ï‡ÒÒË‚Â.
	int* polynomial—oefficient = nullptr;
	int* newPolynomials = nullptr;

public:
	void inputDegree();         // Á‡Ô‡˘Ë‚‡ÂÚ Ï‡ÍÒËÏ‡Î¸ÌÛ˛ ÒÚÂÔÂÌ¸ ÏÌÓ„Ó˜ÎÂÌ‡.
	void input—oefficient();    // Á‡Ô‡¯Ë‚‡ÂÚ ‚ÒÂ ÍÓ˝ÙÙËˆËÂÌÚ˚ ÏÌÓ„Ó˜ÎÂÌ‡.
	std::string outputPolinom();    //‚˚‚Ó‰ËÚ ‚‚Â‰ÂÌÌ˚È ÏÌÓ„Ó˜ÎÂÌ.
	std::string outputNewPolynomials();    //‚˚‚Ó‰ËÚ ÌÓ‚˚È ÏÌÓ„Ó˜ÎÂÌ.
	std::string varDegree(int i); // ÔËÌËÏ‡ÂÚ ÒÚÂÔÂÌ¸ ÏÌÓ„Ó˜ÎÂÌ‡ Ë ‚ÓÁ‚‡˘‡ÂÚ ÒÚÓÍÛ ÚËÔ‡ x^i.

	static Polynom sumPolynomials(Polynom& n1, Polynom& n2); // ÓÚ‰ÂÎ¸Ì‡ˇ ÓÔÂ‡ˆËˇ ÒÎÓÊÂÌËˇ!
	static Polynom defferencePolynomials(Polynom& n1, Polynom& n2); // ÓÚ‰ÂÎ¸Ì‡ˇ ÙÛÌÍˆËˇ ‚˚˜ËÚ‡ÌËˇ!

	friend Polynom operator+(Polynom& n1, Polynom& n2); // ·ËÌ‡Ì‡ˇ ÓÔÂ‡ˆËˇ ÒÎÓÊÂÌËˇ!
	friend Polynom operator-(Polynom& n1, Polynom& n2); // ·ËÌ‡Ì‡ˇ ÓÔÂ‡ˆËˇ ‚˚˜ËÚ‡ÌËˇ!
	friend void reverse—oefficient(Polynom& n); // ÏÂÌˇÂÚ ÍÓ˝ÙÙËˆËÂÌÚ˚ ‚ Ï‡ÒÒË‚Â Á‡‰ÓÏ Ì‡ÔÂÂ‰!

	void productPolynomials(Polynom& n1, Polynom& n2); // ÔÓËÁ‚Â‰ÂÌËÂ ÏÌÓ„ÓÎÂÌÓ‚!
	static void comparisonPolynomials(Polynom& n1, Polynom& n2); // Ò‡‚ÌÂÌËÂ ÏÌÓ„Ó˜ÎÂÌÓ‚!
	void polynomialDifferentiation(Polynom& n1); //‰ËÙÙÂÂÌˆËÓ‚‡ÌËÂ ÏÌÓ„Ó˜ÎÂÌ‡!


	int GetDegree() {
		return degree;
	}

	Polynom() {
		inputDegree();
		polynomial—oefficient = new int[degree + 1];
	}
	Polynom(int degree) {
		this->degree = degree;
		polynomial—oefficient = new int[degree + 1];
	}

	Polynom(int d1, int d2) {
		degree = d1 + d2;
		newPolynomials = new int[degree];
	}

	Polynom(Polynom&& other) {
		this->degree = other.degree;
		this->polynomial—oefficient = other.polynomial—oefficient;
		other.degree = 0;
		other.polynomial—oefficient = nullptr;
	}
	// other - ÛÍ‡Á˚‚‡ÂÚ Ì‡ ÍÓÔËÛÂÏ˚È/ÔÂÂÏÂ˘‡ÂÏ˚È Ó·˙ÂÍÚ ‚ ‰Û„ÓÈ Ó·˙ÂÍÚ!
	Polynom(Polynom& other) {
		this->degree = other.degree;
		this->polynomial—oefficient = other.polynomial—oefficient;
		other.degree = 0;
		other.polynomial—oefficient = nullptr;
	}// =

	~Polynom() {
		delete[] polynomial—oefficient;
		polynomial—oefficient = nullptr;
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	std::cout << "œÂ‚˚È ÏÌÓ„Ó˜ÎÂÌ!\n";
	Polynom number1;
	number1.input—oefficient();
	std::cout << number1.outputPolinom();

	std::cout << "\n\n¬ÚÓÓÈ ÏÌÓ„Ó˜ÎÂÌ!\n";
	Polynom number2;
	number2.input—oefficient();
	std::cout << number2.outputPolinom();

	reverse—oefficient(number1);
	reverse—oefficient(number2);

	std::cout << "\n\n—ÛÏÏ‡ ‰‚Ûı ÏÌÓ„Ó˜ÎÂÌÓ‚!\n";
	//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // ‚ÚÓÓÈ ÒÔÓÒÓ· ÒÎÓÊËÚ¸ ÔÓÎËÌÓÏ˚
	Polynom number3 = number1 + number2;
	reverse—oefficient(number3);
	std::cout << number3.outputPolinom();

	std::cout << "\n\n–‡ÁÌÓÒÚ¸ ‰‚Ûı ÏÌÓ„Ó˜ÎÂÌÓ‚!\n";
	//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // ‚ÚÓÓÈ ÒÔÓÒÓ· ‚˚˜ÂÒÚ¸ ÔÓÎËÌÓÏ˚
	Polynom number4 = number1 - number2;
	reverse—oefficient(number4);
	std::cout << number4.outputPolinom();

	Polynom number5(number1.GetDegree(), number2.GetDegree());
	number5.productPolynomials(number1, number2);
	reverse—oefficient(number5);
	std::cout << number5.outputNewPolynomials();

	Polynom::comparisonPolynomials(number1, number2);

	std::cout << "\n\nœÓ‰ËÙÙÂÂÌˆËÓ‚‡ÎË ÏÌÓ„Ó˜ÎÂÌ: \n";
	Polynom number6(number1.GetDegree());
	number6.polynomialDifferentiation(number1);
	reverse—oefficient(number6);
	std::cout << number6.outputPolinom();

	std::cout << "\n\n";
	system("pause");
	return 0;
}

void Polynom::inputDegree() {
	std::cout << "¬‚Â‰ËÚÂ Ï‡ÍÒËÏ‡Î¸ÌÛ˛ ÒÚÂÔÂÌ¸ ÏÌÓ„Ó˜ÎÂÌ‡: ";
	std::cin >> degree;
}

void Polynom::input—oefficient() {
	for (int i = 0; i < degree + 1; i++) {
		if (i == 0) {
			std::cout << "¬‚Â‰ËÚÂ ÍÓ˝ÙÙËˆËÂÌÚ ÔË Ï‡ÍÒËÏ‡Î¸ÌÓÈ ÒÚÂÔÂÌË: ";
			std::cin >> polynomial—oefficient[i];
			std::cout << "œÓ‰ÓÎÊ‡ÈÚÂ ‚‚Ó‰ËÚ¸ ÍÓ˝ÙÙËˆËÂÌÚ˚ ÔÓÒÎÂ‰Ó‚‡ÚÂÎ¸ÌÓ:\n";
		}
		else if (i == degree) {
			std::cout << "¬‚Â‰ËÚÂ Ò‚Ó·Ó‰Ì˚È ˝ÎÂÏÂÌÚ ÏÌÓ„Ó˜ÎÂÌ‡: ";
			std::cin >> polynomial—oefficient[degree];
		}
		else {
			std::cin >> polynomial—oefficient[i];
		}
	}
}

std::string Polynom::outputPolinom() {
	std::string resultPolinim = "";
	std::cout << "œÓÎÛ˜ËÎË ÏÌÓ„Ó˜ÎÂÌ ‚Ë‰‡: ";
	for (int i = 0; i < degree + 1; i++) {
		if (i != degree) {
			resultPolinim += std::to_string(polynomial—oefficient[i]) + varDegree(degree - i);
		}
		else {
			resultPolinim += std::to_string(polynomial—oefficient[i]);
		}
		if (polynomial—oefficient[i + 1] >= 0 && i >= 0 && i < degree) {
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
	std::cout << "\n\nœÓËÁ‚Â‰ÂÌËÂ ÏÌÓ„Ó˜ÎÂÌÓ‚: ";
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

Polynom Polynom::sumPolynomials(Polynom& n1, Polynom& n2) { // ÌÂ Ó·ˇÁ‡ÚÂÎ¸Ì‡ˇ ÙÛÌÍˆËˇ, ˜ËÒÚÓ ‰Îˇ ÓÔ˚Ú‡
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i] + n2.polynomial—oefficient[i];
		}
	}
	return n3;
}

Polynom Polynom::defferencePolynomials(Polynom& n1, Polynom& n2) { // ÌÂ Ó·ˇÁ‡ÚÂÎ¸Ì‡ˇ ÙÛÌÍˆËˇ, ˜ËÒÚÓ ‰Îˇ ÓÔ˚Ú‡
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i] - n2.polynomial—oefficient[i];
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
			newPolynomials[i + j] += n1.polynomial—oefficient[i] * n2.polynomial—oefficient[j];
		}
	}
}

void Polynom::comparisonPolynomials(Polynom& n1, Polynom& n2) {
	int j = 0;
	bool l = true;
	for (int i = 0; i < n1.degree + 1; i++) {
		if (n1.degree == n2.degree) {
			if (n1.polynomial—oefficient[i] == n2.polynomial—oefficient[j]) {
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
		std::cout << "\n\nÃÌÓ„Ó˜ÎÂÌ˚ ‡‚Ì˚!\n";
	}
	else {
		std::cout << "\n\nÃÌÓ„Ó˜ÎÂÌ˚ ÌÂ ‡‚Ì˚!\n";
	}
}

void Polynom::polynomialDifferentiation(Polynom& n1) {
	for (int i = 0; i < n1.degree + 1; i++) {

		polynomial—oefficient[i] = 0;
	}
	for (int i = 0; i < n1.degree + 1; i++) {

		polynomial—oefficient[i] = i * n1.polynomial—oefficient[i];
	}
	for (int i = 0; i < n1.degree; i++) {

		polynomial—oefficient[i] = polynomial—oefficient[i + 1];
	}
	degree--;
}

Polynom operator+(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++)
	{
		n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i] + n2.polynomial—oefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++)
	{
		if (n1.degree > n2.degree) {
			n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i];
		}
		else {
			n3.polynomial—oefficient[i] = n2.polynomial—oefficient[i];
		}
	}
	return n3;
}

Polynom operator-(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::min(n1.degree, n2.degree) + 1; i++)
	{
		n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i] - n2.polynomial—oefficient[i];
	}
	for (int i = std::min(n1.degree, n2.degree) + 1; i < std::max(n1.degree, n2.degree) + 1; i++)
	{
		if (n1.degree > n2.degree) {
			n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i];
		}
		else {
			n3.polynomial—oefficient[i] = -n2.polynomial—oefficient[i];
		}
	}

	return n3;
}

void reverse—oefficient(Polynom& n)
{
	if (n.polynomial—oefficient != nullptr) {
		std::reverse((n.polynomial—oefficient), (n.polynomial—oefficient + n.degree + 1));
	}
	else if (n.newPolynomials != nullptr) {
		std::reverse((n.newPolynomials), (n.newPolynomials + n.degree + 1));
	}
}
