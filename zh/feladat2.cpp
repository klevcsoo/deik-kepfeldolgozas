#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
    std::string in_p = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/blue_fish.jpg";
    cv::Mat blue_fish = cv::imread(in_p);
    cv::Mat filtered;
    cv::medianBlur(blue_fish, filtered, 5);
    std::string out_p_f = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/filtered_stud.png";
    cv::imwrite(out_p_f, filtered);

    cv::Mat hsv;
    cv::cvtColor(filtered, hsv, cv::COLOR_BGR2HSV);
    std::string out_p_h = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/hsv_stud.png";
    cv::imwrite(out_p_h, hsv);

    cv::Mat mask;
    cv::inRange(hsv, cv::Scalar(80, 10, 100), cv::Scalar(120, 255, 255), mask);
    std::string out_p_m = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/mask_stud.png";
    cv::imwrite(out_p_m, mask);

    cv::Mat result, mask3ch;
    result.create(blue_fish.size(), CV_8UC3);
    result.setTo(0);
    cv::cvtColor(mask, mask3ch, cv::COLOR_GRAY2BGR);
    for (int i = 0; i < mask3ch.rows; i++) {
        for (int j = 0; j < mask3ch.cols; j++) {
            cv::Vec3b c = mask3ch.at<cv::Vec3b>(i, j);
            if (c[2] > 250) {
                result.at<cv::Vec3b>(i, j) = blue_fish.at<cv::Vec3b>(i, j);
            }
        }
    }
    std::string out_p_r = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/result_stud.png";
    cv::imwrite(out_p_r, result);

    return 0;
}
