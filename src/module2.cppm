module;  // Global module fragment

export module module2;

export auto b() {
    struct Point { int x; int y; };
    return Point{1, 2};
}
