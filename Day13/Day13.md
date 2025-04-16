# 도전할 문제 **프로그래머스 JadenCase 문자열 만들기**

## **프로그래머스 JadenCase 문자열 만들기** (https://programmers.co.kr/learn/courses/30/lessons/12951)

## 문제

JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다.
문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수를 완성하는 문제입니다.

## 접근 방식

### 첫 번째 도전 (programmers-jadencase.cpp)

풀이 방식: 문자열을 공백으로 분리한 후, 각 단어의 첫 글자는 대문자로, 나머지는 소문자로 변환

```cpp
// split 함수: 문자열을 공백 기준으로 분할
vector<string> split(string target) {
    vector<string> result;
    int start = 0;
    while (true) {
        int idx = target.find(" ", start);
        if (idx == string::npos) {
            result.push_back(target.substr(start));
            break;
        } else {
            int length = idx - start;
            result.push_back(target.substr(start, length));
            start = idx + 1;
        }
    }
    return result;
}

// 핵심 로직
for (int i = 0; i < test.size(); i++) {
    for (int j = 0; j < test[i].length(); j++) {
        if (j == 0) {
            // 첫 글자 대문자 변환 (ASCII 코드 사용)
            if (static_cast<int>(test[i][0]) >= 97 && static_cast<int>(test[i][0]) <= 122) {
                test[i][j] = test[i][j] - 32;
            }
        } else {
            // 나머지 글자 소문자 변환 (ASCII 코드 사용)
            if (static_cast<int>(test[i][j]) >= 65 && static_cast<int>(test[i][j]) <= 90) {
                test[i][j] = test[i][j] + 32;
            }
        }
    }
}
```

### 두 번째 도전 (programmers-jadencase-new_ver.cpp)

풀이 방식: 동일한 접근법이지만, 문자 비교 방식을 개선

```cpp
// 핵심 로직
for (int i = 0; i < test.size(); i++) {
    for (int j = 0; j < test[i].length(); j++) {
        if (j == 0) {
            // 첫 글자는 대문자로 변환 (문자 리터럴 직접 비교)
            if (test[i][j] >= 'a' && test[i][j] <= 'z') {
                test[i][j] = test[i][j] - 32;
            }
        } else {
            // 나머지 글자는 소문자로 변환 (문자 리터럴 직접 비교)
            if (test[i][j] >= 'A' && test[i][j] <= 'Z') {
                test[i][j] = test[i][j] + 32;
            }
        }
    }
}
```

## 깨달은 점

**문자 처리의 효율적인 방법**

1. **ASCII 코드 변환 없이 직접 비교 가능**

   - C++에서는 문자 자체를 직접 비교할 수 있음
   - `if(ch >= 'a' && ch <= 'z')` 같은 방식이 더 직관적임

2. **문자 변환의 간결한 표현**

   - 대소문자 변환도 ASCII 값 차이(32)를 더하거나 빼는 것으로 간단히 처리 가능
   - 대문자로 변환: `ch - 32` 또는 `ch - ('a' - 'A')`
   - 소문자로 변환: `ch + 32` 또는 `ch + ('a' - 'A')`

3. **가독성과 유지보수성**

   - ASCII 코드 번호(97, 65 등)보다 문자 리터럴('a', 'A' 등)을 사용하는 것이 가독성이 높음
   - 코드의 의도가 더 명확하게 전달됨

4. **C++ 문자 처리에 익숙해질 필요성**
   - 문자 처리 시 직관적인 방식을 사용하여 코드 품질 향상 가능
   - 숫자 대신 문자 리터럴 사용에 익숙해질 필요가 있음
