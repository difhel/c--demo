module;

#include <concepts>

export module structural_eq;

template<typename T, typename U>
concept HasXY = requires(T t, U u) {
    { t.x } -> std::convertible_to<int>;
    { t.y } -> std::convertible_to<int>;
    { u.x } -> std::convertible_to<int>;
    { u.y } -> std::convertible_to<int>;
};

export template<typename T, typename U>
requires HasXY<T, U>
bool operator==(const T& lhs, const U& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
