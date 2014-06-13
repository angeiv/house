#ifndef ROOMINFO_H
#define ROOMINFO_H

struct roomInfo
{
    int roomId;
    QString location;
    QString roomType;
    int renterId;//fangdong
    int area;
    int realNum;//shiyong mianji
    QString ratingNum;//weixiu zhuangtai  db air
    int price;
    int floor;//出租状态
    QString remark;
}ri[256];

#endif // ROOMINFO_H
