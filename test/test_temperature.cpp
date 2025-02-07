#include <unity.h>
#include "../src/sensor/Temperature.h"

void test_temperature_initialization() {
    Temperature temp(39);
    TEST_ASSERT_FLOAT_WITHIN(0.1, 0.0, temp.getLastReading());
}

void test_temperature_validity_check() {
    Temperature temp(39);
    TEST_ASSERT_TRUE(temp.isValid(25.0));
    TEST_ASSERT_FALSE(temp.isValid(-100.0));
    TEST_ASSERT_FALSE(temp.isValid(150.0));
}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_temperature_initialization);
    RUN_TEST(test_temperature_validity_check);
    UNITY_END();
}

void loop() {}
