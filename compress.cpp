/*
 * Author(s):   Alex Reinisch and Nick Walker 
 * Date(s):     28-02 March-April 2012
 * Prog05 - Data Structures - Dr. Goldwasser
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int W(-1), T(-1), count(0);         // Width, Threshold, and count

void main() {
    while (W != 0) {
        ++count;                    // increment image count
        cin >> W;
        cin >> T;
        cout << "Image " << count << ":" << endl;
        //RECURSION!
    }
    return 0;
}
