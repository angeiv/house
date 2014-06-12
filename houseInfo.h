#ifndef HOUSEINFO_H
#define HOUSEINFO_H
struct houseInfo
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
}ho[256];
#endif // HOUSEINFO_H
