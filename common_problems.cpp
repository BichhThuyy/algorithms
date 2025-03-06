#include <iostream>
#include <chrono>
#include <format>
#include <string>
#include <vector>
#include "CommonProblemHeader.h"
#include "ConstantHeader.h"

using namespace std;
using namespace common_problem_constant;

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
	int nnumber = 0;
	cout << "Enter the integer: ";
	cin >> nnumber;

	int sum_digit = 0;
	string number_str = to_string(nnumber);
	for (char digit : number_str) {
		sum_digit += digit - '0';
	}

	cout << "Total sum digits: " << sum_digit;
}

void SumDigitCalculateUseArithmetic() {
	int nnumber = 0;
	while (true) {
		cout << "Enter an integer > 0: ";
		cin >> nnumber;

		if (cin.fail() || nnumber <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input, please enter an integer > 0" << endl;
		}
		else {
			break;
		}
	}

	int nRem, nSum = 0;
	while (nnumber != 0) {
		nRem = nnumber % 10;
		nSum += nRem;
		nnumber = nnumber / 10;
	}

	cout << "Total sum digit: " << nSum << endl;
}