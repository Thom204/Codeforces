#include <algorithm>
#include <vector>

template <typename T, typename Func>
void combine(const std::vector<T>& v, int n, Func proc_fn) {
    std::vector<T> selected;

    auto generate = [&](auto&& self, int start) -> void {
        if (static_cast<int>(selected.size()) == n) {
            proc_fn(selected);
            return;
        }

        int remaining = n - static_cast<int>(selected.size());
        for (int i = start; i <= static_cast<int>(v.size()) - remaining; ++i) {
            selected.push_back(v[i]);
            self(self, i + 1);
            selected.pop_back();
        }
    };

    if (n >= 0 && n <= static_cast<int>(v.size())) {
        generate(generate, 0);
    }
}

template <typename T, typename Func>

void permute(std::vector<T>& v, std::size_t start, std::size_t end, Func proc_fn) {
    if (start >= end) {
        proc_fn(v);
        return;
    }

    for (std::size_t i = start; i <= end; ++i) {
        std::swap(v[start], v[i]);
        permute(v, start + 1, end, proc_fn);
        std::swap(v[start], v[i]);
    }
}


