[#9663. N-Queen](https://www.acmicpc.net/problem/9663)
![solve](https://img.shields.io/badge/solve-filed-brightgreen)
![trial](https://img.shields.io/badge/trial-at%20once-green)
![difficulty](https://img.shields.io/badge/difficulty-easy-brightgreen)
---------------------------
  
## 문제 (Problem)
> N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
> 
> N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

## 입력 (Input)  
> 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

## 출력 (Output)  
> 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

## 예제 입력 (Exercise)  
>8

## 기타 (ETC)
> 퀸을 놓는 경우의 수를 구하는 방법을 모르겠음
> 답지를 봐도 이해가 가지 않음, 현재 새벽 4시 40분 임으로 자고나서 다시 봐야겠음
> 
> n * n에 n개의 퀸이 들어가야 함으로 모든 n열에는 퀸이 들어가야함,
> 따라서 n개의 배열을 만들고 어느 행에만 들어갔는지 기록 하면 됨,
> 같은 행이거나 대각선이 아니면 다음 말을 둠,
> 모든 말을 두었다면 ++