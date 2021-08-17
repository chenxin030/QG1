#include<iostream>
#include"fulfill.h"
int main(void)
{
    char str[MAX];
    int result;
    std::cout << "请输入算式（末尾不带等号）" << std::endl;
    std::cin.get(str,MAX);
    result = fun(str);
    std::cout << result << std::endl;
    return 0;
}
