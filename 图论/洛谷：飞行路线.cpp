#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
const int N = 4e6 + 10;
int n,m,k;
int sta, en;
int h[N],w[N],e[N],ne[N],idx = 0;
int dist[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

typedef struct edge{
    int a, b, w;
}edge;

edge edges[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);//初始化dist数组
    dist[sta] = 0;//将起点的最短距离记为0
    priority_queue<PII, vector<PII>, greater<PII>> heap;//由于需要不断取出最小值，则定义一个小根堆
    heap.push({0, sta});//把起点加入堆内，pair第一个数存储最短距离，第二个数存储是哪个点

    while (heap.size())//若堆不空
    {
        auto t = heap.top();//取出当前距离最短点
        heap.pop();//去除堆顶元素

        int ver = t.second, distance = t.first;//ver记录点，distance记录最短距离

        if (st[ver]) continue;//若该点被使用过，重新开始
        st[ver] = true;//若该点未被使用过，记录

        for (int i = h[ver]; i != -1; i = ne[i])//遍历ver点的邻边
        {
            int j = e[i];//j为i下标记录的点
            if (dist[j] > dist[ver] + w[i])//若j到起点的最短距离小于ver点到起点的最短距离加ver点到j的距离，则更新j，将其加入队列
            {
                dist[j] = dist[ver] + w[i];//更新最短距离
                heap.push({dist[j], j});//向堆内加入j点
            }
        }
    }

    int ret = 0x3f3f3f3f;
    for(int i = 0; i <= k; i++){
        ret = min(ret, dist[en + i*n]);
    }
    return ret;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m >> k >> sta >> en;
    //录入边
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);
        add(edges[i].a, edges[i].b, edges[i].w);
        add(edges[i].b, edges[i].a, edges[i].w);
    }
    //建分层图
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < m; j++){
            add(edges[j].a + (i - 1)*n, edges[j].b + i*n, 0);//连上一层
            add(edges[j].b + (i - 1)*n, edges[j].a + i*n, 0);//连上一层
            add(edges[j].a + i*n, edges[j].b + i*n, edges[j].w);//连本层
            add(edges[j].b + i*n, edges[j].a + i*n, edges[j].w);//连本层
        }
    }
    int t = dijkstra();
    if(t == 0x3f3f3f3f) printf("-1");
    else printf("%d",t);
    return 0;
}