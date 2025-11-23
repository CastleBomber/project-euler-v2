#include "reciprocalCycles.h"

void tmp() {
    mpf_set_default_prec(5000); // Set precision to 5000 bits (~1500 digits)
    mpf_class a("1.1234567890123456789012345678901234567890");
    mpf_class b("2.9876543210987654321098765432109876543210");

    mpf_class result = a * b;
    
    cout << result << endl;

    gmp_printf("%.9Ff\n", result.get_mpf_t());
}

/*

FIX THIS FACTORIALS LIST!
1->1
1->1
2->0.5
6->0.166667
24->0.0416667
120->0.00833333
720->0.00138889
5040->0.000198413
40320->2.48016e-05
362880->2.75573e-06
3628800->2.75573e-07

*/
void tmp2() {
    vector<int> factorials(1000);
    vector<mpf_class> decimals(1000);
    
    cout << factorials[0] << "->" << decimals[0] << endl;
    cout << factorials[1] << "->" << decimals[1] << endl;
    cout << factorials[2] << "->" << decimals[2] << endl;
    cout << factorials[3] << "->" << decimals[3] << endl;
    cout << factorials[4] << "->" << decimals[4] << endl;
    cout << factorials[5] << "->" << decimals[5] << endl;
    cout << factorials[6] << "->" << decimals[6] << endl;
    cout << factorials[7] << "->" << decimals[7] << endl;
    cout << factorials[8] << "->" << decimals[8] << endl;
    cout << factorials[9] << "->" << decimals[9] << endl;
    cout << factorials[10] << "->" << decimals[10] << endl;
}