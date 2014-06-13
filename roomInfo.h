#ifndef ROOMINFO_H
#define ROOMINFO_H

struct roomInfo
{
    int roomId;
    QString location;
    QString roomType;
    int renterId;//zuhu,出租状态
    int lessee;//fang dong
    int area;
    int realNum;//shiyong mianji
    QString circumstance;//zhuangxiu zhuangkuang  db fridge
    int price;
    QString remark;
}ri[256],temp;

void deleteOneRoomInfo(roomInfo *ri,int currentIndex,int *maxIndex)
{
    int num = currentIndex;
    while (num >= *maxIndex) {
        ri[num - 1] = ri[num];
        num = num + 1;
    }
    *maxIndex = *maxIndex - 1;
}

#endif // ROOMINFO_H
