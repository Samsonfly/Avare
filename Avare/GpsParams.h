/*
Copyright (c) 2015, Apps4Av Inc. (apps4av.com)
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*
*     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//
// GpsParams.h
// Declaration of the GpsParams class.
// Author: Salem Gbian
//

#pragma once
#include <string>

/**
* A class to hold GPS params in the format we need
*/
class GpsParams sealed
{
	private:
		double mSpeed;
		double mLongitude;
		double mLatitude;
		double mAltitude;
		double mBearing;
		//Scale  mScale;
		float  mDeclination;
		long   mTime;
		std::string getDMS();

	public:
		GpsParams();
		GpsParams(Windows::Devices::Geolocation::Geocoordinate geoCoordinate);
		static GpsParams* copy(GpsParams rhs);
		static double speedConvert(double locationSpeed);
		double getSpeed() const;
		double getLongitude() const;
		double getLatitude() const;
		double getAltitude() const;
		double getBearing() const;
		//Scale getScale() const;
		double getDeclination() const;
		long getTime() const;
		std::string getLastStringDMS() const;
		std::string getLonStringDMS() const;
		virtual ~GpsParams();
};
