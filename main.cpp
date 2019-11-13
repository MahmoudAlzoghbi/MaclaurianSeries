#include <iostream>
#include<cmath>

using namespace std;

// Return Bernoulli Value
// Bernoulli == 0 for odd Number Expect 1
long double Bernoulli (int index){
    if (index == 0)
        return 1.0;
    else if (index == 1)
        return -1./2.;
    else if(index == 2)
        return 0.16666666;
    else if(index == 4)
        return -0.03333333;
    else if(index == 6)
        return 0.02380952;
    else if(index == 8)
        return -0.0333333333;
    else if(index == 10)
        return 0.075757575;
    else if(index == 12)
        return -0.253113553;
    else if(index == 14)
        return 1.166666666;
    else if(index == 16)
        return -7.0685;
    else if (index == 18)
        return 69.996;
	else if(index == 20)
		return 5986.64;
	else if(index == 22)
        return 1.58986e+006;
	else if( index == 24)
        return -3.16355e+009;
	else if( index == 26)
        return -9.58358e+012;
	else if(index == 28)
        return -1.63095e+016;
	else if(index == 30)
        return -2.08318e+019;
    else return 0;
}

// Calculate Factorial
double Factorial (int n ){
    if (n > 1 ){
        return n * Factorial(n - 1);
    } else {
        return 1;
    }
}

// Calculate The Power
double Power (double base , double power){
    double result = 1.0;
    if (power == 0){
        return 1;
    }
    for (int i = 0 ; i < power ; i++){
        result *= base ;
    }
    return result;
}

// Calculate Cosine
double CosX(double degree){
    double radian = degree * (3.1459 / 180);
    int n = 15;     // Counter To First 15 terms
    double numerator = 0 , denumerator = 0 , result = 0;
    for (int i = 0 ; i < n ; i++){
        numerator = Power(-1 , i) * Power(radian , 2*i);
        denumerator = Factorial(2*i);
        result += (numerator / denumerator);
        //cout << result << endl;
    }
    return result;
}

// Calculate Sin
double SinX(double degree){
    double radian = degree * (3.1459 / 180);
    int n = 15;     // Counter To First 15 terms
    double numerator = 0 , denumerator = 0 , result = 0;
    for (int i = 0 ; i < n ; i++){
            numerator = Power(-1 , i) * Power(radian , 2*i + 1);
            denumerator = Factorial(2*i + 1);
            result += (numerator / denumerator);
    }
    return result;
}

// Calculate Tan
long double TanX(double degree){
    long double radian = degree * (3.1459 / 180);
    //cout << radian << endl;
    //cout << radian << endl ;
    int n = 15;     // Counter To First 15 terms
    double numerator = 0.0 , result = 0.0;
    double denumerator ;
    for (int i = 0 ; i < n ; i++){
        long double ber = Bernoulli(2 * i + 2);
        //cout << ber << endl;
        numerator = Power(-1 , i) * Power(2 , 2 * i + 2) * (Power(2 , 2 * i + 2) -1) * ber;
        //cout << numerator << endl;
        denumerator = Factorial(2 * i + 2);
        //cout << denumerator << endl;
        result += ((numerator / denumerator)* Power(radian , 2 * i + 1));
        //cout << result << endl ;
    }
    return result;
}

int main()
{
    cout << "Approximately Cos(30) Equals: " << CosX(30) << endl;
    cout << "Approximately Sin(30) Equals: " << SinX(30) << endl;
    cout << "Approximately Tan(30) Equals: " << TanX(30) << endl;
    return 0;
}
