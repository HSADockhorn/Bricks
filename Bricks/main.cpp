//
//  main.cpp
//  Pentomino 3x4x5
//
//  Created by Hans Dockhorn on 25/02/2023.
//

#include <iostream>

#include "GridPoint.hpp"
#include "Pentomino3D.hpp"

// names and symbols



#define XSIZE	3
#define YSIZE	4
#define ZSIZE	5

#define XMAX 	2
#define YMAX	3
#define ZMAX	4


int Box[XSIZE][YSIZE][ZSIZE];
int solutionCount;
bool pieceUsed[12];


char Letters[12] = { 'F', 'I', 'L', 'N', 'P', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int pieceUsedOnLevel[12];
int manifestationUsedOnLevel[12];
int manifestationGroupUsedForPiece[12];

T3DPentominoSet*	theSet = nullptr;




void fit_piece( int level, int lx, int ly, int lz )
{
	// primality check
	
	//	case 1: mirroring in plane x=XMID
	bool isFinished = false;
	for ( int z=0; z<5; z++ )
	{
		for ( int y=0; y<4; y++ )
		{
			int scanValue = Box[0][y][z];
			if ( scanValue == -1 ) { isFinished = true; break; }
			int mirrorValue = Box[2][y][z];
			if ( mirrorValue == -1 ) {	isFinished = true; break; }
			if ( scanValue > mirrorValue ) return;
			if ( scanValue < mirrorValue ) { isFinished = true; break; }
		}
		if ( isFinished ) break;
	}

	// case 2: mirroring in plane y=yMID
	isFinished = false;
	for ( int z=0; z<5; z++ )
	{
		for ( int y=0; y<2; y++ )
		{
			for ( int x=0; x<3; x++ )
			{
				int scanValue = Box[x][y][z];
				if ( scanValue == -1 ) { isFinished = true;	break; }
				int mirrorValue = Box[x][3-y][z];
				if ( mirrorValue == -1 ) { isFinished = true; break; }
				if ( scanValue > mirrorValue ) return;
				if ( scanValue < mirrorValue ) { isFinished = true; break; }
			}
			if ( isFinished ) break;
		}
		if ( isFinished ) break;
	}

	// case 3: mirroring in plane z=zMID
	isFinished = false;
	for ( int z=0; z<2; z++ )
	{
		for ( int y=0; y<4; y++ )
		{
			for ( int x=0; x<3; x++ )
			{
				int scanValue = Box[x][y][z];
				if ( scanValue == -1 ) { isFinished = true; break; }
				int mirrorValue = Box[x][y][4-z];
				if ( mirrorValue == -1 ) {	isFinished = true; break; }
				if ( scanValue > mirrorValue ) return;
				if ( scanValue < mirrorValue ) { isFinished = true; break; }
			}
			if ( isFinished ) break;
		}
		if ( isFinished ) break;
	}

	//	case 4: mirroring in line y=YMID, z=ZMID
	isFinished = false;
	for ( int z=0; z<3; z++ )
	{
		for ( int y=0; y<((z<2)?4:2); y++ )
		{
			for ( int x=0; x<3; x++ )
			{
				int scanValue = Box[x][y][z];
				if ( scanValue == -1 ) { isFinished = true; break; }
				int mirrorValue = Box[x][3-y][4-z];
				if ( mirrorValue == -1 ) { isFinished = true; break; }
				if ( scanValue > mirrorValue ) return;
				if ( scanValue < mirrorValue ) { isFinished = true; break; }
			}
			if ( isFinished ) break;
		}
		if ( isFinished ) break;
	}

	//	case 5: mirroring in line x=xMID, z=ZMID
	isFinished = false;
	for ( int z=0; z<3; z++ )
	{
		for ( int y=0; y<4; y++ )
		{
			for ( int x=0; x< ((z<2)?1:3); x++ )
			{
				int scanValue = Box[x][y][z];
				if ( scanValue == -1 ) { isFinished = true; break; }
				int mirrorValue = Box[2-x][y][4-z];
				if ( mirrorValue == -1 ) { isFinished = true; break; }
				if ( scanValue > mirrorValue ) return;
				if ( scanValue < mirrorValue ) { isFinished = true; break; }
			}
			if ( isFinished ) break;
		}
		if ( isFinished ) break;
	}

	//	case 6: mirroring in line x=XMID, y=YMID
	isFinished = false;
	for ( int z=0; z<5; z++ )
	{
		for ( int y=0; y<2; y++ )
		{
			for ( int x=0; x<3; x++ )
			{
				int scanValue = Box[x][y][z];
				if ( scanValue == -1 ) { isFinished = true; break; }
				int mirrorValue = Box[2-x][3-y][z];
				if ( mirrorValue == -1 ) { isFinished = true; break; }
				if ( scanValue > mirrorValue ) return;
				if ( scanValue < mirrorValue ) { isFinished = true; break; }
			}
			if ( isFinished ) break;
		}
		if ( isFinished ) break;
	}

	//	case 7: mirroring in line x=XMID, y=YMID and z=ZMID
	isFinished = false;
	for ( int z=0; z<3; z++ )
	{
		for ( int y=0; y<((z<2)?4:2); y++ )
		{
			for ( int x=0; x<3; x++ )
			{
				int scanValue = Box[x][y][z];
				if ( scanValue == -1 ) { isFinished = true; break; }
				int mirrorValue = Box[2-x][3-y][4-z];
				if ( mirrorValue == -1 ) { isFinished = true; break; }
				if ( scanValue > mirrorValue ) return;
				if ( scanValue < mirrorValue ) { isFinished = true; break; }
			}
			if ( isFinished ) break;
		}
		if ( isFinished ) break;
	}

	// level check
	if ( level == 12 )
	{
		// increment overall solution counter
		solutionCount++;

		// print parts list
		for ( int p=0; p<12; p++ )
		{
			std::cout << Letters[p] << manifestationGroupUsedForPiece[p];
		}
		std::cout << ';';

		// print solution in coded form
		for ( int l=0; l<12; l++)
		{
			std::cout << Letters[pieceUsedOnLevel[l]] << manifestationUsedOnLevel[l];
 		}
		std::cout << ';';

		// print solution in readable format
		for ( int x=0; x<3; x++ )
		{
			for ( int y=0; y<4; y++ )
			{
				for ( int z=0; z<5; z++ )
				{
					std::cout << Letters[Box[x][y][z]];
				}
				if (y<3) std::cout << ' ';
			}
			if (x<2) std::cout << '|';
		}
		std::cout << std::endl;

		// done here
		return;
	}
	
	// no solution: just adding another piece
	// determine the 'lead'
	while ( Box[lx][ly][lz] != -1 )
	{
		if (++lx==XSIZE) { lx=0; if (++ly==YSIZE) { ly=0; ++lz; } }
	}
	T3DGridPoint Lead( lx, ly, lz);
	
	// loop over the pieces
	for ( int p=0; p<12; p++ )
	{
		// skip if the piece has already been used
		if ( pieceUsed[p] ) continue;
		
		// Mark piece 'p' as used and get a reference to its definition
		pieceUsedOnLevel[level] = p;
		Box[lx][ly][lz] = p;
		pieceUsed[p] = true;
		const T3DPiece* thePiece = theSet->getPiece(p);
		
		// loop over manifestations
		int M = thePiece->getManifestationCount();
		for ( int m=0; m<M; m++ )
		{
			// get reference to the manifestation
			const TManifestation* theManifestation = thePiece->getManifestation(m);
	
			// 1. range check for all points in the manifestation
			bool inRange = true;
			for ( int pt=0; pt<4; pt++ )
			{
				const T3DGridPoint& thePoint = theManifestation->getPoint( pt );
				int x = lx + thePoint.getX();
				int y = ly + thePoint.getY();
				int z = lz + thePoint.getZ();

				if ( (x<0) || (x>XMAX) || (y<0) || (y>YMAX) || (z<0) || (z>ZMAX) ) { inRange = false; break; }
			}
			if ( !inRange ) continue;
			
			// 2. freedom check for all points of the manifestation
			bool isFree = true;
			for ( int pt=0; pt<4; pt++ )
			{
				const T3DGridPoint& thePoint = theManifestation->getPoint( pt );
				int x = lx + thePoint.getX();
				int y = ly + thePoint.getY();
				int z = lz + thePoint.getZ();

				if ( Box[x][y][z] != -1 ) { isFree = false; break; }
			}
			if ( !isFree ) continue;
	
			// at this point we are sure that the manifestation meets all the requirements
			// so put it into the box and update administration
			manifestationUsedOnLevel[level] = m;
			manifestationGroupUsedForPiece[p] = m/thePiece->getGroupSize();

			for ( int pt=0; pt<4; pt++ )
			{
				const T3DGridPoint& thePoint = theManifestation->getPoint( pt );
				int x = lx + thePoint.getX();
				int y = ly + thePoint.getY();
				int z = lz + thePoint.getZ();
				Box[x][y][z] = p;
			}
			
			fit_piece( level+1, lx, ly, lz );

			for ( int pt=0; pt<4; pt++ )
			{
				const T3DGridPoint& thePoint = theManifestation->getPoint( pt );
				int x = lx + thePoint.getX();
				int y = ly + thePoint.getY();
				int z = lz + thePoint.getZ();
				Box[x][y][z] = -1;
			}
		}
		// end manifestation loop
	
		// release piece
		pieceUsed[p] = false;
		
		// unblock the lead
		Box[lx][ly][lz] = -1;
	}
}




int main(int argc, const char * argv[])
{
	// create a set of 3D pentominoes
	theSet = new T3DPentominoSet();
	
	// clear the box
	for ( int x=0; x<XSIZE; x++ )
	{
		for ( int y=0; y<YSIZE; y++ )
		{
			for ( int z=0; z<ZSIZE; z++ )
			{
				Box[x][y][z] = -1;
			}
		}
	}
	
	// no solutions found yet
	solutionCount = 0;

	// no pieces in use yet
	for ( int p=0; p<12; p++ ) pieceUsed[p] = false;
	
	fit_piece (0, 0, 0, 0 );
	
	// announce overall result
	std::cout << "A grand total of " << solutionCount<<  " solutions was found." << std::endl;
	
	// clean up the set of 3D pentominoes
	delete theSet;
	theSet = nullptr;
	
	// all well that ends well
	return 0;
}


