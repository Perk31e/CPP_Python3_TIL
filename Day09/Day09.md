# 도전할 문제 **백준 2437**

## **백준 2437** (https://www.acmicpc.net/problem/2437) 도전

## 문제 - 백준 2437

1. 주어진 추들을 이용하여 측정할 수 없는 양의 정수 무게 중 최소값을 구하는 문제
2. 추들을 임의로 조합하여 사용할 수 있음 (추를 여러 번 사용하는 것이 아닌, 추들의 조합)

## 접근 방식

### 첫 번째 도전(baekjoon-2437.cpp, baekjoon-2437.py)

그리디 알고리즘 활용

- 추들을 오름차순으로 정렬한 후, 현재까지 만들 수 있는 연속된 무게의 범위를 추적
- 만약 다음 추의 무게가 현재까지 만들 수 있는 최대 무게+1보다 크다면, 그 사이에 만들 수 없는 무게가 존재

`핵심 아이디어`

- 무게가 1부터 target-1까지 모두 측정 가능할 때
- 새로운 추 weight를 추가하면
- 무게가 1부터 target+weight-1까지 모두 측정 가능해짐

## 배운 점

- 그리디 알고리즘으로 풀 수 있는 문제 유형 학습
- 정렬 후 순차적으로 처리하는 방식의 효율성
- 연속된 수의 범위를 추적하는 테크닉
- 문제를 단순화하여 효율적인 알고리즘 설계하는 방법
