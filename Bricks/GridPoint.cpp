//
//  GridPoint.cpp
//  Pentomino 3x4x5
//
//  Created by Hans Dockhorn on 19/03/2023.
//



#include "GridPoint.hpp"
#include <limits.h>


// ==========================================================================
//
// class T2DGridPoint
//
// ==========================================================================

T2DGridPoint::T2DGridPoint( void )
{
	// this constructor will give you random data in the member variables !!!
}

T2DGridPoint::T2DGridPoint( const T2DGridPoint &rhs )
{
	 x = rhs.x;
	 y = rhs.y;
	
}

T2DGridPoint::T2DGridPoint( int _x, int _y )
{
	 x = _x;
	 y = _y;
}


// --------------------------------------------------------------------------
//
// comparison operators
//
// --------------------------------------------------------------------------

bool T2DGridPoint::operator == ( const T2DGridPoint& rhs ) const
{
	 return (x == rhs.x) && (y == rhs.y);
}

bool T2DGridPoint::operator != ( const T2DGridPoint& rhs ) const
{
	 return (x!=rhs.x) || (y!=rhs.y);
}

bool T2DGridPoint::operator < ( const T2DGridPoint& rhs ) const
{
	if ( y < rhs.y ) return true;
	if ( y > rhs.y ) return false;
	if ( x < rhs.x ) return true;
	return false;
}



// --------------------------------------------------------------------------
//
// binary operators with assignment
//
// --------------------------------------------------------------------------


T2DGridPoint T2DGridPoint::operator + ( const T2DGridPoint& rhs) const
{
	 return T2DGridPoint( x+rhs.x, y+rhs.y );
}

T2DGridPoint T2DGridPoint::operator - ( const T2DGridPoint& rhs) const
{
	 return T2DGridPoint( x-rhs.x, y-rhs.y );
}



// --------------------------------------------------------------------------
//
// binary operators without assignment
//
// --------------------------------------------------------------------------

void T2DGridPoint::operator += ( const T2DGridPoint& rhs )
{
	 x += rhs.x;
	 y += rhs.y;
}

void T2DGridPoint::operator -= ( const T2DGridPoint& rhs)
{
	 x -= rhs.x;
	 y -= rhs.y;
}


// --------------------------------------------------------------------------
//
// utility functions
//
// --------------------------------------------------------------------------

bool T2DGridPoint::IsZero() const
{
	 return (x==0) && (y==0);
}


void T2DGridPoint::Translate( int dx, int dy )
{
	 x += dx;
	 y += dy;
}

void T2DGridPoint::Translate( const T2DGridPoint &rhs )
{
	x += rhs.x;
	y += rhs.y;
}

void T2DGridPoint::Set( int new_x, int new_y )
{
	 x = new_x;
	 y = new_y;
}



// --------------------------------------------------------------------------
//
// member varaible access functions
//
// --------------------------------------------------------------------------

const int T2DGridPoint::getX( void ) const
{
	return x;
}

const int T2DGridPoint::getY( void ) const
{
	return y;
}



// --------------------------------------------------------------------------
//
// rotation and mirroring functions
//
// --------------------------------------------------------------------------

void T2DGridPoint::Rotate90( void ) { int h=x; x=-y; y=h; }
void T2DGridPoint::Rotate180( void ) { x=-x; y=-y; }
void T2DGridPoint::Rotate270( void ) { int h=y; y=-x; x=h; }
void T2DGridPoint::MirrorInX( void ) { y = -y; }
void T2DGridPoint::MirrorInY( void ) { x = -x; }

const T2DGridPoint Origin2D( 0, 0 );
const T2DGridPoint Max2D( INT_MAX, INT_MAX );










// ==========================================================================
//
// class T3DGridPoint
//
// ==========================================================================


// --------------------------------------------------------------------------
//
// constructors
//
// --------------------------------------------------------------------------

T3DGridPoint::T3DGridPoint( void )
{
	// this constructor will give you random data in the member variables !!!
}

T3DGridPoint::T3DGridPoint( const T3DGridPoint &rhs )
{
	 x = rhs.x;
	 y = rhs.y;
	 z = rhs.z;
}

T3DGridPoint::T3DGridPoint( int _x, int _y, int _z )
{
	 x = _x;
	 y = _y;
	 z = _z;
}


