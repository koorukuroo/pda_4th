# AWS 인스턴스 성능 비교

성능 비교를 위해 AWS 인스턴스 유형별로 **CPU 사용 전후 및 작업 처리 시간**을 측정하였습니다.

인스턴스 패밀리: t  
| CPU, RAM, 네트워크가 균형잡힌 인스턴스(m과 같은 범용)

인스턴스 제너레이션: 3 - x86 / 4 - Arm 


어트리뷰션: Arm - AWS Graviton 프로세서  


인스턴스 크기: medium, large, xlarge

<details>
<summary> test.py </summary>

```python

import time
import psutil
import csv
import os

# 작업 정의
def cpu_intensive_task():
    [x**2 for x in range(10000000)]

# 성능 측정 및 CSV 파일 저장
def measure_and_save_performance(csv_file):
    cpu_usage_before = psutil.cpu_percent()
    start_time = time.time()
    cpu_intensive_task()
    cpu_usage_after = psutil.cpu_percent()
    end_time = time.time()

    # 데이터 준비
    data = {
        'CPU Usage Before (%)': cpu_usage_before,
        'CPU Usage After (%)': cpu_usage_after,
        'Task Duration (seconds)': end_time - start_time,
    }

    # CSV 파일이 존재하지 않으면, 헤더와 함께 새 파일 생성
    file_exists = os.path.isfile(csv_file)
    with open(csv_file, 'a', newline='') as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=data.keys())
        if not file_exists:
            writer.writeheader()
        writer.writerow(data)

# 파일명 지정 및 함수 호출
csv_file = 'aws_instance_performance.csv'
measure_and_save_performance(csv_file)

```
</details>


## 성능 비교 표

### t4g.medium vs t3.medium
공통 사양: 2vCPU, 4GiB  
가격 비교: 0.0416 USD(Arm) vs 0.052 USD(x86)

| 인스턴스 유형 | 아키텍처 | CPU 사용 전 (%) | CPU 사용 후 (%) | 작업 처리 시간 (초) |
|---------------|----------|------------------|------------------|----------------------|
| t4g.medium    | Arm      | 0.0              | 50.2             | 3.193                |
| t3.medium    | x86      | 0.0              | 50.2             | 3.776                |

### t4g.large vs t3.large
공통 사양: 2vCPU, 8GiB  
가격 비교: 0.0832 USD(Arm) vs 0.104 USD(x86)

| 인스턴스 유형 | 아키텍처 | CPU 사용 전 (%) | CPU 사용 후 (%) | 작업 처리 시간 (초) |
|---------------|----------|------------------|------------------|----------------------|
| t4g.large     | Arm      | 0.0              | 50.1             | 3.200                |
| t3.large     | x86      | 0.0              | 50.1             | 3.402                |

### t4g.xlarge vs t3.xlarge
공통 사양: 4vCPU, 16GiB  
가격 비교: 0.1664 USD(Arm) vs 0.208 USD(x86)  


| 인스턴스 유형 | 아키텍처 | CPU 사용 전 (%) | CPU 사용 후 (%) | 작업 처리 시간 (초) |
|---------------|----------|------------------|------------------|----------------------|
| t4g.xlarge    | Arm      | 0.0              | 25.1             | 3.198                |
| t3.xlarge     | x86      | 0.0              | 25.2             | 2.960     

### t4g.2xlarge vs t3.2xlarge
공통 사양: 8vCPU, 32GiB  
가격 비교: 0.3328 USD(Arm) vs 0.416 USD(x86)  

| 인스턴스 유형 | 아키텍처 | CPU 사용 전 (%) | CPU 사용 후 (%) | 작업 처리 시간 (초) |
|---------------|----------|------------------|------------------|----------------------|
| t4g.2xlarge    | Arm      | 0.0              | 12.5             | 3.182                |
| t3.2xlarge     | x86      | 0.0              | 12.5             | 2.757     


### 이 중 가장 높은 요금으로 24시간 인스턴스를 실행한다면?
약 13,467원이 부과됨 (x86, t3.2xlarge, 24.03.29 환율 기준)  

### 비교
- 시스템 모니터링, 프로파일링, 프로세스 리소스 제한 및 실행중인 프로세스 관리에 유용한 `psutil` 모듈을 사용하여 CPU 사용량을 측정
- 2vCPU인 인스턴스 유형인
`t4g.medium vs t3.medium` 비교와 `t4g.xlarge vs t3.xlarge` t4g.xlarge vs t3.xlarge비교에서 모두 CPU사용이 약 50%로 비슷
    - 즉, RAM에 의존도가 낮은 작업(단순 연산, 적은 프로그램 등) 은 CPU에 집중하여 인스턴스 유형을 결정하면 된다는 것을 느낌
- CPU의 수가 2배씩 늘어날수록, 사용량이 2배씩 줄어드는 것을 알 수 있음
- 현재 우리의 측정기능은 GPU가 내재된 인스턴스 유형을 굳이 사용할 필요 없다는 것을 알 수 있음(가격만 높음)  
결론: 어떤 작업을 할 지에 대해 잘 알고, 인스턴스 유형을 선택해야 한다.


## 성능 비교 그래프
### CPU 사용량 비교
![alt text](image.png)

### 작업 시간 비교
![alt text](image-1.png)