#ifndef ZEPTODEMO_GEOMVECTOR_H
#define ZEPTODEMO_GEOMVECTOR_H

#include <array>
#include <algorithm>

template<typename T, size_t n>
class GeomVector
{
public:
    GeomVector() : comps_() {
    }

    template<typename... Args>
    GeomVector(Args... args) {
        fill_<0, Args...>(args...);
    }

    T& operator[](size_t ind) { return comps_[ind]; }
    const T& operator[](size_t ind) const { return comps_[ind]; }

    bool operator==(const GeomVector& other) const { return comps_ == other.comps_; }

    T lengthSquared() const  {
        return std::accumulate(begin(comps_), end(comps_), T(), [](const T& a, const T& b) {
            return a + b * b;
        });
    }

    const GeomVector& operator+=(const GeomVector& other) {
        for (int i = 0; i < n; ++i)
            comps_[i] += other.comps_[i];
        return *this;
    }

    const GeomVector& operator-=(const GeomVector& other) {
        for (int i = 0; i < n; ++i)
            comps_[i] -= other.comps_[i];
        return *this;
    }

    const GeomVector& operator*=(const T& multiplier) {
        for (int i = 0; i < n; ++i)
            comps_[i] *= multiplier;
        return *this;
    }

private:
    template<size_t Offset, typename U, typename... Args>
    void fill_(const U& u, Args... args) {
        comps_[Offset] = u;
        fill_<Offset + 1, Args...>(args...);
    }

    template<size_t Offset>
    typename std::enable_if<Offset==n>::type fill_() {}

    std::array<T, n> comps_;
};

template<typename T, size_t n>
GeomVector<T, n> operator+(const GeomVector<T, n>& a, const GeomVector<T, n>& b) {
    auto res = a;
    res += b;
    return res;
}

template<typename T, size_t n>
GeomVector<T, n> operator-(const GeomVector<T, n>& a, const GeomVector<T, n>& b) {
    auto res = a;
    res -= b;
    return res;
}

template<typename T, size_t n>
GeomVector<T, n> operator*(const GeomVector<T, n>& a, const T& b) {
    auto res = a;
    res *= b;
    return res;
}

template<typename T, size_t n>
GeomVector<T, n> operator*(const T& a, const GeomVector<T, n>& b) {
    auto res = b;
    res *= a;
    return res;
}

using GeomVector2F = GeomVector<float, 2>;

#endif //ZEPTODEMO_GEOMVECTOR_H
