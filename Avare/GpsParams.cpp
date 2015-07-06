//
// PivotPage.xaml.cpp
// Implementation of the GpsParams class.
//

#include "pch.h"
#include "GpsParams.h"

using namespace std;
using namespace Windows::Devices::Geolocation;

GpsParams::GpsParams()
{
	mSpeed = 0;
	mLongitude = -94.5;
	mLatitude = 39.5;
	mBearing = 0;
	//mScale* = new Scale();
	//mScale.setScaleAlt(mLatitude);
	mDeclination = 0;
	mTime = 0;
}

GpsParams::GpsParams(Geocoordinate geoCoordinate)
{
	if (1)
	{
		mSpeed = 0;
		mLongitude = 0;
		mLatitude = 0;
		mAltitude = 0;
		mBearing = 0;
		//mScale = new Scale();
		//mScale.setScaleAt(mLatitude);
		mDeclination = 0;
		mTime = 0;
		return;
	}

	//mSpeed = geoCoordinate.Speed; //* Preferences.speedConversion; // ms / sec to knot / hr;
	mLongitude = geoCoordinate.Longitude;
	mLatitude = geoCoordinate.Latitude;
	//mAltitude = geoCoordinate.Altitude; // *Preferences.heightConversion; // meters to feet;

	/*
	* Find declination
	
	GeomagneticField gmf = new GeomagneticField((float)location.getLatitude(),
		(float)location.getLongitude(), 0, System.currentTimeMillis());	
	mDeclination = -gmf.getDeclination();
	gmf = NULL;
	*/

	//mBearing = (geoCoordinate.Heading + 360) % 360;
	//mScale = new Scale();
	//mScale.setScaleAt(mLatitude);

	//mTime = geoCoordinate.Timestamp;
}

/***
* Make an exact copy from the RightHandSide into a newly allocated LeftHandSide object
* @param rhs
* @return Duplicate copy of the right hand side
*/
GpsParams* GpsParams::copy(GpsParams rhs)
{
	GpsParams* lhs = new GpsParams();
	lhs->mSpeed = rhs.mSpeed;
	lhs->mLongitude = rhs.mLongitude;
	lhs->mLatitude = rhs.mLatitude;
	lhs->mAltitude = rhs.mAltitude;
	lhs->mBearing = rhs.mBearing;
	//lhs->mScale = rhs.mScale;
	lhs->mDeclination = rhs.mDeclination;
	lhs->mTime = rhs.mTime;
	return lhs;
}

double GpsParams::speedConvert(double locationSpeed)
{
	//return locationSpeed / Preferences.speedConversion;
}

double GpsParams::getSpeed() const
{
	return mSpeed;
}

double GpsParams::getLongitude() const
{
	return mLongitude;
}

double GpsParams::getLatitude() const
{
	return mLatitude;
}

double GpsParams::getAltitude() const
{
	return mAltitude;
}

double GpsParams::getBearing() const
{
	return mBearing;
}

//Scale GpsParams::getScale(){}

double GpsParams::getDeclination() const
{
	return mDeclination;
}

long GpsParams::getTime() const
{
	return mTime;
}

string GpsParams::getLastStringDMS() const
{ 
	//return (mLatitude >= 0 ? "N" : "S") + getDMS(Math.abs(mLatitude));
}

string GpsParams::getLonStringDMS() const
{
	//return (mLongitude >= 0 ? "E" : "W") + getDMS(Math.abs(mLongitude));
}

/***
* Convert the indicated double value into a deg/min/sec string representation
* @param frac
* @return DD MM SS.SS format
*/
string getDMS(double frac) {

	// Degress is the integer part of the number
	double deg = (int)(frac);

	// Minutes is the decimal part of the number multiplied by 60
	frac -= deg;
	frac *= 60;
	double min = (int)(frac);

	// Seconds is the reminder after the minutes calc multipled by 60
	frac -= min;
	double sec = frac * 60;

	// Place all those values into a string and return
	//return string.format("%02.0f\u00B0 %02.0f\' %02.2f\"", deg, min, sec);
}

GpsParams::~GpsParams()
{}
