#include<iostream>
#include"fulfill.h"
int main(void)
{
    char str[MAX];
    int result;
    std::cout << "��������ʽ��ĩβ�����Ⱥţ�" << std::endl;
    std::cin.get(str,MAX);
    result = fun(str);
    std::cout << result << std::endl;
    return 0;
}
