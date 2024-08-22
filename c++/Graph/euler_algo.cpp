#include <bits/stdc++.h>
#define task "Euler."

using namespace std;

typedef int arr[1001];
typedef int arr2[1001][1001];

// Nhập dữ liệu cho đồ thị. Thao tác này có thể dễ dàng điều chỉnh 
// khi đề bài thay đổi cách nhập liệu.
void enter(int &n, arr2 adj, arr deg)
{
    cin >> n;

    int u, v, k;
    while (cin >> u >> v >> k)
    {
        adj[u][v] = adj[v][u] = k;

        deg[u] += k;
        deg[v] += k;
    }
}

void dfs(int n, int u, int cnt_comps, arr2 adj, arr number) // Đếm số TPLT của đồ thị.
{
    number[u] = cnt_comps;

    for (int v = 1; v <= n; ++v)
        if (!number[v] && adj[u][v])
            dfs(n, v, cnt_comps, adj, number);
}

// Kiểm tra đồ thị có phải đồ thị Euler không.
bool check_euler_graph(int n, arr2 adj, arr deg)
{
    // Đếm số thành phần liên thông của đồ thị.
    int cnt_comps = 0;
    arr number;
    for (int u = 1; u <= n; ++u)
        if (!number[u])
        {
            ++cnt_comps;
            dfs(n, u, cnt_comps, adj, number);
        }

    // Nếu đồ thị không liên thông thì nó không phải đồ thị Euler.
    if (cnt_comps > 1)
        return false;

    // Nếu tồn tại đỉnh có bậc lẻ thì cũng không phải đồ thị Euler.
    for (int u = 1; u <= n; ++u)
        if (deg[u] % 2 == 1)
            return false;

    return true;
}

// Kiểm tra xem nếu xóa cạnh (u, v) thì có thể đi ngược từ v về u không.
bool can_go_back(int n, arr2 adj, int u, int v)
{
    // Thử xóa cạnh (u, v), tức là số cạnh nối giảm đi 1.
    --adj[u][v];
    --adj[v][u];

    // Sau khi xóa cạnh (u, v), thử bfs từ v tới u xem có đi được nữa không.
    bool is_free[n + 1];
    fill(is_free + 1, is_free + n + 1, true);

    queue < int > path;
    path.push(v);

    while (!path.empty())
    {
        int cur = path.front();
        path.pop();

        if (cur == u)
            break;

        for (int next_v = 1; next_v <= n; ++next_v)
            if (is_free[next_v] && adj[cur][next_v])
            {
                is_free[next_v] = false;
                path.push(next_v);
            }
    }

    // Nối lại cạnh (u, v) do lúc nãy đã thử xóa cạnh này đi.
    ++adj[u][v];
    ++adj[v][u];

    return !is_free[u];
}

// Giải thuật Fleury tìm chu trình Euler trên đồ thị.
void fleury(int n, arr2 adj, arr deg)
{
    // Đồ thị không phải đồ thị Euler -> In ra 0.
    if (!check_euler_graph(n, adj, deg))
    {
        cout << 0;
        return;
    }

    int cur_vertex = 1, next_v = 0;
    vector < int > circuit;
    step.push_back(cur_vertex);

    do
    {
        next_v = 0;

        // Lần lượt chọn các cạnh liên thuộc với đỉnh hiện tại
        // trong chu trình đang xét.
        for (int v = 1; v <= n; ++v)
            if (adj[cur_vertex][v])
            {
                next_v = v;

                // Ưu tiên chọn cạnh không phải là cạnh "một đi không trở lại".
                if (can_go_back(n, adj, cur_vertex, next_v))
                    break;
            }

        // Tìm được 1 cạnh nối chưa bị xóa có thể đi được.
        if (next_v != 0)
        {
            // Xóa cạnh nối đó đi.
            --adj[cur_vertex][next_v];
            --adj[next_v][cur_vertex];

            step.push_back(next_v); // Đưa đỉnh này vào danh sách các đỉnh trên chu trình.

            cur_vertex = next_v;
        }
    }
    while (next_v != 0);

    // In ra chu trình tìm được.
    for (int u: circuit)
        cout << u << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    arr2 adj;
    arr deg;

    enter(n, adj, deg);
    fleury(n, adj, deg);

    return 0;
}
