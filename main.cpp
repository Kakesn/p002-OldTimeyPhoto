#include <iostream>
#include <fstream>
#include "bitmap.h"
#include <cstdlib>
#include <vector> 
#include <string>

using namespace std; 

int main()
{ 

    Bitmap image; 
    vector <vector <Pixel> > bmp; 
    Pixel rgbavg;
    bool validBmp; 
    string file;
    
    do {
    cout << "Please enter file name"<< endl;
    cin >> file; image.open(file); 
    validBmp = image.isImage();
    }
    while (validBmp != true);
    
    if (validBmp == true) { 
    bmp = image.toPixelMatrix(); 
    for (int i = 0; i < bmp.size(); i++) { 
    for (int j =0; j <bmp[i].size(); j++) {
    
    rgbavg = bmp[i][j]; 
    int avg = (rgbavg.red + rgbavg.green + rgbavg.blue)/3;
    rgbavg.red = avg;
    rgbavg.green = avg; 
    rgbavg.blue = avg; 
    bmp[i][j] = rgbavg;
    }
    }
    image.fromPixelMatrix(bmp);
    image.save("OldTimers.bmp");
    }
    
    return 0; 
}
