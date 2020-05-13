/*-----------------------------------------*\
|  SteelSeriesRivalController.h             |
|                                           |
|  Definitions and types for SteelSeries    |
|  Rival lighting controller                |
|                                           |
|  B Horn (bahorn) 13/5/2020                |
\*-----------------------------------------*/

#include <string>
#include <hidapi/hidapi.h>

#pragma once


/* Mode, we then use these to set actual effect based on speed. */
enum
{
    STEELSERIES_RIVAL_STATIC = 0x00,
    STEELSERIES_RIVAL_PULSATE = 0x01
};

/* Effects */
enum
{
    STEELSERIES_RIVAL_EFFECT_STATIC = 0x01,
    STEELSERIES_RIVAL_EFFECT_PULSATE_MIN = 0x02,
    STEELSERIES_RIVAL_EFFECT_PULSATE_MID = 0x03,
    STEELSERIES_RIVAL_EFFECT_PULSATE_MAX = 0x04
};


class SteelSeriesRivalController
{
public:
    SteelSeriesRivalController(hid_device* dev_handle);
    ~SteelSeriesRivalController();

    char* GetDeviceName();

    void Save();
    void SetLightEffect(unsigned char effect);
    void SetColor
            (
                unsigned char red,
                unsigned char green,
                unsigned char blue
            );

private:
    char                    device_name[32];
    hid_device*             dev;

};