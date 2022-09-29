#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// For the orange1.jpg
void copy_foreground(const cv::Mat& src, cv::Mat& dst, const int type = CV_8UC3) {
    if (dst.empty()) {
        dst.create(src.size(), type);
        dst.setTo(0);
    } else {
        cv::resize(dst, dst, src.size());
    }

    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            const auto& c = src.at<cv::Vec3b>(i, j);
            if (c[2] > c[0] && c[2] > c[1]) {
                dst.at<cv::Vec3b>(i, j) = c;
            }
        }
    }
}

int main() {
    std::string p_bg = "/Users/klevcsoo/Developer/"
                       "deik-kepfeldolgozas/week2/background.jpg";
    std::string p_o = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week2/orange1.jpg";

    cv::Mat img_bg = cv::imread(p_bg, cv::IMREAD_COLOR);
    cv::Mat img_o = cv::imread(p_o, cv::IMREAD_COLOR);

    if (img_bg.empty()) {
        std::cout << "Error: Missing background" << std::endl;
    }
    if (img_o.empty()) {
        std::cout << "Error: Missing kurama" << std::endl;
    }

//    cv::imshow("Background", img_bg);
//    cv::waitKey();
//    cv::imshow("Kurama", img_o);
//    cv::waitKey();

    copy_foreground(img_o, img_bg);
    cv::imshow("Result", img_bg);
    cv::waitKey();

    return 0;
}
