# 도전할 문제 **백준 2559**

## **백준 14995** (https://www.acmicpc.net/problem/2559) 도전

## 문제 - 백준 2559

N일 동안의 온도가 주어짐
연속된 K일 동안의 온도 합이 최대가 되는 값을 찾는 문제

## 접근 방식

### 첫 번째 도전(baekjoon-2559.py)

풀이 방식: 구현 - 2중 반복문 활용
문제점: 각 시작점마다 k일의 합을 매번 새로 계산하므로 비효율적

### 두 번째 도전(baekjoon-2559-slidingwindow.py)

풀이 방식: 구현 - 슬라이딩 윈도우 활용
개선점: 이전 윈도우의 결과를 활용하여 중복 계산 제거

### 세 번째 도전(baekjoon-2559.cpp)

풀이 방식: 구현 - 슬라이딩 윈도우 활용

## 배운 점

** C++에서는 sum이 존재하지 않는다!!**

1. **accumulate**
   - 세 개의 인자를 받음: 시작 반복자, 끝 반복자, 초기값
   - 사용 예: accumulate(vec.begin(), vec.end(), 0)
   - 추가 장점: 커스텀 연산도 지원 (덧셈 외에 다른 연산도 가능)
2. **sum(별도 함수로 존재하지 않음)**
   - C++ 표준 라이브러리에는 Python의 sum()과 같은 함수가 없음
   - C++20에서 추가된 std::ranges::sum을 사용하거나 <numeric> 헤더의 accumulate를 사용해야 함
