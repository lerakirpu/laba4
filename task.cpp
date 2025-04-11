#include <iostream>  
#include <string>   
#include <opencv2/highgui.hpp>  // Для работы с изображениями и GUI (функции imshow, imread)
#include <opencv2/imgproc.hpp>   // Для обработки изображений (функции cvtColor, transform)

void sepia(cv::Mat img) {
    // Создаем глубокую копию исходного изображения, чтобы не изменять оригинал
    cv::Mat res = img.clone();

    // Конвертируем цветовое пространство из BGR в RGB
    cv::cvtColor(res, res, cv::COLOR_BGR2RGB);

    // Применяем матричное преобразование для создания сепийного эффекта
    cv::transform(res, res, cv::Matx33f(
        0.393, 0.769, 0.189,  // Коэффициенты для красного канала
        0.349, 0.686, 0.168,  // Коэффициенты для зеленого канала
        0.272, 0.534, 0.131   // Коэффициенты для синего канала
    ));

    // Конвертируем обратно в BGR, так как OpenCV ожидает изображение в этом формате
    cv::cvtColor(res, res, cv::COLOR_RGB2BGR);

    // Отображаем оригинальное изображение в окне с названием "original"
    cv::imshow("original", img);
    
    // Отображаем обработанное изображение в окне с названием "Sepia"
    cv::imshow("Sepia", res);

    // Ждем нажатия любой клавиши 
    cv::waitKey(0);
    
    // Закрываем все открытые окна с изображениями
    cv::destroyAllWindows();
}

int main() {
    // Загружаем изображение из файла "1.jpg" в объект img
    cv::Mat img = cv::imread("1.jpg");

    if (img.empty()) {
        std::cerr << "Could not read the image" << std::endl;
        return 1;  
    }

    // Вызываем функцию sepia для обработки загруженного изображения
    sepia(img);

    return 0;
}
