//
//  main.cpp
//  test

//
//  Created by junyan on 12/14/16.
//  Copyright © 2016 junyan. All rights reserved.
//

/*

 第二题：Server Attack的题目。说你只有一个function，用这个function来察觉有没有在攻击服务器。这个function return bool,
 每次有一个server request这个function都会被call. 然后告诉我这个function will return true如果在5秒内有10次以上的request。
 这个题我一开始给出的方法是用一个time和count来看，每5秒更新一次time并重设count为0. 但是面试官指出这个方法对于这种情况不行:
 {0 1 2 3 4 5.5 5.5 5.5 5.5 5.5 5.5}。在这种情况下我的function会给false 但是其实应该是true，因为我的function会在第一个5.5上reset。
 然后我就纠结了半天，面试官给了一些提示，最后才想出用一个window卡住10个request 然后每一次只看头和尾的时间差，如果是小于5秒就证明有server attack。
 这个window用queue来做。因为时间到了，所以面试官让我解释一下我的算法，没有写代码，然后第一轮结束。

 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class Server{
public:
    Server(){
        this->time = 5;
        this->freq = 10;
    }

    void access(int timestamp){
        while (!q.empty() && (q.front() < timestamp - time || q.size() > freq)) {
            q.pop();
        }
        q.push(timestamp);
    }

    bool if_attack(){
        return q.size() >= freq;
    }


public:
    int time;
    int freq;
    queue<int> q;
};
