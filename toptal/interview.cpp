#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    vector<int> result;
    result = getChange(5, 0.99);

    for (int i = result.size(); i > 0; --i) {
        cout << result[i] << " ";
    }
}

vector<int> getChange(float money, float price) {
    int money_in_cents = (money * 100) - (price * 100);
    int div;
    vector<int> result, denominations{1,5,10,25,50,100};

    for (int i = denominations.size(); i > 0; --i) {
        div = money_in_cents / denominations[i];

        if (money_in_cents % denominations[i] != 0) {
            money_in_cents = money_in_cents % denominations[i];
        }

        if (div > 0) {
            result.push_back(div);
        } else {
            result.push_back(0);
        }
    }

    return result;
}