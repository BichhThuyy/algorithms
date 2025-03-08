#include <iostream>
#include <chrono>
#include <format>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "CommonProblemHeader.h"
#include "ConstantHeader.h"

using namespace std;
using namespace common_problem_constant;

int CheckInputLargerThanZero() {
	int nnumber = 0;
	while (true) {
		cout << "Enter an integer > 0: ";
		cin >> nnumber;
		if (cin.fail() || nnumber <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid number, please enter an integer > 0" << endl;
		}
		else {
			break;
		}
	}
	return nnumber;
}

int CheckInputLargerOrEqualZero() {
	int nnumber;
	while (true) {
		cout << "Enter an integer >= 0: ";
		cin >> nnumber;
		if (cin.fail() || nnumber < 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid number" << endl;
		}
		else {
			break;
		}
	}
	return nnumber;
}

void AgeCalculate() {
	int nbirth_year = 0;
	cout << "Enter your birth year: ";
	cin >> nbirth_year;

	auto now = chrono::system_clock::now();
	auto current_year = chrono::year_month_day(chrono::floor<chrono::days>(now)).year();
	cout << "Your age is: " << static_cast<int>(current_year)-nbirth_year << endl;
}

void TaxiFeeCalculate() {
	double fnum_km = 0;
	cout << "Enter the number of kilometer: ";
	cin >> fnum_km;

	double total_fee = 0;
	if (fnum_km <= TAXI_THREDSHOLD_1) {
		total_fee = fnum_km * TAXI_PRICE_1;
	}
	if (TAXI_THREDSHOLD_1 < fnum_km <= TAXI_THREDSHOLD_2) {
		total_fee = TAXI_THREDSHOLD_1 * TAXI_PRICE_1 + (fnum_km - TAXI_THREDSHOLD_1) * TAXI_PRICE_2;
	}
	if (fnum_km > TAXI_THREDSHOLD_2) {
		total_fee = TAXI_THREDSHOLD_1 * TAXI_PRICE_1 + (TAXI_THREDSHOLD_2 - TAXI_THREDSHOLD_1)*TAXI_PRICE_2 + (fnum_km - TAXI_THREDSHOLD_2) * TAXI_PRICE_3;
		if (fnum_km > TAXI_THREDSHOLD_3) {
			total_fee = total_fee * (1 - TAXI_DISCOUNT);
		}
	}

	cout << "Your taxi fee is: " << total_fee << "vnđ" << endl;
}

void SumDigitCalculateUseString() {
	int nnumber = CheckInputLargerThanZero();
	int sum_digit = 0;
	string number_str = to_string(nnumber);
	for (char digit : number_str) {
		sum_digit += digit - '0';
	}

	cout << "Total sum digits: " << sum_digit;
}

void SumDigitCalculateUseArithmetic() {
	int nnumber = CheckInputLargerThanZero();
	int nRem, nSum = 0;
	while (nnumber != 0) {
		nRem = nnumber % 10;
		nSum += nRem;
		nnumber = nnumber / 10;
	}

	cout << "Total sum digit: " << nSum << endl;
}

void CheckSymmetricNumberUseString() {
	int nnumber = CheckInputLargerThanZero();
	string str_reversed_number = to_string(nnumber);
	reverse(str_reversed_number.begin(), str_reversed_number.end());
	cout << "The reversed number is: " << str_reversed_number << endl;
	cout << "Is this a symetric number: " << (to_string(nnumber) == str_reversed_number ? "YES" : "NO") << endl;
}

void CheckSymmetricNumberUseArithmetic() {
	int nnumber = CheckInputLargerThanZero();
	int input = nnumber;
	int nReversedNum = 0;
	int nRem = 0;
	while (input != 0) {
		nRem = input % 10;
		nReversedNum = (nReversedNum * 10) + nRem;
		input = input / 10;
	}

	cout << "The reversed number is: " << nReversedNum << endl;
	cout << "Is this a symetric number: " << (nnumber == nReversedNum ? "YES" : "NO") << endl;

}

void CountDigitUseString() {
	int nnumber = CheckInputLargerThanZero();
	string str_number = to_string(nnumber);
	cout << "The number of digits is: " << str_number.length() << endl;
}

void CountDigitUseArithmetic() {
	int nnumber = CheckInputLargerThanZero();
	int count = 0;
	while (nnumber != 0) {
		nnumber = nnumber / 10;
		count += 1;
	}
	cout << "The number of digits is: " << count << endl;
}

void FindFactorial() {
	int nnumber = CheckInputLargerOrEqualZero();
	if (nnumber == 0) {
		cout << "Factorial of " << nnumber << " is: " << 1 << endl;
	}
	else {
		int nresult = nnumber;
		while (nnumber > 1) {
			nresult *= nnumber - 1;
			nnumber -= 1;
		}
		cout << "Factorial is: " << nresult << endl;
	}
}


int RecursiveFactorial(int input) {
	if (input == 0) {
		return 1;
	}
	else {
		return input * RecursiveFactorial(input - 1);
	}
};

void FindFactorialRecursive() {
	int nnumber = CheckInputLargerOrEqualZero();
	cout << "Factorial is: " << RecursiveFactorial(nnumber) << endl;
}

void CheckNarcissisticNumber() {
	int nnumber = CheckInputLargerThanZero();
	int nCount = 0, nNum = nnumber;
	while (nNum > 0) {
		nNum = nNum / 10;
		nCount += 1;
	}

	int nSum = 0;
	nNum = nnumber;
	while (nNum > 0) {
		nSum += pow(nNum % 10, nCount);
		nNum = nNum / 10;
	}
	cout << "Is this number a narsissitic number: " << (nSum == nnumber ? "Yes" : "No") << endl;
}

void FindLeapYears() {
	int nStart, nEnd;
	cout << "Enter start year and end year: ";
	cin >> nStart >> nEnd;

	vector<int> vLeapYears;
	for (int year = nStart; year <= nEnd; year++) {
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
			vLeapYears.push_back(year);
		}
	}

	for (int year : vLeapYears) {
		cout << "Leap year: " << year << endl;
	}
}