// --------------------------------------------------------------------------
//
// comparison operators
//
// --------------------------------------------------------------------------

bool T3DGridPoint::operator == ( const T3DGridPoint& rhs ) const
{
	 return (x == rhs.x) && (y == rhs.y) && (z==rhs.z);
}

bool T3DGridPoint::operator != ( const T3DGridPoint& rhs ) const
{
	 return (x!=rhs.x) || (y!=rhs.y) || (z!=rhs.z);
}

bool T3DGridPoint::operator < ( const T3DGridPoint& rhs ) const
{
	if ( z < rhs.z ) return true;
	if ( z > rhs.z ) return false;
	if ( y < rhs.y ) return true;
	if ( y > rhs.y ) return false;
	if ( x < rhs.x ) return true;
	return false;
}

bool T3DGridPoint::operator > ( const T3DGridPoint& rhs ) const
{
	if ( z > rhs.z ) return true;
	if ( z < rhs.z ) return false;
	if ( y > rhs.y ) return true;
	if ( y < rhs.y ) return false;
	if ( x > rhs.x ) return true;
	return false;
}




// --------------------------------------------------------------------------
//
// binary operators with assignment
//
// --------------------------------------------------------------------------


T3DGridPoint T3DGridPoint::operator + ( const T3DGridPoint& rhs) const
{
	 return T3DGridPoint( x+rhs.x, y+rhs.y, z+rhs.z );
}

T3DGridPoint T3DGridPoint::operator - ( const T3DGridPoint& rhs) const
{
	 return T3DGridPoint( x-rhs.x, y-rhs.y, z-rhs.z );
}



// --------------------------------------------------------------------------
//
// binary operators without assignment
//
// --------------------------------------------------------------------------

void T3DGridPoint::operator += ( const T3DGridPoint& rhs )
{
	 x += rhs.x;
	 y += rhs.y;
	 z += rhs.z;
}

void T3DGridPoint::operator -= ( const T3DGridPoint& rhs)
{
	 x -= rhs.x;
	 y -= rhs.y;
	 z -= rhs.z;
}


// --------------------------------------------------------------------------
//
// utility functions
//
// --------------------------------------------------------------------------

bool T3DGridPoint::IsZero() const
{
	 return (x==0) && (y==0) && (z==0);
}


void T3DGridPoint::Translate( int dx, int dy, int dz )
{
	 x += dx;
	 y += dy;
	 z += dz;
}

void T3DGridPoint::Translate( const T3DGridPoint &rhs )
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

void T3DGridPoint::Set( int new_x, int new_y, int new_z )
{
	 x = new_x;
	 y = new_y;
	 z = new_z;
}




// --------------------------------------------------------------------------
//
// member varaible access functions
//
// --------------------------------------------------------------------------

const int T3DGridPoint::getX( void ) const
{
	return x;
}

const int T3DGridPoint::getY( void ) const
{
	return y;
}

const int T3DGridPoint::getZ( void ) const
{
	return z;
}


// --------------------------------------------------------------------------
//
// rotation and mirroring functions
//
// --------------------------------------------------------------------------

void T3DGridPoint::RotateAroundX90( void ) { int h=y; y=-z; z=h; }
void T3DGridPoint::RotateAroundX180( void ) { y=-y; z=-z; }
void T3DGridPoint::RotateAroundX270( void ) { int h=z; z=-y; y=h; }
void T3DGridPoint::RotateAroundY90( void ) { int h=z; z=-x; x=h; }
void T3DGridPoint::RotateAroundY180( void ) { z=-z; x=-x; }
void T3DGridPoint::RotateAroundY270( void ) { int h=x; x=-z; z=h; }
void T3DGridPoint::RotateAroundZ90( void ) { int h=x; x=-y; y=h; }
void T3DGridPoint::RotateAroundZ180( void ) { x=-x; y=-y; }
void T3DGridPoint::RotateAroundZ270( void ) { int h=y; y=-x; x=h; }
void T3DGridPoint::MirrorInXY( void ) { z = -z; }
void T3DGridPoint::MirrorInYZ( void ) { x = -x; }
void T3DGridPoint::MirrorInZX( void ) { y = -y; }


const T3DGridPoint Origin3D( 0, 0, 0 );
const T3DGridPoint Max3D( INT_MAX, INT_MAX, INT_MAX );

