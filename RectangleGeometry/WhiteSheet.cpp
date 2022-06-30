// difficulty: hard
#include <iostream>
#include <tuple>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// best answer
struct Rect {
    ll x1, y1, x2, y2;

    ll area() const {
        if (x2 < x1 || y2 < y1) return 0;
        else return (x2 - x1) * (y2 - y1);
    }
};
Rect its(Rect a, Rect b) {
    Rect res;
    res.x1 = max(a.x1, b.x1);
    res.x2 = min(a.x2, b.x2);
    res.y1 = max(a.y1, b.y1);
    res.y2 = min(a.y2, b.y2);
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    Rect w, b1, b2;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
 
    // adding the last expression is crucial, as some res may have been already added
    ll res = w.area() - its(w, b1).area() - its(w, b2).area() + its(w, its(b1, b2)).area();
    if (res > 0) cout << "YES\n";
    else cout << "NO\n";
}

// slightly overcomplicated answer that fails test case 16
/*
struct Rect {
    ll x1, y1, x2, y2;
    std::tuple<ll, ll, ll, ll> new_coords(Rect r2) {
        if (x1>=r2.x1 && x2<=r2.x2 && y1<r2.y1 && y2<=r2.y2) {
            // top is covered
            return std::make_tuple(x1, y1, x2, r2.y1);
        }
        else if (x1>=r2.x1 && x2<=r2.x2 && y1>=r2.y1 && y2>r2.y2) {
            // bottom is covered
            return std::make_tuple(x1, r2.y2, x2, y2);
        }
        else if (y1>=r2.y1 && y2<=r2.y2 && x1<r2.x1 && x2<=r2.x2) {
            // right is covered
            return std::make_tuple(x1, y1, r2.x1, y2);
        }
        else if (y1>=r2.y1 && y2<=r2.y2 && x1>=r2.x1 && x2>r2.x2) {
            // left is covered
            return std::make_tuple(r2.x2, y1, x2, y2);
        }
        else if (x1>=r2.x1 && x2<=r2.x2 && y1<=r2.y1 && y2<=r2.y2) {
            // whole sheet is covered
            return std::make_tuple(0, 0, 0, 0);
        }
        // whole sheet must be covered
        else {return std::make_tuple(x1, y1, x2, y2);}   
    }
    ll area() const {return (x2-x1) * (y2-y1);}
    ll intersection (Rect r2) {
        return (min(x2, r2.x2) - max(x1, r2.x1)) * (min(y2, r2.y2) - max(y1, r2.y1));
    }
    void assign_coords(std::tuple<ll, ll, ll, ll> coords) {
        x1 = get<0>(coords);
        y1 = get<1>(coords);
        x2 = get<2>(coords);
        y2 = get<3>(coords);
    }
};
int main() {
    Rect W, B1, B2;
    cin >> W.x1 >> W.y1 >> W.x2 >> W.y2;
    cin >> B1.x1 >> B1.y1 >> B1.x2 >> B1.y2;
    cin >> B2.x1 >> B2.y1 >> B2.x2 >> B2.y2;
    tuple<ll, ll, ll, ll> coords;
    coords = W.new_coords(B1);
    W.assign_coords(coords);
    if (W.area() == W.intersection(B2) || coords==std::make_tuple(0, 0, 0, 0)) {cout << "NO";}
    else {cout << "YES";}
    cout << "\n";
    return 0;
} */