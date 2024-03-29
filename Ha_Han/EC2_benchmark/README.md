# EC2 벤치마크

# 공통 스펙

- Intel x86 아키텍쳐
- Ubuntu 22.04 LTS

# 측정 내용

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/9ee4e3fc-a5d5-4588-9905-fcf5e1fb6307/58b9e7ed-b5b4-4f43-ad83-c6c1a1942410/Untitled.png)

- Instance Family 별 성능 차이
- 동일 Instance Family 내 Instance 크기 별 성능차이

# 결과 요약

---

| 인스턴스 유형 | 하드웨어 스펙 | CPU 테스트 | 크롤링 테스트 |
| --- | --- | --- | --- |
| m5.large | 2vCPU, 8G RAM | 0.74 sec | 3.94 sec |
| m5.xlarge | 4v CPU, 16G RAM | 0.36 sec | 3.81 sec |
| c5.large | 2v CPU, 5G RAM | 0.63 sec | 4.08 sec |
| c5.xlarge | 4v CPU, 8G RAM | 0.31 sec | 3.49 sec |
| t2.micro | 1v CPU, 1G RAM | 1.35 sec | 4.82 sec |
| t2.medium | 2v CPU, 4G RAM | 0.67 sec | 4.71 sec |
| r3.large | 2v CPU, 15G RAM | 0.9 sec | 4.50 sec |
| r3.xlarge | 4v CPU, 30.5G RAM | 0.44 sec | 4.57 sec |

<br><br>

# 세부 내용

---

## t2.micro VS t2.medium

https://github.com/koorukuroo/pda_4th/assets/71596178/6dfdb19e-ffb1-425b-84c2-e160fab5c7eb

https://github.com/koorukuroo/pda_4th/assets/71596178/e5ed5976-48eb-4e25-ac32-2a6963d53676

https://github.com/koorukuroo/pda_4th/assets/71596178/8640955c-8ce2-496c-a99b-62523e7d0cc2

https://github.com/koorukuroo/pda_4th/assets/71596178/718f96be-49a8-44f9-bf72-7119f4024251

## r3.large VS r3.xlarge

https://github.com/koorukuroo/pda_4th/assets/71596178/ca9aa8a4-94fb-4f4a-b58d-a1535249be4a

https://github.com/koorukuroo/pda_4th/assets/71596178/23d97707-50dc-45d2-8848-e216a632f433

https://github.com/koorukuroo/pda_4th/assets/71596178/3085fd2c-234c-4bf5-91d7-d4640aa5531b

https://github.com/koorukuroo/pda_4th/assets/71596178/2184720b-9fea-4052-8cfb-decaacb57420

## CPU 사용 비교

https://github.com/koorukuroo/pda_4th/assets/71596178/03b9d0bf-e9ec-45ae-8914-2c15dcb56ba1

## m5.large VS m5.xlarge

https://github.com/koorukuroo/pda_4th/assets/71596178/6af30b96-2ef9-4eb8-b038-8d94778c3965

https://github.com/koorukuroo/pda_4th/assets/71596178/fbf0066b-301e-474e-a7ea-33ea81f6502a

https://github.com/koorukuroo/pda_4th/assets/71596178/0eb6120b-85bb-413b-ab08-e10f721e5fc4

https://github.com/koorukuroo/pda_4th/assets/71596178/2c29b309-bf12-46c3-a540-dfdbe753b315

## c5.large VS c5.xlarge

https://github.com/koorukuroo/pda_4th/assets/71596178/dee22c55-66a9-4c0a-b206-6ae59dd5f553

https://github.com/koorukuroo/pda_4th/assets/71596178/7d577708-16ca-454f-ae1e-e36175410e0b

https://github.com/koorukuroo/pda_4th/assets/71596178/d4e9f4a9-d2d2-4b98-99c3-62c3b993a4c9

https://github.com/koorukuroo/pda_4th/assets/71596178/13e06e2e-78c9-45e5-911d-a8a50ef6a3d0

## CPU 사용 비교

https://github.com/koorukuroo/pda_4th/assets/71596178/0c3e309e-939f-4fd3-9d72-18d4d9267949

# 정리

---

### Instance Family 별 성능 차이가 있는가?

- **CPU 연산에서 유의미한 차이가 존재**
2v CPU 기준 : c5 > t2 > m5 > r3
4v CPU 기준 : c5 > m5 > r3
    
    EC2의 최고 성능 CPU를 사용하는 C가 가장 빨랐으며, 그다음으로 성능 순간 확장에 특화된  T, 범용성이 좋은 M, 그리고 메인메모리를 우선적으로 하는 R 순으로 CPU연산 속도가 빨랐다.
    

### CPU, 메인 메모리 용량 별(Instance 크기) 성능 차이가 있는가?

- **CPU 연산이 많은 경우에 유의미한 차이 발생**
    
    같은 Family의 경우, CPU 코어의 수 / 2 만큼의 속도 차이가 났으며, 병렬 처리를 한 결과로 추측이 된다.
    
    다른 Family의 인스턴트인 경우, 코어 수의 차이만큼은 아니지만 각 인스턴트 Family 별로 유의미한 차이가 관측되었다.
    
- **크롤링의 경우, 네트워크의 영향이 더욱 컸음**
    
    동시에 여러 인스턴스를 실행하면 모든 인스턴스에서 속도가 느려지고, 시간에 따라 지속적으로 측정 시간의 변동이 존재하였다.
    또한 성능이 더 좋은 인스턴스라도 시간이 더 길게 나오는 등, 인스턴스의 성능보다는 네트워크의 성능이 더 중요하였다.
