#include <stdio.h>
#include <stdlib.h>

// ��Ʒ����
struct Thing {
    int w;    // ����
    int v;    // ��ֵ
    double k; // ��ֵ������

    // ���캯��
    void getK() {
        k = (double)v / w;
    }
};

// �������Ľ��
struct Node {
    int W;           // ��ǰ����
    int V;           // ��ǰ��ֵ
    int ub;          // �ý���Ͻ�
    int level;       // ��ǰ���߲㼶
};

// ���ڱȽϽ������ȼ�������ѣ�
int compareNodes(const void* a, const void* b) {
    return ((Node*)b)->ub - ((Node*)a)->ub; // �Ӵ�С����
}

// ��������Ͻ����
int getUb(Node* node, int C, Thing* things, int M) {
    int _W = node->W;
    int _V = node->V;
    int i = node->level;

    while (_W < C && i < M) {
        if (_W + things[i].w <= C) {
            _W += things[i].w;
            _V += things[i].v;
        } else {
            _V += (C - _W) * things[i].k;
            _W = C;
        }
        i++;
    }

    return _V;
}

int main() {
    int C = 0; // ����������
    int M = 0; // ��Ʒ��Ŀ
    scanf("%d %d", &C, &M);

    Thing things[105]; // ��Ʒ

    // ������Ʒ��������λ��ֵ�Ӵ�С����
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &things[i].w, &things[i].v);
        things[i].getK();
    }

    qsort(things, M, sizeof(Thing), compareNodes);

    Node q[105]; // �������ռ�
    int front = 0, rear = 1;

    Node t;
    t.W = 0;
    t.V = 0;
    t.ub = getUb(&t, C, things, M);
    t.level = 0;
    q[0] = t;

    int result = 0; // ���Ž�

    while (front < rear) {
        Node f = q[front++];

        if (f.V > result) {
            result = f.V;
        }

        if (f.level < M) {
            Node l = f;
            l.level++;
            l.ub = getUb(&l, C, things, M);

            if (l.ub > result) {
                q[rear++] = l;
            }
        }

        Node r = f;
        r.level++;
        r.W += things[f.level].w;
        r.V += things[f.level].v;
        r.ub = getUb(&r, C, things, M);

        if (r.ub > result && r.W <= C) {
            q[rear++] = r;
        }
    }

    printf("%d\n", result);

    return 0;
}

