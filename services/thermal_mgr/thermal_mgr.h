#pragma once

#include "lm75bd.h"
#include "errors.h"

typedef enum {
  THERMAL_MGR_EVENT_MEASURE_TEMP_CMD,
  THERMAL_MGR_EVENT_OS_INTERRUPT
} thermal_mgr_event_type_t;

typedef struct {
  thermal_mgr_event_type_t type;
} thermal_mgr_event_t;

#ifdef __cplusplus
extern "C" {
#endif

void initThermalSystemManager(lm75bd_config_t *config);

/**
 * @brief Send an event to the thermal manager queue
 * 
 * @param event Event struct for thermal manager
 */
error_code_t thermalMgrSendEvent(thermal_mgr_event_t *event);

/**
 * @brief Display a temperature reading
 * 
 * @param tempC The temperature to display
 */
void addTemperatureTelemetry(float tempC);

/**
 * @brief Display a message when reaching overtemperature shutdown
 */
void overTemperatureDetected(void);

/**
 * @brief Display a message when reaching hysteresis
 */
void safeOperatingConditions(void);

#ifdef __cplusplus
}
#endif
