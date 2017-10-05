#include <iostream>
#include "bitmap.h"
#include <string>
#include <vector>
using namespace std;
 int main ()
  {
Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;
image.open("machupicchu.bmp");
bmp = image.toPixelMatrix();
cout<<"machupicchu.bmp has been loaded. it is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<<" pixels high."<<endl;

         return 0;
          }

