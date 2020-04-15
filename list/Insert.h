//
// Created by 陈桐 on 2020/4/15.
//

#ifndef LEETCODE_INSERT_H
#define LEETCODE_INSERT_H

#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

class Insert {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> nums2) {

        set<int> record;
        for (int i = 0; i < nums1.size(); i++) {
            record.insert(nums1[i]);
        }

        set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++) {
            if (record.find(nums2[i]) != record.end()) { // record找到值
                resultSet.insert(nums2[i]);
            }
        }

        vector<int> resultVector;

        for (auto item :resultSet) {
            resultVector.push_back(item);
        }

        return resultVector;
    }

    vector<int> intersection1(vector<int> &nums1, vector<int> nums2) {

        //O(nlogn)
        set<int> record(nums1.begin(), nums1.end());
        set<int> resultSet;

        //O(nlogn)
        for (auto item : nums2) {
            if (record.find(item) != record.end()) { // record找到值
                resultSet.insert(item);
            }
        }
        //O(n)
        return vector<int>(resultSet.begin(), resultSet.end());
    }

    //哈希表 失去数据顺序性


};


#endif //LEETCODE_INSERT_H
