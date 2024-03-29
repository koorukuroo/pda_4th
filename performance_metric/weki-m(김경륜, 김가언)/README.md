# AWS EC2 성능 측정
## 주제
### 요청 속도 측정
각 EC2 인스턴스 유형에 따라 [네이버 증권](https://m.stock.naver.com/)에 요청을 100번 보냈을 때 초당 요청횟수(requests/seconds)와 총 요청시간(seconds)을 측정한다.

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


| 아키텍처 | 인스턴스 유형 | 초당 요청 횟수(requests/sec) |  요청 시간 (seconds)|
|----------|---------------|---------------------------|---------------------------|
| ARM      | t4g.large     | 5.36                      | 18.664                  |
|          | m6g.large     | 5.55                      | 18.006                  |
|          | c6g.large     | 5.36                      | 18.671                  |
|          | t4g.xlarge    | 5.28                      | 18.941                  |
|          | m6g.xlarge    | 5.56                      | 17.990                  |
|          | c6g.xlarge    | 5.42                      | 18.461                  |
| x86      | t2.large      | 5.08                      | 19.669                  |
|          | m4.large      | 4.98                      | 20.064                  |
|          | c4.large      | 5.66                      | 17.678                  |
|          | t2.xlarge     | 5.07                      | 19.721                  |
|          | m4.xlarge     | 4.84                      | 20.650                  |
|          | c4.xlarge     | 5.44                      | 18.387                  |


<br>


ARM에서는 m(범용), intel(x86)에서 c가 초당 요청 횟수가 가장 많았고, 총 요청시간이 가장 짧은 것을 볼 수 있다.

large와 xlarge의 차이는 유의미하지 않다. 따라서 인스턴스 유형 별 크기는 성능에 영향을 끼치지 않는다.

c에서는 intel이 , 나머지(m, t)에서는 arm이 더 좋은 성능을 보였다.

<br>

# 결론

따라서 웹 요청을 하는 경우, 초당 요청 횟수가 가장 높고, 총 요청시간이 가장 적은 아키텍처 x86의 유형 c를 추천한다.

<br>

# 이슈
![image](https://github.com/koorukuroo/pda_4th/assets/56223389/7d8218fd-865b-4d66-8061-f8b188e52d68)
* x86 c4.large 로 10000번의 요청을 보낸 경우, 위 그림처럼 멈췄다.
* 예상 소요 시간은 17.678 x 100 = 1767.8 초로, 29.45분이다.
* 하지만, 1시간이 지나도 결과가 나타나지 않았다.
* 네이버 정책상, 요청 횟수에 재한을 두었기 때문인 것으로 예상된다.
* 따라서 이럴 때 API 이용한다. 대부분의 대형 웹 서비스는 공개된 API를 제공한다. 이 API를 사용하여 데이터를 가져오면 웹페이지를 직접 크롤링하는 것보다 훨씬 더 안정적이고 효율적이다.


# 요청 파이썬 코드
```python
import requests
import time

def measure_crawling_speed(url, num_requests):
    start_time = time.time()  # 시작 시간 기록
    for _ in range(num_requests):
        response = requests.get(url)  # 웹 페이지에 요청 보내기
    end_time = time.time()  # 끝 시간 기록
    elapsed_time = end_time - start_time  # 총 경과 시간 계산
    crawling_speed = num_requests / elapsed_time  # 총 요청 속도 계산
    time_per_request = elapsed_time / num_requests  # 1번의 요청당 평균 시간 계산
    return crawling_speed, time_per_request

if __name__ == "__main__":
    url = "https://m.stock.naver.com/"
    num_requests = 100
    
    speed, time_per_request = measure_crawling_speed(url, num_requests)
    print(f"크롤링 속도: {speed:.2f} requests/second")
    print(f"1번의 요청당 평균 시간: {time_per_request:.5f} seconds")
    print(f"총 요청 시간: {elapsed_time:.5f} seconds" )
```

# 역할
인스턴스 아키텍처 기준으로 역할을 분담한다.
- KimRiun : Intel(x86)
- gariguri : ARM
