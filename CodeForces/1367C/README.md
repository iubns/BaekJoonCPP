[#1367C. Social Distance](http://codeforces.com/contest/1367/problem/C)
![solve](https://img.shields.io/badge/solve-fail-brightgreen)
![trial](https://img.shields.io/badge/trial-at%20ninth-green)
![difficulty](https://img.shields.io/badge/difficulty-easy-brightgreen)
---------------------------
  
## 문제 (Problem)
> Polycarp and his friends want to visit a new restaurant. The restaurant has n tables arranged along a straight line. People are already sitting at some tables. The tables are numbered from 1 to n in the order from left to right. The state of the restaurant is described by a string of length n which contains characters "1" (the table is occupied) and "0" (the table is empty).
> 
> Restaurant rules prohibit people to sit at a distance of k or less from each other. That is, if a person sits at the table number i, then all tables with numbers from i−k to i+k (except for the i-th) should be free. In other words, the absolute difference of the numbers of any two occupied tables must be strictly greater than k.
> 
> For example, if n=8 and k=2, then:
> 
> strings "10010001", "10000010", "00000000", "00100000" satisfy the rules of the restaurant;
> strings "10100100", "10011001", "11111111" do not satisfy to the rules of the restaurant, since each of them has a pair of "1" with a distance less than or equal to k=2.
> In particular, if the state of the restaurant is described by a string without "1" or a string with one "1", then the requirement of the restaurant is satisfied.
> 
> You are given a binary string s that describes the current state of the restaurant. It is guaranteed that the rules of the restaurant are satisfied for the string s.
> 
> Find the maximum number of free tables that you can occupy so as not to violate the rules of the restaurant. Formally, what is the maximum number of "0" that can be replaced by "1" such that the requirement will still be satisfied?
> 
> For example, if n=6, k=1, s= "100010", then the answer to the problem will be 1, since only the table at position 3 can be occupied such that the rules are still satisfied.

## 입력 (Input)  
> The first line contains a single integer t (1≤t≤104) — the number of test cases in the test. Then t test cases follow.
> 
> Each test case starts with a line containing two integers n and k (1≤k≤n≤2⋅105) — the number of tables in the restaurant and the minimum allowed distance between two people.
> 
> The second line of each test case contains a binary string s of length n consisting of "0" and "1" — a description of the free and occupied tables in the restaurant. The given string satisfy to the rules of the restaurant — the difference between indices of any two "1" is more than k.
> 
> The sum of n for all test cases in one test does not exceed 2⋅105.

## 출력 (Output)  
> For each test case output one integer — the number of tables that you can occupy so as not to violate the rules of the restaurant. If additional tables cannot be taken, then, obviously, you need to output 0.

## 예제 입력 (Exercise)  
> 6
> 6 1
> 100010
> 6 2
> 000000
> 5 1
> 10101
> 3 1
> 001
> 2 2
> 00
> 1 1
> 0

## 기타 (ETC)
> 최적화를 시키는 방법으로 변경하는 과정에서 버그가 많았음, 아에 처음부터 시간 및 bigO를 생각해보고 최적화를 한 뒤 코딩이 좋을 듯