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
// GpsInterface.h
// Declaration of the GpsInterface class.
// Author: Salem Gbian
//

#pragma once

using namespace Windows::Devices::Geolocation;

ref class GpsInterface sealed
{
public:

	/*
	* Few callbacks from GPS to make dealing with it easier and uniform
	* This keeps all the GPS logic separate from rest of the code.
	*/

	virtual ~GpsInterface();

	virtual	void statusCallback(ref class Geocoordinate sealed) = 0;

	virtual void locationCallback(ref class Geolocator sealed) = 0;

	virtual void timeoutCallback(boolean timeout) = 0;

	virtual void enabledCallback(boolean enabled) = 0;

};
