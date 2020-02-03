#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <cmath>

struct vec {
    double x, y;
    vec() : x(0), y(0) {}
    vec(double x, double y) : x(x), y(y) {}

    vec operator+(const vec &other) const { return vec(x + other.x, y + other.y); }
    vec operator-() const { return vec(-x, -y); }
    vec operator-(const vec &other) const { return vec(x - other.x, y - other.y); }
    double operator*(const vec &other) const { return x * other.x + y * other.y; }
    vec operator*(double t) const { return vec(t * x, t * y); }
    double len() const { return sqrt(x * x + y * y); }
    double len2() const { return x * x + y * y; }
    void normalize() { double length = len(); x = x / length; y = y / length; }
    vec normalized() const { double length = len(); return vec(x / length, y / length); }
    bool operator==(const vec &other) const { return x == other.x && y == other.y; }
    bool operator<(const vec& b) const { return x == b.x ? y < b.y : x < b.x; }
};

struct line {
    vec p0, p1;
};

struct CompareForG {
    bool operator()(const vec &a, const vec &b) const {
        if (a.x == 1 && a.y == 0 && b.x == 1 && b.y == 0)
            return false;
        if (a.x == 1 && a.y == 0)
            return true;
        if (b.x == 1 && b.y == 0)
            return false;

        if (a.y > 0 && b.y <= 0)
            return false;
        else if (a.y < 0 && b.y >= 0)
            return true;
        else if (a.y == 0)
            return b.y > 0;
        else
        {
            double cosa = a.x, cosb = b.x;

            return (a.y > 0 ? cosa < cosb : cosa > cosb);
        }
    }
};
std::map<vec, int> p_map;
std::unordered_map<int, vec> p_coord;

std::vector<std::map<vec, int, CompareForG>> planar_g;


double count_s(std::vector<int> &vertices) {
    int left = 0, right = 0;
    double ind_min = p_coord[vertices[0]].x, ind_max = p_coord[vertices[0]].x;

    for (size_t i = 0; i < vertices.size(); i++) {
        if (p_coord[vertices[i]].x < ind_min) {
            ind_min = p_coord[vertices[i]].x;
            left = i;
        }
        else if (p_coord[vertices[i]].x > ind_max) {
            ind_max = p_coord[vertices[i]].x;
            right = i;
        }
    }

    int tmp = left;
    double s = 0;
    int num = -1;
    if (p_coord[vertices[(left + 1) % vertices.size()]].y > p_coord[(left - 1 + vertices.size()) % vertices.size()].y)
        num = 1;

    while (tmp != right) {
        if (tmp == vertices.size() - 1) {
            s += num * abs(p_coord[vertices[0]].x - p_coord[vertices[tmp]].x) * (p_coord[vertices[0]].y + p_coord[vertices[tmp]].y) / 2;
            tmp = 0;
        }
        else {
            s += num * abs(p_coord[vertices[tmp + 1]].x - p_coord[vertices[tmp]].x) * (p_coord[vertices[tmp + 1]].y + p_coord[vertices[tmp]].y) / 2;
            tmp++;
        }
    }

    num *= -1;

    while (tmp != left) {
        if (tmp == vertices.size() - 1) {
            s += num * abs(p_coord[vertices[0]].x - p_coord[vertices[tmp]].x) * (p_coord[vertices[0]].y + p_coord[vertices[tmp]].y) / 2;
            tmp = 0;
        }
        else {
            s += num * abs(p_coord[vertices[tmp + 1]].x - p_coord[vertices[tmp]].x) * (p_coord[vertices[tmp + 1]].y + p_coord[vertices[tmp]].y) / 2;
            tmp++;
        }
    }

    return s;
}
double dfs(int cur, const vec from, std::vector<int> &vertices, int start) {
    if (start == cur) {
        double res = count_s(vertices);
        return res;
    }

    vertices.push_back(cur);

    auto it = planar_g[cur].upper_bound(from);
    if (it == planar_g[cur].end())
        it = planar_g[cur].begin();

    double res = dfs(it->second, -it->first, vertices, start);
    planar_g[cur].erase(it);

    return res;

}
int main() {
    int n;
    std::cin >> n;

    std::vector<line> lines;
    for (int i = 0; i < n; i++) {
        line l;
        std::cin >> l.p0.x >> l.p0.y >> l.p1.x >> l.p1.y;

        lines.push_back(l);
    }

    int cur_p = 0;
    for (int i = 0; i < n; i++) {
        std::set<std::pair<vec, int>> intersections;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                line a = lines[i], b = lines[j];
                if ((a.p1.x - a.p0.x) * (b.p1.y - b.p0.y) - (b.p1.x - b.p0.x) * (a.p1.y - a.p0.y) == 0)
                    continue;
                vec inter_point((
                                        (a.p1.x * a.p0.y - a.p0.x * a.p1.y) * (b.p1.x - b.p0.x) -
                                        (b.p1.x * b.p0.y - b.p0.x * b.p1.y) * (a.p1.x - a.p0.x)) /
                                ((a.p1.x - a.p0.x) * (b.p1.y - b.p0.y) - (b.p1.x - b.p0.x) * (a.p1.y - a.p0.y)),

                                ((a.p1.x * a.p0.y - a.p0.x * a.p1.y) * (b.p1.y - b.p0.y) -
                                 (b.p1.x * b.p0.y - b.p0.x * b.p1.y) * (a.p1.y - a.p0.y)) /
                                ((a.p1.x - a.p0.x) * (b.p1.y - b.p0.y) - (b.p1.x - b.p0.x) * (a.p1.y - a.p0.y)));

                if (p_map.find(inter_point) == p_map.end()) {
                    p_map.insert(std::make_pair(inter_point, cur_p++));
                    p_coord.insert(std::make_pair(cur_p - 1, inter_point));
                    planar_g.push_back(std::map<vec, int, CompareForG>());
                }

                intersections.insert(std::make_pair(inter_point, p_map[inter_point]));
            }
        }
        auto end = --intersections.end();

        for (auto it = intersections.begin(); it != end;) {
            auto prev = it++;
            planar_g[prev->second].insert(std::make_pair(((it->first - prev->first).normalized()), it->second));
            planar_g[it->second].insert(std::make_pair((prev->first - it->first).normalized(), prev->second));
        }
    }

    std::vector<double> result;
    for (int i = 0; i < (int)planar_g.size(); i++) {
        while (planar_g[i].size() != 0) {
            std::vector<int> v;
            v.push_back(i);
            double res = dfs(planar_g[i].begin()->second, -planar_g[i].begin()->first, v, i);
            planar_g[i].erase(planar_g[i].begin());
            if (abs(res) > 0.00000001)
                result.push_back(abs(res));
        }
    }
    std::sort(result.begin(), result.end());
    if (result.size() == 0) {
        printf("0");
        return 0;
    }
    int size = result.size() - 1;
    printf("%d\n", size);

    auto end = --result.end();
    for (auto it = result.begin(); it != end; ++it) {
        printf("%.10lf\n", *it);
    }
    return 0;
}