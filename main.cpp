
#include "ft/ft.h"
#include "labyrinth/app.h"

using namespace ft;
using namespace lab;

int main() {
    App app;

    test_method<App>(app);

    generate_and_say<App>(app);
    generate_and_say<App>(app);
    generate_and_say<App>(app);
    generate_and_say<App>(app);
    generate_and_say<App>(app);
}
