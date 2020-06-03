#include <QString>
#include <QtTest>

#include <variant>
#include <iostream>

#include "common.h"
#include "ft/ft.h"
#include "ft/types.h"

class FTTest : public QObject
{
    Q_OBJECT

public:
    FTTest();


private Q_SLOTS:

    void someTest();
};

FTTest::FTTest()
{
}

void FTTest::someTest()
{
    auto val = ft::f(1, 2);
    QVERIFY(val == 1);
}

QTEST_APPLESS_MAIN(FTTest)

#include "tst_final_tagless.moc"

