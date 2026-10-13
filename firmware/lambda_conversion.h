#pragma once

float GetLambda(int ch);
float GetLambdaFull(int ch);

// Convert measured pump current (mA) to lambda.
// When clamped==true, matches the historical rusEFI ~0.5..~2 range.
float ConvertPumpCurrentToLambda(float pumpCurrent, bool clamped);

// Free oxygen % from lambda: 20.95*(1-1/lambda), clamped to >= 0; 0 when lambda <= 0.
float ConvertLambdaToO2Percent(float lambda);
