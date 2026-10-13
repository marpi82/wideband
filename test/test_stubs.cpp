#include "status.h"
#include "can.h"
#include "port.h"
#include "sampling.h"

void SetStatus(int, wbo::Status) {}

float GetRemoteBatteryVoltage()
{
    return 0;
}

SensorType GetSensorType()
{
    return SensorType::LSU49;
}

int GetESRSupplyR()
{
    // Nernst AC injection resistor value
    return 22000;
}

// GetLambda/GetLambdaFull need a sampler; unit tests use ConvertPumpCurrentToLambda instead.
const ISampler& GetSampler(int)
{
    static Sampler dummy;
    return dummy;
}
