# 신한 프로디지털아카데미 4기 테스트 공간

이 공간은 신한 프로디지털아카데미 4기 수강생들을 위한 github 테스트 공간입니다. 여기에서는 다양한 테스트를 진행하고 결과를 공유할 수 있습니다.

## 💻테스트 환경

저희는 ApacheBench를 사용해서 부하 발생 테스트를 했습니다.  
동일한 환경에서 테스트하기위해 t4.nano 인스턴스틀 생성해서 테스트 했습니다.
우분투에서 아파치를 설치한 후 'ab -n 400 -c 1 http://인스턴스퍼블릭 IP주소' 명령어를 실행해서 400명의 사람이 동시 접속 없이 페이지에 접속한다고 가정한 상황을 테스트를 합니다.

## ⚙아키텍처

아키텍처는 64비트(x86)과 64비트(Arm)을 사용했습니다.
t4g, m6g 유형은 arm 아키텍처로 t3, m6i 유형은 x86 아키텍처로 테스트 했습니다.

## 🔎AWS EC2 인스턴스 유형 별 성능 테스트

| 인스턴스-아키텍처 | Time taken for tests | Suc/Total Request | Request per second | Time per Request |
| ----------------- | -------------------- | ----------------- | ------------------ | ---------------- |
| T4g.small-Arm     | 0.992sec             | 400/400           | 403.40[#/sec]      | 2.479ms          |
| T3.small-x86      | 0.585sec             | 400/400           | 684.08[#/sec]      | 1.462ms          |
| T4g.large-Arm     | 0.971sec             | 400/400           | 411.83[#sec]       | 2.479ms          |
| T3.large-x86      | 0.575sec             | 400/400           | 695.47[#/sec]      | 1.438ms          |
| M6g.large-Arm     | 0.909sec             | 400/400           | 439.83[#/sec]      | 2.274ms          |
| M6i.large-x86     | 0.558sec             | 400/400           | 717.26[#/sec]      | 1.394ms          |

![poster](./imgs/graph.png)
<img src="/imgs/graph.png" width="400" height="300">

## 📈결과 분석

ARM 기반 아키텍처를 사용하는 t4g와 인텔의 x86 아키텍처를 사용하는 t3를 비교해보겠습니다.
표를 해석해보면 x86 아키텍처를 사용하는 t3 유형의 인스턴스가 크기에 상관없이 t4g보다 처리가 빠르다는 것을 알 수 있습니다.
구글링을 했을 땐 t4g 인스턴스가 t3 모델보다 40% 나은 성능에 20% 더 저렴하다고 하는데 결과값은 반대로 나왔습니다.

동일한 유형에서 인스턴스 크기에 따라 비교를 해보면 인스턴스의 크기가 클수록 처리속도가 빨라지는 것을 알 수 있습니다. 
가상 CPU가 모두 2개이고 범용 목적 인스턴스의 경우 네트워크 성능이 5기가비트로 동일한 것을 고려했을 때 같은 유형, 다른 크기의 차이는 메모리 밖에 없어서 처리 능력 차이에는 메모리 차이에서 오는 것 아닐까 생각했습니다.

마지막으로 범용 목적 인스턴스인 t4g, t3와 메모리 최적화 목적 인스턴스인 M6g, M6i를 비교해보면, 동일한 인스턴스 크기에서 메모리 최적화 목적인 인스턴스가 더 처리 성능이 좋다는 것을 알 수 있습니다.
웹 부하테스트를 수행할 때 메모리 성능은 주요한 요소 중 하나입니다. 웹 서버는 클라이언트 요청을 처리하고 응답을 생성하기 위해 메모리를 사용하기 때문에 서버가 처리하는 요청의 양과 동시에 사용되는 메모리 양은 일반적으로 비례합니다. 그런 이유에서 메모리 특화 유형 인스턴스가 범용 목적 인스턴스보다 처리 속도가 더 빠른 것이 아닌지 추측합니다.

## 기타
| 인스턴스 | 온디맨드 시간당 요금 | vCPU | 메모리 | 네트워크 성능 |
| ------- | ------------------- | ---- | ----- | --------------- |
| t4g.small | 0.0208 | 2 | 2GiB | 최대 5기가비트 |
| t4g.large | 0.832 | 2 | 8GiB | 최대 5기가비트 |
| t3.small | 0.026 | 2 | 2GiB | 최대 5기가비트 |
| t3.large | 0.104 | 2 | 8GiB | 최대 5기가비트 |
| m6g.large | 0.094 | 2 | 8GiB | 최대 10기가비트 |
| m6i.large | 0.118 | 2 | 8GiB | 최대 12,500메가비트 |
