//ll par[100005];

/* //Basic
void make_set(ll v) {
    par[v] = v;
}

ll find(ll v) {
    if (v == par[v])
        return v;
    return find(par[v]);
}

void merg(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b)
        par[b] = a;
}*/

//Path compression
/*
ll find(ll v) {
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}
*/

//union by size
/*
void make_set(ll v) {
    par[v] = v;
    size[v] = 1;
}

void merg(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        par[b] = a;
        size[a] += size[b];
    }
}
*/


//union by Rank
/*
void make_set(ll v) {
    par[v] = v;
    rank[v] = 0;
}

void merg(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        par[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
*/




