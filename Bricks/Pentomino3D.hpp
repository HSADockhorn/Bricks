//
//  Pentomino3D.hpp
//  Pentomino 3x4x5
//
//  Created by Hans Dockhorn on 05/03/2023.
//

#ifndef Pentomino3D_hpp
#define Pentomino3D_hpp

#include "GridPoint.hpp"






class TManifestation
{
private:
	T3DGridPoint GridPoints[4];
	void Normalise( void );
    
public:
   TManifestation( T3DGridPoint grid_points[4] );
	TManifestation( TManifestation* rhs );

	bool operator == ( const TManifestation& manifestation ) const;
	bool operator != ( const TManifestation& manifestation ) const;

	const T3DGridPoint& getPoint( int point_index ) const;
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




class T3DPiece
{
private:
   TManifestation* Manifestations[24];
   int ManifestationCount;
	int GroupSize;
	int GroupCount;
    
public:
	T3DPiece( T3DGridPoint grid_points[4] );
	~T3DPiece( void );
	
   const int getManifestationCount( void ) const;
	const int getGroupSize( void ) const;
	const int getGroupCount( void ) const;
	const TManifestation* getManifestation( int manifestation_number ) const;
};



class T3DPentominoSet
{
private:
	T3DPiece* Pieces[12];
        
public:
	T3DPentominoSet( void );
	~T3DPentominoSet( void );

	const T3DPiece* getPiece( int piece_number ) const;
};




#endif /* Pentomino3D_hpp */
