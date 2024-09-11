# AWS
AWS(성능비교)

## 1. t4.xlarge vs t4.micro

가격 비교: 0.1664 USD vs 0.0104 USD

| 인스턴스 유형 | 아키텍처 | CPU 사용 전 (%) | CPU(AWS 모니터링)(%) | 크롤링 처리 시간 (초) |
|---------------|----------|------------------|------------------|----------------------|
| t4g.xlarge    | Arm      | 0.0              | 1.49%             | 4.81s                |
| t4g.micro    | Arm     | 0.0              | 6.87%             | 12.04s               |

### 크롤링 시간차

<div style="display: flex;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/b4c02080-bf47-4d99-8990-aec2d84160d1" alt="Image 1" style="width: 50%;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/cfe7ae70-c053-42d4-8c76-b6b0201e1d35" alt="Image 2" style="width: 50%;">
</div>

<br/>

- t4.xlarge(4.81s)가 t4.micro(12.04s)보다 세배 가량 빠르다 

### cpu 사용량

<div style="display: flex;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/ba008a85-1ff0-4f98-905d-841b7d19129b" alt="Image 1" style="width: 50%;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/26a265ec-4f3f-438d-80a1-b5418ce1eb90" alt="Image 2" style="width: 50%;">
</div>

<br/>

- 가장 높은 수치를 기준으로 t4.xlarge(1.49%)가 t4.micro(6.87%)에 비해 4배 가량 cpu사용량이 적다 

## 2. m6g.2xlarge vs t3.2xlarge

가격 비교: 0.376 USD vs 0.416 USD

| 인스턴스 유형 | 아키텍처 | CPU 사용 전 (%) | CPU(AWS 모니터링)(%) | 크롤링 처리 시간 (초) |
|---------------|----------|------------------|------------------|----------------------|
| m6g.2xlarge    | Arm      | 0.0              | 1.67%             | 4.20s               |
| t3.2xlarge    | x86      | 0.0              | 0.877%             | 4.34s               |


### 크롤링 시간차

<div style="display: flex;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/e993975c-eaf7-4866-8004-66c1fa91787b" alt="Image 1" style="width: 50%;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/efb9a701-7bfc-43cb-881a-c33a266cc018" alt="Image 2" style="width: 50%;">
</div>

<br/>

- m6g.2xlarge(4.20s)가 t3.2xlarge(4.34s)보다 빠르다 


### cpu 사용량

<div style="display: flex;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/7c472ff4-b75b-481f-83bd-84eb1b1ad98c" alt="Image 1" style="width: 50%;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/42e3c2b7-31e5-44fd-98a2-d57287c24d40" alt="Image 2" style="width: 50%;">
</div>

<br/>

- 가장 높은 수치를 기준으로 t3.2xlarge(0.877%) m6g.2xlarge(1.67%)에 비해 2배 가량 cpu사용량이 적다 


## 3. t3.xlarge vs t4.xlarge

가격 비교: 0.208 USD vs 0.1664 USD

| 인스턴스 유형 | 아키텍처 | CPU 사용 전 (%) | CPU(AWS 모니터링)(%) | 크롤링 처리 시간 (초) |
|---------------|----------|------------------|------------------|----------------------|
| t3.xlarge    | Arm      | 0.0              | 0.783%             | 4.53s               |
| t4.xlarge    | x86      | 0.0              | 1.49%             | 4.81s               |


### 크롤링 시간차

<div style="display: flex;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/5b107cec-a629-487f-b344-c65a7f2582cc" alt="Image 1" style="width: 50%;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/699edc51-5f53-4183-b2b4-04756b39d888" alt="Image 2" style="width: 50%;">
</div>

<br/>

-  t3.xlarge(4.59s)가 t4.xlarge(4.81s)보다 빠르다

### cpu 사용량

<div style="display: flex;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/8c1d507c-676d-48e4-b8a6-9e3fb6408179" alt="Image 1" style="width: 50%;">
  <img src="https://github.com/yoonjaeuk/AWS/assets/52642461/a677a9c4-7698-4ba8-bd20-c9609a3ad224" alt="Image 2" style="width: 50%;">
</div>






<br/>

- 가장 높은 수치를 기준으로 t3.xlarge(0.783%) t4.xlarge(1.49%)에 비해 2배 가량 cpu사용량이 적다


 ### 보아야될 사항
 1. 코드를 돌릴 때마다 크롤링 처리 시간이 다르게 나옴
 2. htop 명령어를 입력할 떄마다 cpu 사용량이 다르게 나옴(AWS Monitoring이 조금 느리게 반영)
 3. CPU 사용량이랑 처리 속도 속도가 빠를 줄 알았는데 그렇지 않음
