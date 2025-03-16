#include <iostream>
#include <chrono>
#include <format>
#include <string>
#include <sstream>
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

void CheckValidDay() {
	string sDate;
	cout << "Endter a date format yyyy/MM/dd: ";
	cin >> sDate;

	stringstream ssDate(sDate);
	string token;
	vector<int> parts;
	while (getline(ssDate, token, '/')) {
		parts.push_back(stoi(token));
	}

	int year = parts[0];
	int month = parts[1];
	int day = parts[2];
	if (year <= 0) {
		cout << "Invalid year" << endl;
		return;
	}
	if (month < 1 || month > 12) {
		cout << "Invalid month" << endl;
		return;
	}

	int nMaxDays;
	vector<int> monthHas30Days = { 4, 6, 9, 11 };
	vector<int> monthHas31Days = { 1, 3, 5, 7, 8, 10, 12 };
	if (month == 2) {
		nMaxDays = ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) ? 29 : 30;
	}
	if (count(monthHas30Days.begin(), monthHas30Days.end(), month) > 0) {
		nMaxDays = 30;
	}
	if (count(monthHas31Days.begin(), monthHas31Days.end(), month) > 0) {
		nMaxDays = 31;
	}
	if (day < 1 || day > nMaxDays) {
		cout << "Invalid day" << endl;
		return;
	}
	cout << "Valid day" << endl;
}

// Find the previous day and the next day of a day
int FindTotalDayOfAMonth(int month, int year) {
	int nMaxDays;
	vector<int> monthHas30Days = { 4, 6, 9, 11 };
	vector<int> monthHas31Days = { 1, 3, 5, 7, 8, 10, 12 };
	if (month == 2) {
		nMaxDays = ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) ? 29 : 30;
	}
	if (count(monthHas30Days.begin(), monthHas30Days.end(), month) > 0) {
		nMaxDays = 30;
	}
	if (count(monthHas31Days.begin(), monthHas31Days.end(), month) > 0) {
		nMaxDays = 31;
	}
	return nMaxDays;
}

bool CheckValidDay(int year, int month, int day) {
	if (year <= 0) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}

	int nMaxDays;
	vector<int> monthHas30Days = { 4, 6, 9, 11 };
	vector<int> monthHas31Days = { 1, 3, 5, 7, 8, 10, 12 };
	if (month == 2) {
		nMaxDays = ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) ? 28 : 29;
	}
	if (count(monthHas30Days.begin(), monthHas30Days.end(), month) > 0) {
		nMaxDays = 30;
	}
	if (count(monthHas31Days.begin(), monthHas31Days.end(), month) > 0) {
		nMaxDays = 31;
	}
	if (day < 1 || day > nMaxDays) {
		return false;
	}
	return true;
}

void FindPreviousDay() {
	string sDay;
	cout << "Enter a day format yyyy/MM/dd: ";
	cin >> sDay;

	stringstream ssDay(sDay);
	string token;
	vector<int> parts;
	while (getline(ssDay, token, '/')) {
		parts.push_back(stoi(token));
	}

	int year = parts[0], month = parts[1], day = parts[2];
	if (!CheckValidDay(year, month, day)) {
		cout << "Invalid day" << endl;
		return;
	}
	int prevDay = day - 1, prevMonth = month, prevYear = year;
	if (prevDay <= 0) {
		prevMonth = month - 1;
		if (prevMonth <= 0) {
			prevYear = year - 1;
			if (prevYear <= 0) {
				cout << "Invalid day" << endl;
				return;
			}
			prevMonth = 12;
		}
		prevDay = FindTotalDayOfAMonth(prevMonth, prevYear);
	}
	cout << "Previous day: " << prevYear << '/' << prevMonth << '/' << prevDay;
}

