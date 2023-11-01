struct Dsu
{
	vi par, sz;
	Dsu(int n)
	{
		par.resize(n + 1);
		fore(i, 1, n) par[i] = i, sz[i] = 1;
	}
	int find(int u)
	{
		if (par[u] == u) return u;
		return par[u] = find(par[u]);
	}
	bool join(int u, int v)
	{
		u = find(u);
		v = find(v);
		if (u == v) return 0;
		if (sz[v] > sz[u]) swap(u, v);
		sz[u] += sz[v];
		par[v] = u;
		return 1;
	}
};
