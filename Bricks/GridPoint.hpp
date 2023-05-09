//
//  GridPoint.hpp
//  Pentomino 3x4x5
//
//  Created by Hans Dockhorn on 19/03/2023.
//

#ifndef GridPoint_hpp
#define GridPoint_hpp


class T2DGridPoint
{
private:
	int x, y;
	
public:
	
	// constructors
	T2DGridPoint( void );
	T2DGridPoint( const T2DGridPoint &rhs );
	T2DGridPoint( int _x, int _y );
	
	// comparison operators
	bool operator == ( const T2DGridPoint& rhs ) const;
	bool operator != ( const T2DGridPoint& rhs ) const;
	bool operator < ( const T2DGridPoint& rhs ) const;
	
	// binary operators with assignment
	T2DGridPoint operator + ( const T2DGridPoint& rhs ) const;
	T2DGridPoint operator - ( const T2DGridPoint& rhs ) const;
	
	// binary operators without assignment
	void operator += ( const T2DGridPoint& rhs );
	void operator -= ( const T2DGridPoint& rhs );
	
	// utilities
	bool IsZero( void ) const;
	void Translate( int dx, int dy );
	void Translate( const T2DGridPoint& rhs );
	void Set( int new_x, int new_y );
	
	// member access
	const int getX( void ) const;
	const int getY( void ) const;
	
	// rotation and mirroring
	void Rotate90( void );
	void Rotate180( void );
	void Rotate270( void );
	void MirrorInX( void );
	void MirrorInY( void );
};

extern const T2DGridPoint Origin2D;
extern const T2DGridPoint Max2D;

class T3DGridPoint
{
private:
	int x, y, z;
	 
public:
	
	// constructors
	T3DGridPoint( void );
	T3DGridPoint( const T3DGridPoint &rhs );
	T3DGridPoint( int _x, int _y, int _z );
	
	// comparison operators
	bool operator == ( const T3DGridPoint& rhs ) const;
	bool operator != ( const T3DGridPoint& rhs ) const;
	bool operator < ( const T3DGridPoint& rhs ) const;
	bool operator > ( const T3DGridPoint& rhs ) const;


	// binary operators with assignment
	T3DGridPoint operator + ( const T3DGridPoint& rhs ) const;
	T3DGridPoint operator - ( const T3DGridPoint& rhs ) const;
	
	// binary operators without assignment
	void operator += ( const T3DGridPoint& rhs );
	void operator -= ( const T3DGridPoint& rhs );
	
	// utilities
	bool IsZero( void ) const;
	void Translate( int dx, int dy, int dz );
	void Translate( const T3DGridPoint& rhs );
	void Set( int new_x, int new_y, int new_z );

	// member access
	const int getX( void ) const;
	const int getY( void ) const;
	const int getZ( void ) const;
	
	// rotation and mirroring
	void RotateAroundX90( void );
	void RotateAroundX180( void );
	void RotateAroundX270( void );
	void RotateAroundY90( void );
	void RotateAroundY180( void );
	void RotateAroundY270( void );
	void RotateAroundZ90( void );
	void RotateAroundZ180( void );
	void RotateAroundZ270( void );
	void MirrorInXY( void );
	void MirrorInYZ( void );
	void MirrorInZX( void );
};

extern const T3DGridPoint Origin3D;
extern const T3DGridPoint Max3D;


#endif /* GridPoint_hpp */
