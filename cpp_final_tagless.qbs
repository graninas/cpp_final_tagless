import qbs

CppApplication {
    consoleApplication: true
    files: [
        "ft/expected.h",
        "ft/ft.h",
        "ft/functional_concepts.h",
        "ft/io.h",
        "ft/kv_db.h",
        "ft/logger.h",
        "ft/optional.h",
        "ft/prelude.h",
        "ft/random.h",
        "ft/serialization.h",
        "ft/unit.h",
        "labyrinth/app.h",
        "main.cpp",
    ]

    Depends { name: "cpp" }
//    cpp.cppFlags: "-std=c++2a"
    cpp.cppFlags: [ "-std=c++2a", "-w", "-fconcepts-diagnostics-depth=2"]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
