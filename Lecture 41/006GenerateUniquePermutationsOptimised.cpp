/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (inp[i] == '\0') { // i == n
		cout << inp << endl;
		return;
	}

	// recursive case

	// you've to take a sequence of n-i decisions for the positions i to n-1

	// or

	// generate the permutations for the suffix of inp[] that starts at the ith index i.e. inp[i....n-1]

	// make a decision for the ith position

	for (int j = i; j < n; j++) {

		// can I choose the char at the jth index to be assigned to the ith position

		bool flag = true; // assume, you can assign the char. at the jth index to the ith position

		for (int k = j + 1; k < n; k++) {
			if (inp[k] == inp[j]) {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			// you can use the char at the jth index to be assigned to the ith position
			swap(inp[i], inp[j]);
			f(inp, n, i + 1);
			swap(inp[i], inp[j]); // backtracking
		}
	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
