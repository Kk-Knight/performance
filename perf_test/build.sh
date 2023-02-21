#!/bin/bash
###
 # @Author: Kk-knight liubin999000@163.com
 # @Date: 2023-02-21 21:53:27
 # @LastEditors: Kk-knight liubin999000@163.com
 # @LastEditTime: 2023-02-21 21:54:28
 # @FilePath: /perf_test/build.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 


set -e

rm -rf output/

rm -rf build/

mkdir build

cd build
cmake ..
make
