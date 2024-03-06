#include <stdio.h>
#include <stdlib.h>

// 定义任务结构体
typedef struct {
    int execution_time;        // 执行时间
    int deadline;              // 截止时间
    int selected;              // 是否已选择
} Job;

// 定义状态结构体
typedef struct {
    int current_time;          // 当前已执行时间
    int total_time;            // 当前总执行时间
    int current_value;         // 当前目标函数值
    int job_count;             // 已选择的任务数
    Job* jobs;                 // 任务数组
} State;

// 根据截止时间排序的比较函数
int compareByDeadline(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->deadline - jobB->deadline;
}

// 分支限界搜索函数
void branchAndBound(State* current_state, State* best_solution, int n) {
    if (current_state->job_count == n) {
        // 如果已经选择了所有任务，更新最优解
        if (current_state->current_value < best_solution->current_value) {
            *best_solution = *current_state;
        }
        return;
    }

    // 扩展状态
    for (int i = 0; i < n; i++) {
        if (!current_state->jobs[i].selected) {
            State next_state = *current_state;
            next_state.jobs[i].selected = 1;
            next_state.current_time += next_state.jobs[i].execution_time;
            next_state.total_time += next_state.current_time;
            next_state.current_value = next_state.total_time - next_state.jobs[i].deadline;
            next_state.job_count++;

            // 剪枝条件：如果当前值已经超过当前最优解，则停止扩展
            if (next_state.current_value < best_solution->current_value) {
                branchAndBound(&next_state, best_solution, n);
            }
        }
    }
}

int main() {
    int n;
    printf("输入任务数: ");
    scanf("%d", &n);

    Job* jobs = (Job*)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++) {
        printf("任务%d的执行时间和截止时间: ", i + 1);
        scanf("%d%d", &jobs[i].execution_time, &jobs[i].deadline);
        jobs[i].selected = 0;
    }

    // 按照截止时间排序
    qsort(jobs, n, sizeof(Job), compareByDeadline);

    State current_state = {0, 0, 0, 0, jobs};
    State best_solution = {0, 0, INT_MAX, 0, NULL};

    branchAndBound(&current_state, &best_solution, n);

    printf("最优解: %d\n", best_solution.current_value);

    free(jobs);
    return 0;
}
