/*
 * Author(s):   Alex Reinisch and Nick Walker 
 * Date(s):     28-02 March-April 2012
 * Prog05 - Data Structures - Dr. Goldwasser
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* 
 * Initialize Variables
 */
double W(-1), T(-1), n(0);              // Width, Threshold, and n
vector<string> image;                   // store image as string vector

/*
 * imagesum
 * The goal of imagesum is to find the
 * sum of the values in the current
 * portion of the image.
 */
double imagesum(int rl, int rh,         // row bounds (low/high)
                int cl, int ch,         // column bounds (low/high)
                vector<string>& image   // image as string vector
        ) {
    double sum=0;
    for (double r = rl; r < rh; r++) {
        for (double c = cl; c < ch; c++) {
            sum+= image[r][c];          // sum the elements
            sum-= 48;                   // subtract the ASCII value of 0
        }
    }
    return sum;
}

/*
 * lossy
 * This is where the work gets done.
 * We check to see if the portion of the
 * image is past Threshold and can be
 * compressed. If not, the image is 
 * split into quarters with a call to
 * lossy on each quarter.
 */
void lossy(double rl, double rh,        // row bounds (low/high)
            double cl, double ch,       // column bounds (low/high)
            const double& T,            // compression threshold
            vector<string>& image       // image as string vector
        ) {
    double sum = imagesum(rl, rh, cl, ch, image);       // sum for portion of image
    if (((sum/((rh-rl)*(ch-cl)))*100) >= T) {           // if % of 1s > Threshold
        for (double r = rl; r < rh; r++) {
            for (double c = cl; c < ch; c++) {
                image[r][c] = '1';                      // change part of image to 1s
            }
        }
    }
    else if (((1-(sum/((rh-rl)*(ch-cl))))*100) >= T) {  // if % of 0s > Threshold
        for (double r = rl; r < rh; r++) {
            for (double c = cl; c < ch; c++) {
                image[r][c] = '0';                      // change part of image to 0s
            }
        }
    }
    else {
        lossy(rl, ((rh-rl)/2), (cl+((ch-cl)/2)), ch, T, image);     // top-right
        lossy(rl, ((rh-rl)/2), cl, ((ch-cl)/2), T, image);          // top-left
        lossy((rl+((rh-rl)/2)), rh, cl, ((ch-cl)/2), T, image);     // bottom-left
        lossy((rl+((rh-rl)/2)), rh, (cl+((ch-cl)/2)), ch, T, image);// bottom-right
    }
}

/*
 * main
 * Here, we keep track of the number of
 * images that have been passed, 
 * compress (if possible) and print 
 * images. This is repeated until the 
 * user inputs a Width of 0.
 */
int main() {
    cin >> W;                           // finds first width (0 for exit)
    while (W != 0) {
        image.resize(W);                // size image vector to Width
        ++n;                            // increment image count
        cin >> T;                       // find Threshold
        for (vector<double>::size_type i = 0; i < W; i++) {
            cin >> image[i];            // fill string vector with image data
        }
        cout << "Image " << n << ":" << endl;
        lossy(0, W, 0, W, T, image);    // RECURSION!
        for (int r = 0; r < W; r++) {
            cout << image[r] << endl;   // prints the image to the screen
        }
        image.clear();                  // clears image for next loop
        cin >> W;                       // finds next width (0 for exit)
    }
    return 0;
}
