[#1182. 부분수열의 합](https://www.acmicpc.net/problem/1182)  
![solve](https://img.shields.io/badge/solve-failed-brightgreen)
![trial](https://img.shields.io/badge/trial-at%20once-green)
![difficulty](https://img.shields.io/badge/difficulty-easy-brightgreen)
---------------------------
  
## 문제 (Problem)
> N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

## 입력 (Input)  
> 첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

## 출력 (Output)  
> 첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

## 예제 입력 (Exercise)  
> 5 0
> -7 -3 -2 5 8


## 기타 (ETC)
> 시간 초과 문제 발생, verctor에 값을 빼고 넣는 과정을 생략할 필요가 있을듯 하다.
> 또한 target 값과 현재 값의 차이(양,음)을 보고 한쪽의 값만 돌려도 됨, 집에 가서 로직 변경. 