void FindNextDay() {
	string sDay;
	cout << "Enter a day format yyyy/MM/dd: ";
	cin >> sDay;

	stringstream ssDay(sDay);
	string token;
	vector<int> parts;
	while (getline(ssDay, token, '/')) {
		parts.push_back(stoi(token));
	}

	int year = parts[0], month = parts[1], day = parts[2];
	if (!CheckValidDay(year, month, day)) {
		cout << "Invalid day";
		return;
	}
	int nextDay = day + 1, nextMonth = month, nextYear = year;
	int curTotalDays = FindTotalDayOfAMonth(month, year);
	if (nextDay > curTotalDays) {
		nextDay = 1;
		nextMonth = month + 1;
		if (nextMonth > 12) {
			nextMonth = 1;
			nextYear = year + 1;
		}
	}
	cout << "Next day: " << nextYear << '/' << nextMonth << '/' << nextDay;
}

// Find order of a day in year
void FindOrderOfDay() {
	string sDay;
	cout << "Enter a day format yyyy/MM/dd: ";
	cin >> sDay;

	stringstream ssDay(sDay);
	string token;
	vector<int> parts;
	while (getline(ssDay, token, '/')) {
		parts.push_back(stoi(token));
	}

	int year = parts[0], month = parts[1], day = parts[2];
	if (!CheckValidDay(year, month, day)) {
		cout << "Invalid day";
		return;
	}

	if (month == 1) {
		cout << "The order of day is: " << day;
		return;
	}

	vector<int> v_total_days_of_month_ly = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<int> v_total_days_of_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int total_prev_days = 0;
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
		for (int i = 0; i < month - 1; i++) {
			total_prev_days += v_total_days_of_month_ly[i];
		}
	}
	else {
		for (int i = 0; i < month - 1; i++) {
			total_prev_days += v_total_days_of_month[i];
		}
	}
	cout << "The order of day is: " << total_prev_days + day;
}

void CheckPrimeInteger() {
	int nNum = CheckInputLargerThanZero();
	bool isPrime = true;
	for (int i = 2; i <= nNum; i++) {
		if ((nNum % i == 0) && (i != nNum)) {
			isPrime = false;
			break;
		}
	}
	cout << "Is prime: " << (isPrime ? "Yes" : "No");
}

void FindGreatestCommonDivisor() {
	int a = CheckInputLargerThanZero();
	int b = CheckInputLargerThanZero();
	
	// swap a and b if a < b to make sure a is always the bigest
	if (a < b) {
		int tem = a;
		a = b;
		b = tem;
	}
	
	vector<int> b_divisor;
	for (int i = 1; i <= b; i++) {
		if (b % i == 0) {
			b_divisor.push_back(i);
		}
	}
	int greates_common_divisor = 1;
	for (int div : b_divisor) {
		if ((a % div == 0) && (div > greates_common_divisor)) {
			greates_common_divisor = div;
		}
	}
	cout << "The greates common divisor of " << a << " and " << b << " is: " << greates_common_divisor;
}

void CountDivisor() {
	int nNum = CheckInputLargerThanZero();
	int count = 0;
	for (int i = 1; i <= nNum; i++) {
		if (nNum % i == 0) {
			count++;
		}
	}
	cout << "The number of divisors are: " << count;
}

void CheckPerfectInteger() {
	int nNum = CheckInputLargerThanZero();
	cout << "nNum: " << nNum;
	int nSum = 0;
	for (int i = 1; i <= nNum; i++) {
		if ((nNum % i == 0) && (i != nNum)) {
			nSum += i;
		}
	}
	cout << "Is this perfect number: " << (nSum == nNum ? "Yes" : "No");
}

void CalculateSn() {
	int nNum = CheckInputLargerThanZero();

	int nSum = 0;
	for (int i = 0; i <= nNum; i++) {
		int nSumj = 0;
		for (int j = 0; j <= i; j++) {
			nSumj += j;
		}
		nSum += nSumj;
	}
	cout << "Result: " << nSum;
}

// Fibonaci
int Fibonaci(int n) {
	if ((n == 0) || (n == 1)) {
		return 1;
	}
	else {
		return Fibonaci(n - 1) + Fibonaci(n - 2);
	}
}

void CalculateFibonaci() {
	int nNum = CheckInputLargerThanZero();
	for (int i = 0; i <= nNum; i++) {
		cout << Fibonaci(i) << ", ";
	}
}