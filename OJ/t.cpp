#define MAXN 1024;
int lch[MAXN],rch[MAXN];char op[MAXN];int nc = 0;
int build(char *s,int x,int y){
	int i,c1 = -1,c2 = -1,p = 0;
	int u;
	if (y - x == 1){
		u = ++nc;
		lch[u] = rch[u] = 0;
		op[u] = s[x];
		return u;
	}
	f(i,x,y){
		switch(s[i]){
			case '(': p++;break;
			case ')': p--;break;
			case '+': case '-':if(!p)c1 = i;break;//c1 marks the last +/- shown;
			case '*': case '/':if(!p)c2 = i;break;//c2 shows where the lasr * or / takes place;
		}
	}
	if (c1 < 0)c1 = c2;
	if (c2 < 0)return build(s,x + 1,y - 1);
	u = ++nc;
	lch[u] = build(s,x,c1);
	rch[u] = build(s,c1 + 1,y);
	op[u] = s[c1];
	return u;
}

vector <int> G[MAXN];
void read(){
	int u,v;
	scanf("%d",&n);
	f(i,0,n - 1){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
void dfs(int u,int fa){
	int d = G[u].size();
	f(i,0,d){
		int v = G[u][i];
		if (v != fa)dfs(v,p[v] = u);
	}
}

typedef long long LL;
inline int pow(int x,int y,int p){
	int ans = 1,base = x;
	while (y){
		if (y & 1)ans = (LL)ans * base % p;
		base = base * base % p;
		y >>= 1;
	}
	return ans;
}


//-------------------------------
#define SIZE 1024
int fa[SIZE],rank[SIZE];
inline void init(){
	f(i,0,SIZE)fa[i] = i;
	memset(rank,0,sizeof rank);
}
inline int get(int x){
	if (x == fa[x])return x;
	else return fa[x] = get(fa[x]);
}
inline int get(int x){
	if (x == fa[x])return x;
	int tee = fa[x],te = 0;
	while (tee != fa[tee]){
		tee = fa[tee];
	}
	while (x != tee){
		te = fa[x];
		fa[x] = s;
		x = te;
	}
	return tee;
}
inline void join(int x1,int y1){
	fa[x1] = y1;
	if (rank[y1])rank[x1] += rank[y1];
	else ++rank[x1];
}
inline void Union(int x,int y){
	int x1 = get(x),y1 = get(y);
	if (x1 == y1)return;
	if (rank[x1] < rank[y1]){
		join(x1,y1);
	}else join(y1,x1);

}
struct edge{
	int s,w,t;
	edge(int s = 0,int t = 0,int w = 0):s(s),w(w),t(t){};
} e[SIZE];
inline bool cmp(edge a,edge b){
	return a.w < b.w;
}
int kruskal(){
	int ans = 0;
	sort(e,e + m,cmp);
	f(i,0,m){
		int x1 = get(e[i].x),y1 = get(e[i].y);
		if (x1 == y1)continue;
		Union(x1,y1);
		ans += e[i].w;		
	}
	return ans;
}


//----------------------------

void dijkstra(){
	memset(v,0,sizeof v);
	memset(d,0x1f,sizeof d);
	d[0] = 0;
	f(i,0,n){
		int x,m = 1 << 24;
		f(y,0,n)if (!v[y] && d[y] <= m)m = d[x = y];
		v[x] = 1;
		f(y,0,n)if (d[y] < d[x] + w[x][y]){
			fa[y] = x;
			d[y] = d[x] + w[x][y];
		}
	}
	
}

//----------------------
int n,m;
int first[SIZE},u[SIZE],w[SIZE],v[SIZE],next[SIZE];
void read(){
	scanf("%d%d",&n,&m);
	//(i,0,n)
	memset(first,-1,sizeof first);
	f(e,0,m){
		scanf("%d%d%d",&u[e],&v[e],&w[e]);
		next[e] = first[u[e]];
		first[u[e]] = e;
	}
}

#include <vector>
struct edge{
	int s,w,t;
	edge(int s = 0,int t = 0,int w = 0):s(s),w(w),t(t){};
}
vector<int> G[SIZE];
int n,m;
vector<edge>edges;
bool done[SIZE];
int d[SIZE],p[SIZE];

void init(int x){
	n = x;
	f(i,0,n)G[i].clear();
	edges.clear();
}
void addegde(int s,int t,int w){
	edges.push_back(edge(s,t,w));
	m = edges.size();
	G[s].push_back(m - 1);
}

//-------------------------------------------------------
struct HeapNode{
	int d,u;
	bool operator < (const HeapNode &rhs)const{
		return d > rhs.d;
	}
}
void dijkstra(int s){
	memset(done,0,sizeof done);
	memset(d,0x1f,sizeof d);
	priority_queue<HeapNode> Q;
	d[s] = 0;
	Q.push(HeapNode{0,s});
	while (!q.empty()){
		HeapNode x = Q.top();Q.pop();
		int u = x.u;
		if (done[u])continue;
		done[u] = 1;
		f(i,0,G[u].size()){
			Edge &e = edges[G[u][i]];
			if (d[e.t] > d[u] + e.w){
				d[e.t] = d[u] + e.w;
				fa[e.t] = G[u][i];
				Q.push((HeapNode){d[e.t],e.t]});
			}
		}
	}
}

//---------------------
void Bellman-Ford(){
	memset(d,0x1f,sizeof d);
	d[0] = 0;
	f(k,0,n - 1){
		f(i,0,n){
			int xx = u[i],y = v[i];
			if (d[x] < INF)get_min(d[y],d[x] + w[i]);
		}
	}
}

//------------------------------------
bool SPFA(int s){
	queue<int> Q;
	memset(inq,0,sizeof inq);
	memset(cnt,0,sizeof cnt);
	memset(d,0x1f,sizeof d);
	d[s] = 0;
	inq[s] = 1;
	Q.push(s);
	while (!Q.empty()){
		int u = Q.front();Q.pop();
		inq[u] = false;
		f(i,0,G[u].size()){
			Edge &e = edges[G[u][i]];
			if (d[u] < INF && d[e.t] > d[u] + e.w){
				d[e.t] = d[u] + e.w;
				p[e.t] = G[u][i];
				if (!inq[e.t]){
					Q.push(e.t);
					inq[e.t] = 1;
					if (++cnt[e.t] > n)return false;
				}
			}
		}
	}
	return true;
}

//FLOYD

void floyd(){
memset(d,0x1f,sizeof d);
f(i,0,n)d[i][i] = 0;
	f(k,0,n){
		f(i,0,n){
			f(j,0,n)if (d[i][j] < INF && d[k][j] < INF){
				get_min(d[i][j],d[i][k] + d[k][j]);// care for integer overflow!!
			}
		}		
	}
}
//if we care no more about weights but connected or not?(with 0 && 1)
[row->247] into=>[]
d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
