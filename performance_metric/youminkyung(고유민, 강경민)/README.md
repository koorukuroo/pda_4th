
## ⭐️ M 범용
- 컴퓨팅, 메모리 및 네트워크 리소스를 균형 있게 제공
- 적용사례 : 중소형 DB, 기타 엔터프라이즈 애플리케이션
## ⭐️ C 컴퓨팅 최적화
- 가장 높은 수준의 컴퓨팅 성능을 제공
- 적용사례 : 고성능 프론트 엔드, 웹서버, 배치(일괄처리), 게임

## ⁉️ M5 vs C5

| 인스턴스 크기 | vCPU | 메모리(GiB) | 인스턴스 스토리지(GB) |네트워크 대역폭(Gbps)** | EBS 대역폭(Mbps) | 시간 당 요금 | CPU 아키텍처 |
|---|---|---|---|---|---|---|---|
|m5.large|2|8|EBS 전용|최대 10|최대 4,750|USD 0.096| x86(64bit) |
|c5.large|2|4|EBS 전용|최대 10|최대 4,750|USD 0.085| x86(64bit) |

## ✨ M5
- Amazon EC2 M5 인스턴스는 인텔 제온® 플래티넘 8175M 또는 8259CL 프로세서로 구동되는 최신 세대 범용 인스턴스입니다. 이 인스턴스는 컴퓨팅, 메모리 및 네트워크 리소스를 균형 있게 제공하며 다양한 애플리케이션에 적합합니다.

### 기능:
- 메모리 최적화를 중점으로 한 인스턴스
- 일반적으로 메모리 접근이 더 빠르고 메모리 사용량에 더 많은 리소스를 할당하므로 메모리 집약적인 작업을 수행할 때 더 빠른 실행 시간을 보임
- 데이터베이스, 캐시 서버, 대규모 데이터 처리 등의 작업을 수행할 때 더 효과적 
### 예시:
- 대규모 데이터베이스: 시스템에서 데이터를 메모리에 적재하고 빠르게 액세스할 수 있어야 함.
- 메모리 캐싱: 캐싱 서버는 많은 양의 데이터를 메모리에 저장하여 빠른 응답 시간을 제공해야 함.
- 대규모 데이터 처리: 데이터를 메모리에 로드하여 빠르게 처리해야 함. 


## ✨ C5
- Amazon EC2 C5 인스턴스는 컴퓨팅 집약적 워크로드에 최적화되었으며 컴퓨팅 비율당 저렴한 가격으로 비용 효율적이며 뛰어난 성능을 제공합니다.

### 기능:
- 컴퓨팅 최적화를 중점으로 한 인스턴스
- CPU 연산에 더 많은 리소스를 할당하고 CPU 성능이 뛰어남
- 고성능 컴퓨팅, 컴파일 작업, 웹 서버 등의 작업을 수행할 때 더 효과적
### 예시:
- 고성능 컴퓨팅 (HPC): 고성능 컴퓨팅 작업은 대규모 데이터를 처리하고 병렬 컴퓨팅을 수행해야 함.
- 컴파일 작업: CPU 연산이 많이 필요한 작업, 소프트웨어 개발 및 빌드 시스템에서는 코드를 컴파일하는 데 많은 CPU 자원이 필요.
- 웹 서버: 웹 서버는 동시 요청을 처리하고 빠른 응답을 제공해야 함.

## 1️⃣ cpu 연산 처리 속도 측정
- 확인 코드
```python
import time

# 실행할 작업
def task_instance_1():
    start_time = time.time()
    result = 0
    for i in range(1000000000): # 10억 번 반복해서 정수 덧셈 수행
        result += i
    end_time = time.time()
    execution_time = end_time - start_time
    return execution_time

print(task_instance_1())
```
- M5
<Img src = "https://hackmd.io/_uploads/r133OiXk0.png" width="700"/>

- C5
<Img src = "https://hackmd.io/_uploads/rJCsOiXJC.png" width="1200"/>

#### 🤔 결론
- cpu 연산 처리 속도: `M5` < `C5`
- 단순한 cpu 연산 처리 속도시간을 C5 인스턴스가 M5 인스턴스 보다 `36.37%` 정도 시간을 줄일 수 있었습니다.
## 2️⃣ 네트워크 요청 처리 속도
### ☝🏻 동기 코드
```python3 
import requests
import time

def send_request(url):
    response = requests.get(url)
    return response.text

if __name__ == "__main__":
    num_requests = 1000
    url = "http://서버의_IP_또는_도메인:포트번호/"
    start_time = time.time()
    
    for _ in range(num_requests):
        response_text = send_request(url)
        # 응답을 받은 후의 처리 작업
        print("응답:", response_text)
        
    end_time = time.time()
    total_time = end_time - start_time
    print(f"총 소요 시간: {total_time:.2f} 초")
```
- M5
<Img src = "https://hackmd.io/_uploads/r1PcUiX1C.png" width="1200"/>

- C5
<Img src = "https://hackmd.io/_uploads/SyWsIomy0.png" width="450"/>

#### 🤔 문제점
- 동기적으로 요청을 보낼 시 네트워크 `request` 처리 속도를 비교하기가 까다로웠음

### ✌🏻 비동기 코드
```python
import asyncio
import aiohttp
import time

async def fetch(url):
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as response:
            return await response.text()

async def main(num_requests):
    url = "http://43.203.217.70:5000/"  # 요청을 보낼 URL
    start_time = time.time()  # 시작 시간 기록
    tasks = [fetch(url) for _ in range(num_requests)]
    await asyncio.gather(*tasks)
    end_time = time.time()  # 종료 시간 기록
    total_time = end_time - start_time  # 총 소요 시간 계산
    print(f"총 소요 시간: {total_time:.2f} 초")

if __name__ == "__main__":
    num_requests = 240  # 보낼 요청의 수
    asyncio.run(main(num_requests))
```

- M5
<Img src = "https://hackmd.io/_uploads/rkQfFs71C.png" width="600"/>

`10번 평균 시간: 45.9 초`

- C5
<Img src = "https://hackmd.io/_uploads/SyPWYomkC.png" width="600"/>

`10번 평균 시간: 29.2 초`

#### 🤔 결론
- 비동기처리로 한번에 240개의 요청을 처리해주는 시간을 비교했을때 네트워크 요청 처리 속도는 C5 인스턴스가 M5 인스턴스 보다 `36.37%` 정도 시간을 줄일 수 있었습니다.
