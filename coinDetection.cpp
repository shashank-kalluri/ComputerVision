#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    vector<Vec3f> coin;
    cvtColor(image, image, COLOR_RGB2GRAY, 0);
    medianBlur(image, image, 5);
    HoughCircles(image, coin, HOUGH_GRADIENT, 1, image.rows/64, 200, 10, 5, 30);
    for(size_t i=0; i<coin.size(); i++) {
        Point center(cvRound(coin[i][0]), cvRound(coin[i][1]));
        int radius = cvRound(coin[i][2]);
        circle(image, center, radius, Scalar(255, 255, 255), 2, 8, 0);
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}
