
#include "ft/ft.h"
#include "labyrinth/app.h"

using namespace ft;
using namespace lab;
using namespace std;

template <typename A, typename B>
B foldr(const std::function<B(A, B)>& f, B b, const vector<A>& v) {
    for (int val : v) {
        b = f(val, b);
    }
    return b;
}


int main() {
    App app;

    test_method<App>(app);

    generate_and_say<App>(app);
    generate_and_say<App>(app);
    generate_and_say<App>(app);
    generate_and_say<App>(app);
    generate_and_say<App>(app);


    function<int(int, int)> add
            = [](int a, int b) { return a + b; };

    function<int(int, int)> mul
            = [](int a, int b) { return a * b; };

    vector<int> ints = {1, 2, 3, 4};
    int sum = foldr(add, 0, ints);
    int product = foldr(mul, 1, ints);

    cout << endl << sum;       // 10
    cout << endl << product;   // 24


//    function<string(int)> intToStr
//            = [](int val) { return to_string(val); };

//    function<size_t(string)> strLen
//            = [](const string& s) {
//        return s.length();
//    };

//    ft::optional<int> maybeInt = ft::optional(10);
//    ft::optional<string> maybeStr = fmap(intToStr, maybeInt);
//    ft::optional<size_t> maybeLen = fmap(strLen, maybeStr);

//    if (maybeLen.index() == 0) {
//        cout << "Chain is broken.";
//    }
//    else {
//        cout << "Digits count: " << std::get<1>(maybeLen);
//    }

}
