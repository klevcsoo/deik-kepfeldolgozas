//
// Created by Keve Lajsz on 2022. 09. 08..
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main() {
    std::cout << "OpenCV version: " << cv::getVersionString() << std::endl;

    std::string p = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week1/testimg.jpg";
    cv::Mat img = cv::imread(p);
    std::cout << "Image resolution: " << img.cols << "x" << img.rows << std::endl;

    {
        using namespace cv;
        if (img.type() == CV_8UC1) {
            std::cout << "8-bit monochrome" << std::endl;
        } else if (img.type() == CV_8UC3) {
            std::cout << "24-bit RGB" << std::endl;
        } else {
            std::cout << img.type() << std::endl;
        }
    }

    cv::imshow("OpenCV picture", img);
    cv::waitKey();

    return 0;
}
