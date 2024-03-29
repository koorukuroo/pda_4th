# AWS EC2 성능 측정
## 주제
### 크롤링 속도 측정
각 EC2 인스턴스 유형에 따라 [네이버 증권](https://m.stock.naver.com/)에 크롤링 요청을 100번 보냈을 때 초당 요청횟수(requests/seconds)를 측정한다.

<br>


# 비교 스펙
## 차이점

### 1. 아키텍처
`Intel(x86)` &nbsp; vs &nbsp; `ARM`

### 2. 인스턴스 유형
`T`&nbsp;  vs &nbsp; `M`&nbsp;  vs&nbsp; `C`
### 3. 각 유형별 크기
`large` &nbsp; vs &nbsp; `xlarge`



## 공통점
- OS (Ubuntu)
- 스토리지 (16G, gp3)

<br>


# 결과


요청이 100번인 경우 시간 비교 결과

![image](https://github.com/koorukuroo/pda_4th/assets/56223389/928ee66c-af17-4ea3-9e09-f68b2346ffef)


| 아키텍처 | 인스턴스 유형 | 초당 요청 횟수(requests/sec) | 1번의 요청당 평균 시간 (seconds)|
|----------|---------------|---------------------------|---------------------------|
| ARM      | t4g.large     | 5.36                      | 0.18664                  |
|          | m6g.large     | 5.55                      | 0.18006                  |
|          | c6g.large     | 5.36                      | 0.18671                  |
|          | t4g.xlarge    | 5.28                      | 0.18941                  |
|          | m6g.xlarge    | 5.56                      | 0.17990                  |
|          | c6g.xlarge    | 5.42                      | 0.18461                  |
| x86      | t2.large      | 5.08                      | 0.19669                  |
|          | m4.large      | 4.98                      | 0.20064                  |
|          | c2.large      | 5.66                      | 0.17678                  |
|          | t2.xlarge     | 5.07                      | 0.19721                  |
|          | m4.xlarge     | 4.84                      | 0.20650                  |
|          | c2.xlarge     | 5.44                      | 0.18387                  |


<br>


ARM에서는 m(범용), intel(x86)에서는 c가 초당 요청 횟수가 가장 많다.

large와 xlarge의 차이는 유의미하지 않다. 따라서 인스턴스 유형 별 크기는 성능에 영향을 끼치지 않는다.


c에서는 intel이 , 나머지(m, t)에서는 arm이 더 좋은 성능을 보였다.

<br>

# 결론



따라서 웹 크롤링을 하는 경우, 가장 초당 요청 횟수가 많은 유형 c에 아키텍처는 x86를 추천한다.

<br>

# 크롤링 코드
```python
import requests
import time

def measure_crawling_speed(url, num_requests):
    start_time = time.time()  # 시작 시간 기록
    for _ in range(num_requests):
        response = requests.get(url)  # 웹 페이지에 요청 보내기
    end_time = time.time()  # 끝 시간 기록
    elapsed_time = end_time - start_time  # 총 경과 시간 계산
    crawling_speed = num_requests / elapsed_time  # 크롤링 속도 계산
    time_per_request = elapsed_time / num_requests  # 1번의 요청당 평균 시간 계산
    return crawling_speed, time_per_request

if __name__ == "__main__":
    url = "https://m.stock.naver.com/"
    num_requests = 100
    
    speed, time_per_request = measure_crawling_speed(url, num_requests)
    print(f"크롤링 속도: {speed:.2f} requests/second")
    print(f"1번의 요청당 평균 시간: {time_per_request:.5f} seconds")

```

# 역할
인스턴스 아키텍처 기준으로 역할을 분담한다.
- KimRiun : Intel(x86)
- gariguri : ARM
