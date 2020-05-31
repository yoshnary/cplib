#ifndef CPLIB_LIB_CONVEX_HULL_TRICK_H_
#define CPLIB_LIB_CONVEX_HULL_TRICK_H_

template<class T, class Comp = std::less<T>>
struct ConvexHullTrick {
public:
    ConvexHullTrick(const Comp &comp = Comp()) : comp(comp) {}

    void add_line(T slope, T intercept) {
        Line line(slope, intercept);
        while (lines.size() >= 2) {
            if (check_valid(*(lines.end() - 2), lines.back(), line)) break;
            lines.pop_back();
        }
        lines.emplace_back(slope, intercept);
    }

    T evaluate(T x) {
        assert(!lines.empty());

        int lo = -1, hi = (int)lines.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            T v1 = evaluate(lines[mid], x);
            T v2 = evaluate(lines[mid + 1], x);
            if (comp(v1, v2)) hi = mid;
            else lo = mid;
        }
        return evaluate(lines[hi], x);
    }

private:
    const Comp comp;
    using Line = std::pair<T, T>;
    std::vector<Line> lines;

    T check_valid(Line l1, Line l2, Line l3) {
        if (l1.first < l3.first) std::swap(l1, l3);
        T lhs = (l3.second - l2.second)*(l2.first - l1.first);
        T rhs = (l2.second - l1.second)*(l3.first - l2.first);
        return lhs < rhs;
    }

    T evaluate(const Line &line, T x) {
        return line.first*x + line.second;
    }
};

#endif  // CPLIB_LIB_CONVEX_HULL_TRICK_H_
