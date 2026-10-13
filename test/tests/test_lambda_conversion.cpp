#include <gtest/gtest.h>

#include "lambda_conversion.h"

TEST(LambdaConversion, ClampedStaysNearTwo)
{
    // Above historical LSU49 lean clamp (Ip > 1.11 -> lambda ~2)
    float clamped = ConvertPumpCurrentToLambda(1.5f, true);
    EXPECT_NEAR(2.0f, clamped, 1e-3f);

    float unclamped = ConvertPumpCurrentToLambda(1.5f, false);
    EXPECT_GT(unclamped, 2.5f);
}

TEST(LambdaConversion, StoichNearOne)
{
    // Near-zero pump current -> near stoich
    float lambda = ConvertPumpCurrentToLambda(0.0f, false);
    EXPECT_NEAR(1.0f / 0.99559f, lambda, 1e-3f);
}

TEST(LambdaConversion, HighLambdaEncodable)
{
    // Ensure unclamped path can represent values well above 2 (e.g. ~10+)
    // before uint16 x1000 packing saturates at ~65.535
    float lambda = ConvertPumpCurrentToLambda(2.0f, false);
    EXPECT_GT(lambda, 8.0f);
    EXPECT_LE(lambda, 65.535f);
}

TEST(LambdaConversion, O2PercentFromLambda)
{
    EXPECT_NEAR(0.0f, ConvertLambdaToO2Percent(1.0f), 1e-3f);
    EXPECT_NEAR(10.475f, ConvertLambdaToO2Percent(2.0f), 1e-3f);
    // Rich: formula is negative, clamped to 0
    EXPECT_FLOAT_EQ(0.0f, ConvertLambdaToO2Percent(0.8f));
    EXPECT_FLOAT_EQ(0.0f, ConvertLambdaToO2Percent(0.0f));
}
