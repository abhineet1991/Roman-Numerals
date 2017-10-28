#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include<string>
using namespace std;

class RomanNumeral
{
public:
    /**
     * Default constructor.
     */
    RomanNumeral();
    RomanNumeral(int decimal);
    RomanNumeral(string roman);

    // Operator overloading
    RomanNumeral operator+ ( RomanNumeral& numeral);
    RomanNumeral operator- ( RomanNumeral& numeral);
    RomanNumeral operator/ ( RomanNumeral& numeral);
    RomanNumeral operator* ( RomanNumeral& numeral);
    bool operator== ( RomanNumeral& numeral);
    bool operator!= ( RomanNumeral& numeral);
    friend ostream& operator<< (ostream&, RomanNumeral& numeral);
    friend istream& operator>> (istream&, RomanNumeral& numeral);

    int getDecimal();
    string getRoman();
    /***** Complete this class declaration. *****/
private:

     string roman;
     int decimal;
     void to_roman(int decimal);
     void to_decimal(string roman);
};

#endif /* ROMANNUMERAL_H_ */
