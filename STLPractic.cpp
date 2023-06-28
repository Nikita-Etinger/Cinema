
#include "Param.h"
#include "Cinema.h"
#include "JsonReader.h"












int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string str = "\"pathImg\": \"./img/1.jpg\", \"rating\": 7.8, \"subscription\": true, \"top10\": false, \"category\": [\"Новинки 2023\", \"Рекомендации\", \"Лучшее\"]";
    Cinema cinema();
    Theater theater;
    reader("cinema.json",theater);
    theater.showAllCinemas();
    

}

