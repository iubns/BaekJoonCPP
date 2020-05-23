[#1016. 제곱 ㄴㄴ 수](https://www.acmicpc.net/problem/1016)
![solve](https://img.shields.io/badge/solve-success-brightgreen)
![trial](https://img.shields.io/badge/trial-at%20ninetimes-green)
![difficulty](https://img.shields.io/badge/difficulty-easy-brightgreen)
---------------------------
  
## 문제 (Problem)
> 어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. min과 max가 주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

## 입력 (Input)  
> 첫째 줄에 min과 max가 주어진다. min은 1보다 크거나 같고, 1,000,000,000,000보다 작거나 같은 자연수이고, max는 min보다 크거나 같고, min+1,000,000보다 작거나 같은 자연수이다.

## 출력 (Output)  
> 첫째 줄에 [min,max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다.

## 예제 입력 (Exercise)  
> 1 10

## 기타 (ETC)
> 제곱수가 아닌 제곱으로 나누어 떨어지는 수임, 따라서 제곱수를 구해서 모든 숫자가 나누어 떨어지는지 알아봐야함,
> 하지만 꼭 계산을 할 필요는 없음, 2로 나누어 떨어지는 수들은 2칸씩 떨어져 있고 3으로 나누어 떨어지는 수는 3칸씩 떨어져 있음으로 굳이 연산 없이 그냥 3칸 뒤로 가면 됨,
> 그리고! 경계 조건 잘 확인 할 것! ( 이것 때문에 4번 기회 더 썼다.)