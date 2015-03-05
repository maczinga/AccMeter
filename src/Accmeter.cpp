/**
 * \file Accmeter.h
 * \brief Implementation of a class for dealing a generic accelerometer module.
 * \author Enrico Formenti
 * \date 5 march 2015
 * \version 1.0
 * \copyright BSD license, check the License page on the blog for more information. All this text must be
 *  included in any redistribution.
 *  <br><br>
 *  See macduino.blogspot.com for more details.
 *
 */

#include "Accmeter.h"

float Accmeter::getPitch() {
    float y = getY();
    float z = getZ();
    
    return atan(getX()/sqrt(y*y+z*z))*180.0/PI;
    
}

float Accmeter::getRoll() {
    float x = getX();
    float z = getZ();
    
    return atan(getY()/sqrt(x*x+z*z))*180.0/PI;
}