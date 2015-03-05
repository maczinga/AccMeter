/**
 * \file Accmeter.h
 * \brief A class for dealing a generic accelerometer module.
 * \author Enrico Formenti
 * \date 5 march 2015
 * \version 1.0
 * \copyright BSD license, check the License page on the blog for more information. All this text must be
 *  included in any redistribution.
 *  <br><br>
 *  See macduino.blogspot.com for more details.
 *
 */

#include <math.h>

#ifndef __Accmeter.h
#define __Accmeter.h

class Accmeter {
    /**
     * \brief Zero calibration vars
     *
     */
    float _xOff, _yOff, _zOff;
    /**
     * \brief Last reading vars
     *
     */
    float _x, _y, _z;
    static const float _sensitivity;
public:
    Accmeter() : _sensitivity(1.0) {};
    virtual float getX() = 0;
    virtual float getY() = 0;
    virtual float getZ() = 0;
    void calibrate() { _xOff = getX(); _yOff = getY(); _zOff = getZ(); };
    inline float getAccX() { return (getX()-_xOff)/sensitivity; };
    inline float getAccY() { return (getY()-_yOff)/sensitivity; };
    inline float getAccZ() { return (getZ()-_zOff)/sensitivity; };
    float getPitch();
};

#endif