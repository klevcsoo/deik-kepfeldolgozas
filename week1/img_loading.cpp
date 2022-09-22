//
// Created by Keve Lajsz on 2022. 09. 08..
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

void brighten_grayscale(const cv::Mat& in_img, cv::Mat& out_img) {
    out_img = in_img + 100;
}

void invert_grayscale(const cv::Mat& in_img, cv::Mat& out_img) {
    out_img = 255 - in_img;
}

void brighten_colour(const cv::Mat& in_img, cv::Mat& out_img) {
    out_img = in_img + cv::Scalar(100, 100, 100);
}

void invert_colour(const cv::Mat& in_img, cv::Mat& out_img) {
    out_img = cv::Scalar(255, 255, 255) - in_img;
}

int main() {
    std::cout << "OpenCV version: " << cv::getVersionString() << std::endl;

    std::string p = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week1/testimg.jpg";
    cv::Mat img = cv::imread(p, cv::IMREAD_COLOR);
    std::cout << "Image resolution: " << img.cols << "x" << img.rows << std::endl;

    if (img.type() == CV_8UC1) {
        std::cout << "8-bit monochrome" << std::endl;
    } else if (img.type() == CV_8UC3) {
        std::cout << "24-bit RGB" << std::endl;
    } else {
        std::cout << img.type() << std::endl;
    }

    cv::imshow("Normal image", img);

    cv::Mat img_b;
    brighten_colour(img, img_b);
    cv::imshow("Brightened image", img_b);

    cv::Mat img_i;
    invert_colour(img, img_i);
    cv::imshow("Inverted image", img_i);

    cv::waitKey();

    return 0;
}
