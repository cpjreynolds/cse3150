#ifndef IVEC_HPP
#define IVEC_HPP

#include <iostream>
#include <vector>

struct int_vector {
    int id;
    int from;
    int to;

    int_vector() : id(-1), from(0), to(0){};
    int_vector(int id, int from, int to) : id(id), from(from), to(to){};
    // the compiler will supply the memberwise-copy constructor
    int_vector(const int_vector&) = default;

    static std::vector<int_vector> from_stream(std::istream& is)
    {
        int i = 0;
        std::vector<int_vector> vec;
        for (int_vector iv(0, 0, 0); is >> iv; iv.id = ++i) {
            vec.push_back(iv);
        }
        return vec;
    }

    friend auto operator<=>(const int_vector& lhs,
                            const int_vector& rhs) = default;

    friend std::istream& operator>>(std::istream& is, int_vector& tgt)
    {
        is >> tgt.from;
        return is >> tgt.to;
    }

    friend std::ostream& operator<<(std::ostream& os, const int_vector& self)
    {
        return os << self.id << ": " << self.from << " " << self.to;
    }
};

#endif
