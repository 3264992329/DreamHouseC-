#include <stdio.h>
#include <stdlib.h>

// 物品类型
struct Thing {
    int w;    // 质量
    int v;    // 价值
    double k; // 价值比质量

    // 构造函数
    void getK() {
        k = (double)v / w;
    }
};

// 搜索树的结点
struct Node {
    int W;           // 当前质量
    int V;           // 当前价值
    int ub;          // 该结点上界
    int level;       // 当前决策层级
};

// 用于比较结点的优先级（大根堆）
int compareNodes(const void* a, const void* b) {
    return ((Node*)b)->ub - ((Node*)a)->ub; // 从大到小排序
}

// 计算结点的上界估计
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
    int C = 0; // 背包总容量
    int M = 0; // 物品数目
    scanf("%d %d", &C, &M);

    Thing things[105]; // 物品

    // 输入物品，并按单位价值从大到小排序
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &things[i].w, &things[i].v);
        things[i].getK();
    }

    qsort(things, M, sizeof(Thing), compareNodes);

    Node q[105]; // 搜索结点空间
    int front = 0, rear = 1;

    Node t;
    t.W = 0;
    t.V = 0;
    t.ub = getUb(&t, C, things, M);
    t.level = 0;
    q[0] = t;

    int result = 0; // 最优解

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

