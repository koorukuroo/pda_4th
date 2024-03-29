<div>
인스턴스 성능비교
</div>

![image](https://github.com/JangHoIk1/AWS/assets/94967088/a35c29fb-d703-4618-a890-a388e88cef5b)


![image](https://github.com/JangHoIk1/AWS/assets/94967088/5f75b723-9cb0-46bd-8e38-63b2200f3a78)


t4g.micro vs t4g.2xlarge

![image](https://github.com/JangHoIk1/AWS/assets/94967088/75ae2a07-5fd7-4caa-86dc-af7a49bd16ec)

t4 시리즈 -> AWS Graviton2 프로세서 사용
c7 시리즈 -> AWS Graviton3 프로세서 사용

AWS Gravition 3는 AWS Graviton2 기반 인스턴스에 비해 최대 25% 더 뛰어난 성능을 제공

![image](https://github.com/JangHoIk1/AWS/assets/94967088/451fe4dc-83d9-49eb-881b-ad36524d9ef5)


![image](https://github.com/JangHoIk1/AWS/assets/94967088/5ea9fd5e-5660-429f-a569-8c2a59722444)
![image](https://github.com/JangHoIk1/AWS/assets/94967088/017a1ba1-22cf-4531-8a39-58208e85d72d)

가격 차이에 따른 성능

<H3>X86 Intel Architecture</H3>

![image](https://github.com/koorukuroo/pda_4th/assets/68230815/848f8cc2-5afc-44fa-93f0-49dd55ab1abf)


T : 범용

T2의 사용 프로세서

 • 최대 3.3GHz의 인텔 제온 스케일러블 프로세서(하스웰 E5-2676 v3 또는 브로드웰 E5-2686 v4)

![image](https://github.com/koorukuroo/pda_4th/assets/68230815/0c6e9e0d-b02f-4c91-baa5-13465c88d4f7)


t2.micro

![image](https://github.com/koorukuroo/pda_4th/assets/68230815/0401cc09-48f6-4971-adad-257ce58c1e29)


t2.xlarge

C : 컴퓨팅 특화. (추론,고성능)

C4의 사용 프로세서 

 • 최대 2.9GHz의 인텔 제온 스케일러블 프로세서(하스웰 E5-2666 v3)

C6i의 사용 프로세서 
 • 최대 3.5GHz의 3세대 인텔 제온 스케일러블 프로세서(아이스 레이크 8375C)

![image](https://github.com/koorukuroo/pda_4th/assets/68230815/4c216f5b-8e9f-4371-9979-2604592b5046)


c4.xlarge

프로그램 자체에서 단일 쓰레드 사용. 병렬화 불가

D : 스토리지 최적화.

D2의 사용 프로세서
 • 고주파수 인텔 제온 스케일러블 프로세서(하스웰 E5-2676 v3)

![image](https://github.com/koorukuroo/pda_4th/assets/68230815/22d4c844-c3eb-4969-a639-c182fe2ff890)

AMD 프로세서는 멀티코어 아키텍처를 활용하여 병렬 처리에 특화


