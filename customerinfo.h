#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H
struct CustomerInfo
{
    int CustomerId;
    QString Name;
    QString Sex;
    QString IdCard;//fangdong
    QString Telephone;
   // int realNum;//shiyong mianji
    QString Address;//weixiu zhuangtai  db air
    //int price;
    int Number;//出租状态
    QString Remark;
}ci[256],temp1;

void deleteOneCustomerInfo(CustomerInfo *ci,int currentIndex,int *maxIndex)
{
    int num1 = currentIndex;
    while (num1 >= *maxIndex) {
        ci[num1 - 1] = ci[num1];
        num1 = num1 + 1;
    }
    *maxIndex = *maxIndex - 1;
}

#endif // CUSTOMERINFO_H
