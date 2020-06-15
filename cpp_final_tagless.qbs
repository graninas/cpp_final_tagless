import qbs

CppApplication {
    consoleApplication: true
    files: [
        "ft/ft.h",
        "ft/io.h",
        "ft/kv_db.h",
        "ft/logger.h",
        "ft/prelude.h",
        "labyrinth/labyrinth.h",
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
