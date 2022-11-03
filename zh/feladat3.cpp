#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    std::string in_p = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/btn_c.jpg";
    cv::Mat btn = cv::imread(in_p);

    cv::Mat gray;
    cv::cvtColor(btn, gray, cv::COLOR_BGR2GRAY);
    std::string out_p_g = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/gray_stud.png";
    cv::imwrite(out_p_g, gray);

    cv::Mat median;
    cv::medianBlur(btn, median, 7);
    std::string out_p_m = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/zh/filtered_stud.png";
    cv::imwrite(out_p_m, median);

    cv::Mat g_ch, mask;
    cv::extractChannel(btn, g_ch, 1);
    cv::threshold(g_ch, mask, 150, 255, cv::THRESH_BINARY);
    cv::imshow("gmask", g_ch);
    cv::waitKey();
//    std::vector<std::vector<cv::Point>> cont;

    return 0;
}
