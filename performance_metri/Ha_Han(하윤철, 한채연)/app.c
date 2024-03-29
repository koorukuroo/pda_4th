#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#define NUM_PROCESSES 4 // 원하는 프로세스의 수로 변경 가능

// CPU에 단순연산 작업으로 성능을 측정하는 코드
double get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
void cpu_bound_task(int iterations) {
    double result = 0;
    for (int i = 0; i < iterations; ++i) {
        // 강한 CPU 부하를 주는 연산을 수행합니다.
        result += 1.0;
    }
}
int main() {
    int iterations_per_process = 100000000; // 각 프로세스에서 수행할 반복 횟수
    double start_time, end_time;
    int pid, status;
    printf("Running benchmark with %d processes...\n", NUM_PROCESSES);
    start_time = get_wall_time();
    // 지정된 수의 프로세스를 생성합니다.
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // 자식 프로세스
            cpu_bound_task(iterations_per_process);
            exit(EXIT_SUCCESS);
        }
    }
    // 모든 자식 프로세스가 종료될 때까지 대기합니다.
    while (wait(&status) > 0);
    end_time = get_wall_time();
    printf("Elapsed time with %d processes: %.2f seconds\n", NUM_PROCESSES, end_time - start_time);
    return 0;
}