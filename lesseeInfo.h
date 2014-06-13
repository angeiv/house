#ifndef LESSEEINFO_H
#define LESSEEINFO_H

struct lesseeInfo
{
    //按横向顺序
    int zuhuId;
    QString zuhuname;
    int xingbie;//性别
    QString worklocation;
    int telephone;
    int Idcard;//身份证
    int toll;//租住人数
    QString remark;
}li[256],temp;

void deleteOneLesseeInfo(lesseeInfo *li,int currentIndex,int *maxIndex)
{
    int num = currentIndex;
    while (num >= *maxIndex) {
        li[num - 1] = li[num];
        num = num + 1;
    }
    *maxIndex = *maxIndex - 1;
}

#endif // LESSEEINFO_H
