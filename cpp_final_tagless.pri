# targets

win32:       CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/release/ -lcpp_final_tagless
else:win32:  CONFIG(debug, debug|release):   LIBS += -L$$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/debug/   -lcpp_final_tagless
else:unix:                                   LIBS += -L$$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/         -lcpp_final_tagless

INCLUDEPATH += $$PWD/../../lib/cpp_final_tagless/cpp_final_tagless
DEPENDPATH  += $$PWD/../../lib/cpp_final_tagless/cpp_final_tagless

win32-g++:             CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/release/libcpp_final_tagless.a
else:win32-g++:        CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/debug/libcpp_final_tagless.a
else:win32:!win32-g++: CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/release/cpp_final_tagless.lib
else:win32:!win32-g++: CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/debug/cpp_final_tagless.lib
else:unix:                                             PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_final_tagless/cpp_final_tagless/libcpp_final_tagless.a
