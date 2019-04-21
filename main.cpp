#include<iostream>
#include<vector>
#include<string.h>
#include<cmath>
#include<fstream>
#include<complex>


using namespace std;

void mandelbrot_set(int width, int height, int maxIter, int maxColor);
void julia_set(int width, int height, int maxIter, int maxColor, const complex<double>& C);

int main()
{
    int width = 600;
    int height = 600;
    int maxIterations = 255;
    int maxColor = 255;
    complex<double> C(0.355, 0.355);

    //mandelbrot_set(width, height, maxIterations, maxColor);
    julia_set(width, height, maxIterations, maxColor, C);

    return 0;
}

void mandelbrot_set(int width, int height, int maxIter, int maxColor)
{
    ofstream out;
    out.open("mandelbrot.ppm");
    out << "P3\n" << width << " " << height << "\n255" << endl;
    for(int i = 0 ; i < width ; ++i)
    {
        for(int j = 0 ; j < height ; ++j)
        {
            complex<double> C((double)i/width - 1.5, (double)j/height - 0.5);
            complex<double> Z(-0., 0.);
            int iterations = 0;

            while(abs(Z) < 2.0 && iterations < maxIter)
            {
                Z = Z * Z + C;
                iterations++;
            }
            if(iterations < maxIter)
                out << 255 * iterations/maxIter << " " << '0' << " " << '0' << endl;
            else
                out << '0' << " " << '0' << " " << '0' << endl;
        }
    }
    out.close();
}


void julia_set(int width, int height, int maxIter, int maxColor, const complex<double>& C)
{
    ofstream out;
    out.open("julia.ppm");
    out << "P3\n" << width << " " << height << "\n255" << endl;
    for(int i = 0 ; i < width ; ++i)
    {
        for(int j = 0 ; j < height ; ++j)
        {
            complex<double> Z((double)i/width - 0.5, (double)j/height - 0.5);
            int iterations = 0;

            while(abs(Z) < 4.0 && iterations < maxIter)
            {
                Z = Z * Z + C;
                iterations++;
            }
            if(iterations < maxIter)
                out << '0' << " " << 255*iterations/maxIter << " " << '0' << endl;
            else
                out << '0' << " " << '0' << " " << '0' << endl;
        }
    }
    out.close();
}