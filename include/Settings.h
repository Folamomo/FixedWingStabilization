//
// Created by igor on 18.12.2020.
//

#ifndef UAV_SETTINGS_H
#define UAV_SETTINGS_H
/*
 * 0 = +/- 250 degrees/sec
 * 1 = +/- 500 degrees/sec
 * 2 = +/- 1000 degrees/sec
 * 3 = +/- 2000 degrees/sec
 */
#define gyroSetting 0
#define gyroRange 250

/*
 * 0 = +/- 2g
 * 1 = +/- 4g
 * 2 = +/- 8g
 * 3 = +/- 16g
 */
#define accSetting 0
#define accRange 2

#define magnetometerRange 8


#define FREQUENCY 100
#define DT 1.0/FREQUENCY

#endif //UAV_SETTINGS_H
