#include <iostream>
#include "bitmap.h"
#include <string>
#include <vector>

using namespace std;

#define OUTPUT_FILENAME "oldtimey.bmp"
#define WHITE 255
#define BLACK 0
#define BORDER_SIZE 5
#define DOUBLE_BORDER_SIZE BORDER_SIZE * 2

void convertGreyScale(PixelMatrix& pixelMatrix);
void addBorder(PixelMatrix& pixelMatrix);
int main()
{

Bitmap image;

vector <vector <Pixel> > bmp;
string filename;
cout << "Please enter the file name of bitmap: ";
getline(cin, filename);
image.open(filename);

while (!image.isImage())
{
cout << "Please enter the file name of bitmap: ";
getline(cin, filename);
image.open(filename);
}
PixelMatrix pixelMatrix = image.toPixelMatrix();
convertGreyScale(pixelMatrix);
addBorder(pixelMatrix);
image.fromPixelMatrix(pixelMatrix);
image.save(OUTPUT_FILENAME);

return 0;
}

void convertGreyScale(PixelMatrix& pixelMatrix){
for(unsigned int row = 0; row < pixelMatrix.size(); row++)
{
for(unsigned int column=0; column < pixelMatrix[row].size(); column++)
{
Pixel current = pixelMatrix[row][column];
double avg = ((double)(current.red + current.blue + current.green)) /
3.0;

pixelMatrix[row][column].red = (int)avg;
pixelMatrix[row][column].blue = (int)avg;
pixelMatrix[row][column].green = (int)avg;
}
}
}
void addBorder(PixelMatrix& pixelMatrix){
for(int row = 0; row < pixelMatrix.size(); row++)
{
for(int column=0; column < pixelMatrix[row].size(); column++)
{
if (row < DOUBLE_BORDER_SIZE || row > pixelMatrix.size() -
DOUBLE_BORDER_SIZE ||
column < DOUBLE_BORDER_SIZE || column > pixelMatrix[row].size() -
DOUBLE_BORDER_SIZE)
{
pixelMatrix[row][column].red = BLACK;
pixelMatrix[row][column].blue = BLACK;
pixelMatrix[row][column].green = BLACK;
}
}
}

for(int row = 0; row < pixelMatrix.size(); row++)
{

for(int column=0; column < pixelMatrix[row].size(); column++)
{

if (row < BORDER_SIZE || row > pixelMatrix.size() - BORDER_SIZE ||
column < BORDER_SIZE || column > pixelMatrix[row].size() -
BORDER_SIZE)
{
pixelMatrix[row][column].red = WHITE;
pixelMatrix[row][column].blue = WHITE;
pixelMatrix[row][column].green = WHITE;
}
}
}
}
