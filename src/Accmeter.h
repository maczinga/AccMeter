/**
 * \file Accmeter.h
 * \brief A class for dealing a generic accelerometer module.
 * \author Enrico Formenti
 * \date 5 march 2015
 * \version 1.0
 * \copyright BSD license, check the License page on the blog for more information. All this text must be
 * included in any redistribution.
 * <br><br>
 * See macduino.blogspot.com for more details.
 */

#include <math.h>

#ifndef __Accmeter.h
#define __Accmeter.h

class Accmeter {
protected:
    /**
     * @name Calibration variables
     * \brief These variables save an offset value which is used to correct the measurement of acceleration.
     * \see calibrate
     * @{
     */
    float _xOff, _yOff, _zOff;
    /** @} */
    /**
     * @name Current read variables
     * \brief These variables contain the last reading of the variables.
     * \warning The values have not been corrected, so do not use these values directly but pass through
     * getAccX(), getAccY() or getAccZ() functions.
     * \see getAccX, getAccY, getAccZ
     * @{
     */
    float _x, _y, _z;
    /** @} */
    /**
     * \var _sensitivity
     * \brief This is a constant whose value depends from the module used. It is used to correctly scale
     * the readings.
     */
     float _sensitivity;
public:
    /**
     * \fn Accmeter()
     * \brief Empty construct which just assign a dummy value to _sensitivity variable.
    */
    Accmeter() : _sensitivity(1.0) {};
    /**
     * \fn float getX()
     * \brief Returns the value of the acceleration along the X axis.
     * \warning This is a rough readout value which has to be corrected and scaled. So it should not be used
     * directly.
     * \return The current measurement of the acceleration along the X axis.
     */
    virtual float getX() = 0;
    /**
     * \fn float getY()
     * \brief Returns the value of the acceleration along the Y axis.
     * \warning This is a rough readout value which has to be corrected and scaled. So it should not be used
     * directly.
     * \return The current measurement of the acceleration along the Y axis.
     */
    virtual float getY() = 0;
    /**
     * \fn float getZ()
     * \brief Returns the value of the acceleration along the Z axis.
     * \warning This is a rough readout value which has to be corrected and scaled. So it should not be used
     * directly.
     * \return The current measurement of the acceleration along the Z axis.
     */
    virtual float getZ() = 0;
    /**
     * \fn calibrate()
     * \brief Save offset values of the acceleration. These should be used for correcting the successive
     * measurements.
     */
    void calibrate() { _xOff = getX(); _yOff = getY(); _zOff = getZ(); };
    /**
     * \fn getAccX()
     * \brief Returns the current value of the accelearation along the X axis.
     * \warning The value has been scaled and corrected.
     * \see getAccY, getAccZ
     */
    inline float getAccX() { return (getX()-_xOff)/sensitivity; };
    /**
     * \fn getAccY()
     * \brief Returns the current value of the accelearation along the Y axis.
     * \warning The value has been scaled and corrected.
     * \see getAccX, getAccZ
     */
    inline float getAccY() { return (getY()-_yOff)/sensitivity; };
    /**
     * \fn getAccZ()
     * \brief Returns the current value of the accelearation along the Z axis.
     * \warning The value has been scaled and corrected.
     * \see getAccX, getAccZ
     */
    inline float getAccZ() { return (getZ()-_zOff)/sensitivity; };
    /**
     * \fn getPitch()
     * \brief Returns the pitch angle.
     * \return Pitch angle (measured in degrees)
     * \see getRoll
     */
    float getPitch();
    /**
     * \fn getRoll()
     * \brief Returns the roll angle.
     * \return Roll angle (measured in degrees)
     * \see getRoll
     */
    float getRoll()};
#endif