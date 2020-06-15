import qbs

CppApplication {
    consoleApplication: true
    files: [
        "ft/context.h",
        "ft/feature_test.h",
        "ft/ft.h",
        "labyrinth/labyrinth.h",
        "labyrinth/logger.h",
        "labyrinth/player.h",
        "labyrinth/prelude.h",
        "main.cpp",
    ]

    Depends { name: "cpp" }
    cpp.cppFlags: "-std=c++2a"

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
