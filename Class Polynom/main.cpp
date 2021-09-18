#include <iostream>
#include <string>

class Polynom {
private:
	int degree = 0;                                       // Ï‡ÍÒËÏ‡Î¸Ì‡ˇ ÒÚÂÔÂÌ¸ ÏÌÓ„Ó˜ÎÂÌ‡ .
	// int* polynomial—oefficient = new int[degree + 1]; // ÍÓ˝ÙÙËˆÂÌÚ˚ ÏÌÓ„Ó˜ÎÂÌ‡, ÍÓÚÓ˚Â ·Û‰ÛÚ ı‡ÌËÚ¸Òˇ ‚ Ï‡ÒÒË‚Â.
	int* polynomial—oefficient = nullptr;

public:
	void inputDegree();         // Á‡Ô‡˘Ë‚‡ÂÚ Ï‡ÍÒËÏ‡Î¸ÌÛ˛ ÒÚÂÔÂÌ¸ ÏÌÓ„Ó˜ÎÂÌ‡.
	void input—oefficient();    // Á‡Ô‡¯Ë‚‡ÂÚ ‚ÒÂ ÍÓ˝ÙÙËˆËÂÌÚ˚ ÏÌÓ„Ó˜ÎÂÌ‡.
	std::string outputPolinom();    //‚˚‚Ó‰ËÚ ‚‚Â‰ÂÌÌ˚È ÏÌÓ„Ó˜ÎÂÌ.
	std::string varDegree(int i); // ÔËÌËÏ‡ÂÚ ÒÚÂÔÂÌ¸ ÏÌÓ„Ó˜ÎÂÌ‡ Ë ‚ÓÁ‚‡˘‡ÂÚ ÒÚÓÍÛ ÚËÔ‡ x^i.

	static Polynom sumPolynomials(Polynom& n1, Polynom& n2); // ÓÚ‰ÂÎ¸Ì‡ˇ ÓÔÂ‡ˆËˇ ÒÎÓÊÂÌËˇ!
	static Polynom defferencePolynomials(Polynom& n1, Polynom& n2); // ÓÚ‰ÂÎ¸Ì‡ˇ ÙÛÌÍˆËˇ ‚˚˜ËÚ‡ÌËˇ!

	friend Polynom operator+(Polynom& n1, Polynom& n2); // ·ËÌ‡Ì‡ˇ ÓÔÂ‡ˆËˇ ÒÎÓÊÂÌËˇ!
	friend Polynom operator-(Polynom& n1, Polynom& n2); // ·ËÌ‡Ì‡ˇ ÓÔÂ‡ˆËˇ ‚˚˜ËÚ‡ÌËˇ!

	Polynom() {
		inputDegree();
		polynomial—oefficient = new int[degree + 1];
	}
	Polynom(int degree) {
		polynomial—oefficient = new int[degree + 1];
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
	//number1.inputDegree();
	number1.input—oefficient();
	std::cout << number1.outputPolinom();

	std::cout << "\n\n¬ÚÓÓÈ ÏÌÓ„Ó˜ÎÂÌ!\n";
	Polynom number2;
	//number2.inputDegree();
	number2.input—oefficient();
	std::cout << number2.outputPolinom();

	std::cout << "\n\n—ÛÏÏ‡ ‰‚Ûı ÏÌÓ„Ó˜ÎÂÌÓ‚!\n";
	//Polynom number3 = std::move(Polynom::sumPolynomials(number1, number2)); // ‚ÚÓÓÈ ÒÔÓÒÓ· ÒÎÓÊËÚ¸ ÔÓÎËÌÓÏ˚
	Polynom number3 = number1 + number2;
	std::cout << number3.outputPolinom();

	std::cout << "\n\n–‡ÁÌÓÒÚ¸ ‰‚Ûı ÏÌÓ„Ó˜ÎÂÌÓ‚!\n";
	//Polynom number4 = std::move(Polynom::defferencePolynomials(number1, number2)); // ‚ÚÓÓÈ ÒÔÓÒÓ· ‚˚˜ÂÒÚ¸ ÔÓÎËÌÓÏ˚
	Polynom number4 = number1 - number2;
	std::cout << number4.outputPolinom();

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

Polynom operator+(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i] + n2.polynomial—oefficient[i];
		}
	}
	return n3;
}

Polynom operator-(Polynom& n1, Polynom& n2) {
	Polynom n3(std::max(n1.degree, n2.degree));
	for (int i = 0; i < std::max(n1.degree, n2.degree) + 1; i++) {
		if (n1.degree == n2.degree) {
			n3.degree = n1.degree;
			n3.polynomial—oefficient[i] = n1.polynomial—oefficient[i] - n2.polynomial—oefficient[i];
		}
	}
	return n3;
}
