
#include "Param.h"
#include "Cinema.h"













int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str = "\"pathImg\": \"./img/1.jpg\", \"rating\": 7.8, \"subscription\": true, \"top10\": false, \"category\": [\"Новинки 2023\", \"Рекомендации\", \"Лучшее\"]";
    Cinema cinema(str);
    cinema.showInfo();
    

}

