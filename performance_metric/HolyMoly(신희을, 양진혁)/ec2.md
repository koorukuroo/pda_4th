# 환경
저희 조는 vcpu, 코어 수, 인스턴스 패밀리, 네트워크 전송속도 등을 비교 분석하였습니다.

# 지표
지표는 다음과 같습니다.
|지표|
|------|
|코드 실행 속도|
|네트워크 속도 차이|

# 인스턴스 유형
![image](https://github.com/koorukuroo/pda_4th/assets/83682424/1743f02f-125c-4a43-b832-c4c94147011f)

## t3.small <-> t3a.small
항상 작업은 AMD CPU를 사용해야 한다고 들어왔었기 때문에 이런 간단한 작업에서도
유의미한 차이가 날까 궁금하여 테스트를 진행하였고 실제로 CPU 제조사에 따른 성능차이가 있음을 확인하였습니다.

|종류|실행시간|
|------|---|
|t3a.small|40.04|
|t3.small|50.06|

<img width="585" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/5e4ea516-d69d-4cde-8049-794e747f93d6">

## t2.small <-> t3.small

T3의 장점이 T2에 비교하여 네트워크 속도가 향상되었기 때문에 아나콘다 파일을 얼마나 빠르게
다운로드 받는지 테스트하였고 실제로 속도 향상이 된 것을 확인할 수 있었습니다.

|종류|네트워크 속도|
|------|---|
|t2.small|6.73|
|t3.small|4.81|
<img width="620" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/aeaaf019-3f06-4119-8e77-ce04d432f230">


## t3.micro <-> t3.xlarge

t3.micro보다 t3.xlarge의 스펙이 다방면으로 높아
코드 실행속도가 많이 차이 날 것이라 생각했고 테스트를 한 결과
코어수가 두배차이 나는 만큼 실행속도도 약 두배차이가 나는 것을 확인하였습니다.

|종류|실행시간|
|------|---|
|t3.micro|52.07|
|t3.xlarge|26.03|

<img width="610" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/41c37443-1c31-459f-804a-d3472ee87cca">


## c4.large <-> m4.large <-> t3.large 

인스턴스 패밀리의 차이를 알아보기 위해 각 c,t,m을 비교하였는데
범용적인 m이 제일 느렸고
범용적이지만 터보기능을 지원하는 t3.large와
컴퓨팅 능력에 특화되어 있는 c4.large의 속도가 비슷한 것을 확인하였습니다.

|종류|실행시간|
|------|---|
|c4.large|48.02|
|t3.large|46.04|
|m4.large|62.05|

<img width="635" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/cb7fefb4-62e7-4f2b-a0b9-beaedda06781">

## 코드

```python
import time
import psutil
import multiprocessing
def heavy_cpu_task(start, end, result_queue):
    result = 0
    # 많은 계산을 수행하여 CPU를 사용함
    for i in range(start, end):
        result += i
    result_queue.put(result)  # 결과를 Queue에 넣음
def monitor_system_performance(interval=1, stop_event=None):
    while not stop_event.is_set():
        # CPU 사용량 및 부하 가져오기
        cpu_percent = psutil.cpu_percent(interval=1)
        cpu_freq = psutil.cpu_freq()
        cpu_temp = psutil.sensors_temperatures()
        print("CPU 사용량:", cpu_percent, "%")
        print("CPU 주파수 (현재/최소/최대):", cpu_freq.current, "/", cpu_freq.min, "/", cpu_freq.max, "MHz")
        if 'coretemp' in cpu_temp:
            print("CPU 온도:", cpu_temp['coretemp'][0].current, "°C")
        print("----------------------------------")
        time.sleep(interval)
if __name__ == "__main__":
    start_total_time = time.time()  # 프로그램 시작 시간 기록
    print("시스템 성능 모니터링을 시작합니다.")
    # 성능 모니터링 스레드 시작
    monitor_interval = 1  # 모니터링 간격 (초)
    stop_event = multiprocessing.Event()  # 이벤트를 멀티프로세스용으로 변경
    monitor_thread = multiprocessing.Process(target=monitor_system_performance, args=(monitor_interval, stop_event))
    monitor_thread.start()
    # CPU 사용량이 많은 작업 실행
    num_processes = psutil.cpu_count(logical=True)  # 사용 가능한 논리 코어 수
    chunk_size = 10**8 // num_processes  # 각 프로세스가 처리할 범위의 크기
    processes = []
    result_queue = multiprocessing.Queue()  # 결과를 저장할 Queue 생성
    for i in range(num_processes):
        start = i * chunk_size + 1
        end = start + chunk_size
        process = multiprocessing.Process(target=heavy_cpu_task, args=(start, end, result_queue))
        process.start()
        processes.append(process)
    # 모든 프로세스가 종료될 때까지 대기하고 결과를 수집
    for process in processes:
        process.join()
    # 결과 출력
    results = []
    while not result_queue.empty():
        result = result_queue.get()
        results.append(result)
    # 성능 모니터링 스레드 종료
    stop_event.set()
    monitor_thread.join()
    end_total_time = time.time()  # 프로그램 종료 시간 기록
    total_execution_time = end_total_time - start_total_time  # 총 실행 시간 계산
    # 결과 출력
    for i, result in enumerate(results):
        print(f"프로세스 {i}: CPU 작업 완료 - 결과: {result}")
    print("총 실행 시간:", total_execution_time, "초")
```
