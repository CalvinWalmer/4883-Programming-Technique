#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> primeFactorization(int n) {
    vector<int> factors;

    // Extract all the 2s
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Now n must be odd, so we can skip one element (note i = i +2)
    for (int i = 3; i <= sqrt(n); i += 2) {
        // While i divides n, add i to the list and divide n
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n becomes a prime number greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

int main() {
    int numTests, cPs, x;
    while (cin >> numTests)
    {
        cPs = 0;
        for(int i = 0; i < numTests; i++){
            cin >> x;
            vector<int> pf = primeFactorization(x);
            if (pf.size() == 2){
                cPs++;
            }
            
        }

        cout << cPs << endl;
    }
    

    return 0;
}