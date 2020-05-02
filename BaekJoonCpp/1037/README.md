[#1037. 약수](https://www.acmicpc.net/problem/1037)
![solve](https://img.shields.io/badge/solve-success-brightgreen)
![trial](https://img.shields.io/badge/trial-at%20once-green)
![difficulty](https://img.shields.io/badge/difficulty-easy-brightgreen)
---------------------------
  
## 문제 (Problem)
> 양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

## 입력 (Input)  
> 첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 1,000,000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.

## 출력 (Output)  
> 첫째 줄에 N을 출력한다. N은 항상 32비트 부호있는 정수로 표현할 수 있다.

## 예제 입력 (Exercise)  
> 2
> 4 2

## 기타 (ETC)
> 사실 생각해보면, 제일 작은 수는 N에서 제일 작은 소수이며 제일 큰 수는 N에서 제일 작은 소수를 뺀 수
> 따라서 그냥 둘이 곱하면 N이다.