/*
 * @Author: Kk-knight liubin999000@163.com
 * @Date: 2023-02-21 21:10:07
 * @LastEditors: Kk-knight liubin999000@163.com
 * @LastEditTime: 2023-02-21 22:01:19
 * @FilePath: /perf_test/perf_test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "clock.h"
#include <unistd.h>
#include <thread>

#define SWAP(a, b) {a ^= b; b ^= a; a ^= b;}

int CalculatFunc() {
    int count = 100;
    int a = 123;
    int b = 456;
    Clock clock;

    clock.Start();
    for (int i = 0; i < count; i++) {
        SWAP(a, b);
    }
    clock.Stop();
    clock.PrintInfo();

    return 0;
}


int SleepFunc() {
    int count = 100;
    int a = 123;
    int b = 456;
    Clock clock;

    clock.Start();
    for (int i = 0; i < count; i++) {
        SWAP(a, b);
    }
    usleep(100 * 1000);//100ms
    clock.Stop();
    clock.PrintInfo();

    return 0;
}

int MultiTHreadFunc() {
    int count = 100;
    int a = 123;
    int b = 456;
    Clock clock;

    clock.Start();

    auto t = std::thread([&] {
        for (int i = 0; i < count; i++) {
        SWAP(a, b);
    }
    });

    for (int i = 0; i < count; i++) {
        SWAP(a, b);
    }
    t.join();
    clock.Stop();
    clock.PrintInfo();

    return 0;
}

int main(int argc, char *argv[]) {

    CalculatFunc();
    SleepFunc();
    MultiTHreadFunc();

    return 0;
}