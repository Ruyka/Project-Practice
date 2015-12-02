//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int main() {
//	int m, depCase, mLoan, prevMLoan, curMonth;
//	double downPay, loan, depValue, prevDepVal, carValue, payment;
//
//	cin >> m >> downPay >> loan >> depCase;
//	while (m > 0) {
//		curMonth = 1;
//		cin >> prevMLoan >> prevDepVal;
//		carValue = downPay + loan;
//		--depCase;
//		carValue -= carValue*prevDepVal;
//		payment = loan / m;
//		for (curMonth; curMonth <= m && loan > carValue; ++curMonth) {
//			if (depCase) {
//				cin >> mLoan >> depValue;
//				for (curMonth; curMonth < mLoan && loan > carValue; ++curMonth) {
//					carValue -= carValue*prevDepVal;
//					loan -= payment;
//				}
//				prevMLoan = mLoan;
//				prevDepVal = depValue;
//				--depCase;
//				--curMonth;
//			}
//			else {
//				carValue -= carValue*prevDepVal;
//				loan -= payment;
//			}
//		}
//		curMonth = curMonth != 1 ? --curMonth : 0;
//		printf(curMonth == 1 ? "1 month\n" : "%d months\n", curMonth);
//		while (depCase--)
//			cin >> mLoan >> depValue;
//		cin >> m >> downPay >> loan >> depCase;
//	}
//
//
//	return 0;
//}