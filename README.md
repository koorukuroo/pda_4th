# 신한 프로디지털아카데미 4기 테스트 공간

이 공간은 신한 프로디지털아카데미 4기 수강생들을 위한 github 테스트 공간입니다. 여기에서는 다양한 테스트를 진행하고 결과를 공유할 수 있습니다.

## 아키텍처
아키텍처는 64비트(x86)과 64비트(Arm)을 사용했습니다.

## AWS EC2 인스턴스 유형 별 성능 테스트 

| 인스턴스-아키텍처 | Time taken for tests | Suc/Total Request | Request per second | Time per Request |  
|---|---|---|---|---|
| T4g.small-Arm | 0.992sec | 400/400 | 403.40[#/sec] | 2.479ms | 
| T3.small-x86 | 0.585sec | 400/400 | 684.08[#/sec] | 1.462ms |
| T4g.large-Arm |  |  |  |  |
| T3.large-x86 | 0.575sec | 400/400 | 695.47[#/sec] | 1.438ms |
| M6g.large-Arm |  |  |  |  |
| M6i.large-x86 | 0.558sec | 400/400 | 717.26[#/sec] | 1.394ms |
