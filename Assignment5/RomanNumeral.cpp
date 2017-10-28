#include "RomanNumeral.h"
#include<iostream>
using namespace std;

RomanNumeral::RomanNumeral() :
		roman(""), decimal(0) {
}

RomanNumeral::RomanNumeral(string romanArgument) {
	to_decimal(romanArgument);

}

RomanNumeral::RomanNumeral(int decimalEquiv) {
	to_roman(decimalEquiv);

}


/**
 * Method takes care of special cases by keeping
 * track of previously iterated value in char prev.
 */
void RomanNumeral::to_decimal(string romanArg) {

	int decimalEquiv = 0;
	char prev = '0';
	for (unsigned int i = 0; i < romanArg.size(); i++) {

		char num = romanArg[i];

		switch (num) {
		case 'I':
			decimalEquiv += 1;
			break;
		case 'V':
			decimalEquiv += 5;
			if (prev == 'I') {
				decimalEquiv -= 2;
			}
			break;
		case 'X':
			decimalEquiv += 10;
			if (prev == 'I') {
				decimalEquiv -= 2;
			}
			break;
		case 'L':
			decimalEquiv += 50;
			if (prev == 'X') {
				decimalEquiv -= 20;
			}
			break;
		case 'C':
			decimalEquiv += 100;
			if (prev == 'X') {
				decimalEquiv -= 20;
			}
			break;
		case 'D':
			decimalEquiv += 500;
			if (prev == 'C') {
				decimalEquiv -= 200;
			}
			break;
		case 'M':
			decimalEquiv += 1000;
			if (prev == 'C') {
				decimalEquiv -= 200;
			}
			break;
		default:
			cout << "Invalid Num" << endl;
			break;
		}

		prev = num;

	}

	decimal = decimalEquiv;
	roman = romanArg;

}


/**
 *
 *
 *
 */
void RomanNumeral::to_roman(int decimalEquiv) {

	int number = 1000;
	int num = 100;  // integer to handle odd iteration cases
	int count = 1; // to count whether its an even or odd iteration
	string romanNumeral = "";
	decimal = decimalEquiv;
	while (number != 0 && decimalEquiv != 0) {

		if (decimalEquiv % number != decimalEquiv) {

			int repeatCount = decimalEquiv / number;
         // only main cases are specified in switch cases here , special case are automatically handled
	     // every odd iteration covers decimalEquiv /1000 , dec/100, dec/10 , dec /1
		 // every even iteration covers decimalEquiv/500, dec/50 , dec/5
			if (count%2==0 && (number*2 -decimalEquiv <= num)) { // cond will be true for odd iteration
				decimalEquiv = decimalEquiv % (number*2 - num);
				repeatCount = 100;
			}else{
				 decimalEquiv = decimalEquiv % number; // condition will be true for even iteration
			}

			switch (number) {
			case 1000:

				while (repeatCount != 0) {
					romanNumeral += "M";
					repeatCount--;
				}
				break;
			case 500:
					if (repeatCount == 100) {
						romanNumeral += "CM";
					} else
						romanNumeral += "D";
				break;
			case 100:
				while (repeatCount != 0) {
					if (repeatCount == 4) {
						romanNumeral += "CD";
						break;
					} else
						romanNumeral += "C";
					repeatCount--;
				}
				break;
			case 50:
					if (repeatCount == 100) {
						romanNumeral += "XC";
					} else
						romanNumeral += "L";
				break;
			case 10:
				while (repeatCount != 0) {
					if (repeatCount == 4) {
						romanNumeral += "XL";
						break;
					} else
						romanNumeral += "X";
					repeatCount--;
				}
				break;
			case 5:
					if (repeatCount == 100) {
						romanNumeral += "IX";
					} else
						romanNumeral += "V";
					repeatCount--;
				break;
			case 1:
				while (repeatCount != 0) {
					if (repeatCount == 4) {
						romanNumeral += "IV";
						break;
					} else
						romanNumeral += "I";
					repeatCount--;
				}
				break;
			default:
				cout << "Invalid Num" << endl;
				break;
			}

		}
		 // every alternate iteration number gets divided into half and one fifth
		// 1000/2 , 500/100, 100/2 , 50/10, 10/2 , 5/1
		if (count % 2 == 0) {
			number /= 5;
			num = num/10;
		} else {
			number /= 2;
		}
		count++;
	}
	roman = romanNumeral;
}


int RomanNumeral::getDecimal() {

	return decimal;
}

string RomanNumeral::getRoman() {

	return roman;
}

RomanNumeral RomanNumeral::operator+(RomanNumeral& rm) {

	int addNum = this->getDecimal() + rm.getDecimal();
	RomanNumeral newNum(addNum);
	return newNum;
}

RomanNumeral RomanNumeral::operator-(RomanNumeral& rm) {

	int addNum = this->getDecimal() - rm.getDecimal();
	RomanNumeral newNum(addNum);
	return newNum;
}

RomanNumeral RomanNumeral::operator/(RomanNumeral& rm) {

	int addNum = this->getDecimal() /rm.getDecimal();
	RomanNumeral newNum(addNum);
	return newNum;
}

RomanNumeral RomanNumeral::operator*(RomanNumeral& rm) {

	int addNum = rm.getDecimal() * this->getDecimal();
	RomanNumeral newNum(addNum);
	return newNum;
}

bool RomanNumeral::operator==(RomanNumeral& rm) {

	if (this->getDecimal() == rm.getDecimal()) {
		return true;
	} else {
		return false;
	}

}

bool RomanNumeral::operator!=(RomanNumeral& rm) {

	if (this->getDecimal() != rm.getDecimal()) {
		return true;
	} else {
		return false;
	}

}

ostream& operator<<(ostream& ostream, RomanNumeral& rm) {

	ostream << "[" << rm.getDecimal() << ":" << rm.getRoman() << "]";

	return ostream;
}

istream& operator>>(istream& istream, RomanNumeral& rm) {

	istream >> rm.roman;
	rm.to_decimal(rm.roman);
	return istream;
}

/***** Complete this class implementation. *****/
