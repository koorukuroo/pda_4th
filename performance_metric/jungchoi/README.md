
# JC 팀 인스턴스 별 성능비교
Members: 정원우 최경서

## 주제
인스턴스 유형 및 아키텍처별 성능 측정을 위한 파이썬 실행

### 비교 대상 & 지표
비교 대상 1: 1부터 100만까지의 수에서 소수를 찾는 알고리즘  
비교 대상 2: 100만까지의 수 중 소수만을 별개의 파일로 저장한 후, 삭제하는 알고리즘


https://github.com/yapyap2/PDA/blob/main/primeMulti.py

비교 지표: 실행 속도

### 알고리즘 수행 결과

| 인스턴스 유형 | Time taken for test 1 |Time taken for test 2|Time taken for test 3 | Average
| :-----------------: |:--------------------: |:-----------------: | :------------------: |:--:|
| c5.large| 36.3016 | 36.4646 | 36.1971|36.3211
c5.2xlarge| 48.1694 | 50.3427 | 49.6982|49.0211
t4g.large| 29.363 | 29.4873 | 29.5041|29.4515
t4g.2xlarge| 37.4053 | 33.3790 | 36.9954|35.92656
m7i.large| 29.5404 | 28.9874 | 29.0318|29.1865
m7i.2xlarge| 23.8972 | 24.2411 | 23.2343|23.7909
r7i.large| 29.7347 | 27.5120 | 27.9217|28.3895
r7i.2xlarge| 20.2677 | 20.6408 | 20.8087|20.5724

### IO 수행 결과

| 인스턴스 유형 | Time taken for test 1 |Time taken for test 2|Time taken for test 3 | Average
| :-----------------: |:--------------------: |:-----------------: | :------------------: |:--:|
c5.large| 4.1568 | 3.6798 | 3.9116|3.9161
c5.2xlarge| 3.8851 | 3.3556 | 3.3721|3.5376
t4g.large| 5.2953 | 4.8500 | 4.8962|5.0138
t4g.2xlarge| 5.4026 | 4.9343 | 5.0260|5.1209
m7i.large| 2.6203 | 2.2156 | 2.2814|2.3724
m7i.2xlarge| 2.4108 | 2.3861 | 2.3822|2.3930
r7i.large| 2.4899 | 2.0907 | 2.1060|2.2289
r7i.2xlarge| 2.4778 | 2.2273 | 2.0730|2.2594

*t2.nano의 경우 진행 못함


## 각 인스턴스 유형별 성능 설명

Instance Type	|vCPUs|	Memory (GiB)
--|-|-
c5.large	|2|	4
c5.2xlarge	|8|	16
t4g.large	|2|	8
t4g.2xlarge	|8|	32
m7i.large	|2|	16
m7i.2xlarge	|8|	64
r7i.large	|2|	16
r7i.2xlarge	|8|	64


###  cf. CPU 사용량 비교

.|c5.2xlarge | t2.2xlarge
-|-|-
온디맨드 Linux 요금|	시간당 0.3840USD|	시간당 0.4608USD
온디맨드 Windows 요금|	시간당 0.7520USD|	시간당 0.5228USD
vCPU|	8(4코어)|	8(8코어)
메모리(MiB)|	16384	|32768
스토리지(GB)|	–|	–
지원되는 루트 디바이스 유형|	ebs|	ebs
네트워크 성능|	Up to 10 Gigabit|	Moderate
아키텍처|	x86_64|	x86_64
버스트 가능|	false|	true
프리 티어 사용 가능|	false|	false
현재 세대|	true|	true

##### c5.2xlarge

최소:  0.0  
최고:  19.4  
평균 cpu 사용률:  12.15263157894737

![resource_usage_plot_639](https://github.com/koorukuroo/pda_4th/assets/59429729/c9da30fd-67d3-4c84-a559-412ead0a85e8)

##### t2.2xlarge

최소:  12.0  
최고:  29.5  
평균 cpu 사용률:  13.263157894736839

![resource_usage_plot_644](https://github.com/koorukuroo/pda_4th/assets/59429729/963facd3-f810-42e4-ac3b-bbe8061b6899)


