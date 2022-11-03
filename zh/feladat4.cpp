#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    std::string in_p = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/white_cat.jpg";
    cv::Mat white_cat = cv::imread(in_p, cv::IMREAD_GRAYSCALE);

    cv::Mat mask;
    cv::threshold(white_cat, mask, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
    cv::medianBlur(mask, mask, 1);

    std::string out_p = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/result_stud.png";
    cv::imwrite(out_p, mask);

    cv::waitKey();
    return 0;
}
