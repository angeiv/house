#ifndef WANTEDINFO_H
#define WANTEDINFO_H
struct wantedInfo
{
    int sj;
    int customerId;
    QString customerName;
    QString phoneNumber;//
    QString roomType;//
    int area;
    QString  circumstance;//shiyong mianji
   // QString circumstance;//zhuangxiu zhuangkuang  db fridge
    int price;
    int roomId;
    QString remark;

}wt[256],tem;
void deleteOneWantedInfo(wantedInfo *wt,int currentIndex,int *maxIndex)
{
    int num1 = currentIndex;
    while (num1 >= *maxIndex) {
        wt[num1 - 1] = wt[num1];
        num1 = num1 + 1;
    }
    *maxIndex = *maxIndex - 1;
}
#endif // WANTEDINFO_H
