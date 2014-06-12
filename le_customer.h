#ifndef CUSTOMER_H
#define CUSTOMER_H

struct customer
{
    int customerId;
    QString customerName;
    QString nativePlace;
    QString phoneNumber;
    QString sex;//性别
    QString idCard;//身份证
    int number;//租住人数
    QString remark;
}li[256],temp_le;

void deleteOneLesseeInfo(customer *li,int currentIndex_le,int *maxIndex_le)
{
    int num = currentIndex_le;
    while (num >= *maxIndex_le) {
        li[num - 1] = li[num];
        num = num + 1;
    }
    *maxIndex_le = *maxIndex_le - 1;
}

#endif // CUSTOMER_H
