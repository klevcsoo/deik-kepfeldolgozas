#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void copy_foreground(const cv::Mat& fg, cv::Mat&  bg) {
    cv::resize(bg, bg, fg.size());

    const int threshold = 200;
    for (int i = 0; i < fg.rows; i++) {
        for (int j = 0; j < fg.cols; j++) {
            const auto& c = fg.at<cv::Vec3b>(i, j);
            if (c[0] < threshold || c[1] < threshold || c[2] < threshold) {
                bg.at<cv::Vec3b>(i, j) = c;
            }
        }
    }
}

int main() {
    std::string p_bg = "/Users/klevcsoo/Developer/"
                       "deik-kepfeldolgozas/week2/background.jpg";
    std::string p_k = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week2/kurama.jpg";

    cv::Mat img_bg = cv::imread(p_bg, cv::IMREAD_COLOR);
    cv::Mat img_k = cv::imread(p_k, cv::IMREAD_COLOR);

    if (img_bg.empty()) {
        std::cout << "Error: Missing background" << std::endl;
    }
    if (img_k.empty()) {
        std::cout << "Error: Missing kurama" << std::endl;
    }

//    cv::imshow("Background", img_bg);
//    cv::waitKey();
//    cv::imshow("Kurama", img_k);
//    cv::waitKey();

    copy_foreground(img_k, img_bg);
    cv::imshow("Result", img_bg);
    cv::waitKey();

    return 0;
}
