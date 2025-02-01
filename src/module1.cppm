module;  // Global module fragment

export module module1;

export auto a() {
    struct Point { int x; int y; };
    return Point{1, 2};
}
