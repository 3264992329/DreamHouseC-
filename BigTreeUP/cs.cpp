#include <stdio.h>
#include <stdlib.h>

// ��������ṹ��
typedef struct {
    int execution_time;        // ִ��ʱ��
    int deadline;              // ��ֹʱ��
    int selected;              // �Ƿ���ѡ��
} Job;

// ����״̬�ṹ��
typedef struct {
    int current_time;          // ��ǰ��ִ��ʱ��
    int total_time;            // ��ǰ��ִ��ʱ��
    int current_value;         // ��ǰĿ�꺯��ֵ
    int job_count;             // ��ѡ���������
    Job* jobs;                 // ��������
} State;

// ���ݽ�ֹʱ������ıȽϺ���
int compareByDeadline(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->deadline - jobB->deadline;
}

// ��֧�޽���������
void branchAndBound(State* current_state, State* best_solution, int n) {
    if (current_state->job_count == n) {
        // ����Ѿ�ѡ�����������񣬸������Ž�
        if (current_state->current_value < best_solution->current_value) {
            *best_solution = *current_state;
        }
        return;
    }

    // ��չ״̬
    for (int i = 0; i < n; i++) {
        if (!current_state->jobs[i].selected) {
            State next_state = *current_state;
            next_state.jobs[i].selected = 1;
            next_state.current_time += next_state.jobs[i].execution_time;
            next_state.total_time += next_state.current_time;
            next_state.current_value = next_state.total_time - next_state.jobs[i].deadline;
            next_state.job_count++;

            // ��֦�����������ǰֵ�Ѿ�������ǰ���Ž⣬��ֹͣ��չ
            if (next_state.current_value < best_solution->current_value) {
                branchAndBound(&next_state, best_solution, n);
            }
        }
    }
}

int main() {
    int n;
    printf("����������: ");
    scanf("%d", &n);

    Job* jobs = (Job*)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++) {
        printf("����%d��ִ��ʱ��ͽ�ֹʱ��: ", i + 1);
        scanf("%d%d", &jobs[i].execution_time, &jobs[i].deadline);
        jobs[i].selected = 0;
    }

    // ���ս�ֹʱ������
    qsort(jobs, n, sizeof(Job), compareByDeadline);

    State current_state = {0, 0, 0, 0, jobs};
    State best_solution = {0, 0, INT_MAX, 0, NULL};

    branchAndBound(&current_state, &best_solution, n);

    printf("���Ž�: %d\n", best_solution.current_value);

    free(jobs);
    return 0;
}
