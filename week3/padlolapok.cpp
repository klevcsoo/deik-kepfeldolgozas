#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void convert(const cv::Mat& src, cv::Mat& dst) {
    cv::Mat srcf;
    src.convertTo(srcf, CV_32FC3, 1 / 255.0);
    cv::cvtColor(srcf, dst, cv::COLOR_BGR2HSV);
}

double comp(const cv::Mat& lab1, const cv::Mat& lab2) {
    cv::Mat diff1 = lab1 - lab2;
    cv::Mat diff2 = diff1.mul(diff1);
    std::vector<cv::Mat> chs;
    cv::split(diff2, chs);
    cv::Mat E;
    cv::sqrt(chs[0] + chs[1] + chs[2], E);
    return cv::mean(E)[0];
}

int main() {
    std::string pe = "/Users/klevcsoo/Developer/deik-kepfeldolgozas"
                     "/week4/padlolapok/etalon.png";
    cv::Mat etalon = cv::imread(pe, cv::IMREAD_COLOR);
    cv::Mat elab;
    convert(etalon, elab);
    cv::imshow("etalon", etalon);

    cv::Mat img, ilab;
    for (int i = 1; i <= 7; i++) {
        img = cv::imread(
                "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week4/padlolapok/fa_" +
                std::to_string(i) + ".png", cv::IMREAD_COLOR
        );
        convert(img, ilab);
        double dE = comp(elab, ilab);
        std::cout << i << " " << dE << std::endl;

        std::string win_name = "fa_" + std::to_string(i);
        cv::imshow(win_name, img);
        cv::moveWindow(win_name, 300, 10 + i * 60);
    }

    cv::waitKey();

    return 0;
}
