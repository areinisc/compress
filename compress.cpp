/*
 * Author(s):   Alex Reinisch and Nick Walker 
 * Date(s):     28-02 March-April 2012
 * Prog05 - Data Structures - Dr. Goldwasser
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int W(-1), T(-1), n(0);         // Width, Threshold, and n
vector<string> image;           // store image as string vector

void lossy( const int& W,       // image width
            const int& T,       // compression threshold
            const vector<string>& image // image as string vector
        ) {
    cout << "RECURSION!" << endl;
}

int main() {
    cin >> W;
    while (W != 0) {
        image.resize(W);        // size image vector to Width
        ++n;                    // increment image count
        cin >> T;               // find Threshold
        for (vector<double>::size_type i = 0; i < W; i++) {
            cin >> image[i];    // fill string vector with image data
        }
        cout << "Image " << n << ":" << endl;
        lossy(W, T, image);     // RECURSION!
        image.clear();          // clears image for next loop
        cin >> W;               // finds next width(0 for exit)
    }
    return 0;
}