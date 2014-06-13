#ifndef ROOMINFO_H
#define ROOMINFO_H

struct roomInfo
{
    int roomId;
    char location[50];
    char roomType[20];
    int area;
    int realNum;
    int ratingNum;
    int price;
    int floor;//出租状态
    char remark[100];
};

#endif // ROOMINFO_H
