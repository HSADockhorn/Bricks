//
//  Pentomino3D.cpp
//  Pentomino 3x4x5
//
//  Created by Hans Dockhorn on 05/03/2023.
//

#include "Pentomino3D.hpp"

// --------------------------------------------------------------------------
//
// Labeling of grid points in the Z=0 plane. Labels in lowercase are not used
// and not defined.
//
// +--+--+--+--+--+  -->
// |  |ge|  |  |  |   Y
// +--+--+--+--+--+
// |  |gf|gl|  |  |
// +--+--+--+--+--+
// |  |GG|GM|gq|  |
// +--+--+--+--+--+
// |><|GH|GN|gr|gt|
// +--+--+--+--+--+
// |GA|GI|GO|gs|  |
// +--+--+--+--+--+
// |GB|GJ|gp|  |  |
// +--+--+--+--+--+
// |GC|gk|  |  |  |
// +--+--+--+--+--+
// |GD|  |  |  |  |
// +--+--+--+--+--+
//
// |
// | X
// V
//
// --------------------------------------------------------------------------

T3DGridPoint GA(1,0,0);
T3DGridPoint GB(2,0,0);
T3DGridPoint GC(3,0,0);
T3DGridPoint GD(4,0,0);

T3DGridPoint GG(-1,1,0);
T3DGridPoint GH(0,1,0);
T3DGridPoint GI(1,1,0);
T3DGridPoint GJ(2,1,0);

T3DGridPoint GM(-1,2,0);
T3DGridPoint GN(0,2,0);
T3DGridPoint GO(1,2,0);


// --------------------------------------------------------------------------
//
// Definitions of the pieces in terms of T3DGridPoint arrays
//
// --------------------------------------------------------------------------

T3DGridPoint F[4] = { GA, GG, GH, GN };
T3DGridPoint I[4] = { GA, GB, GC, GD };
T3DGridPoint L[4] = { GA, GB, GC, GH };
T3DGridPoint N[4] = { GA, GB, GG, GH };
T3DGridPoint P[4] = { GA, GB, GH, GI };
T3DGridPoint T[4] = { GA, GB, GI, GO };
T3DGridPoint U[4] = { GA, GB, GH, GJ };
T3DGridPoint V[4] = { GA, GB, GH, GN };
T3DGridPoint W[4] = { GA, GG, GH, GM };
T3DGridPoint X[4] = { GG, GH, GI, GN };
T3DGridPoint Y[4] = { GA, GB, GC, GI };
T3DGridPoint Z[4] = { GA, GH, GM, GN };









// --------------------------------------------------------------------------
//
// class TManifestation member functions
//
// --------------------------------------------------------------------------

TManifestation::TManifestation( TManifestation* rhs )
{
	for ( int p=0; p<4; p++ ) GridPoints[p] = rhs->GridPoints[p];
}


TManifestation::TManifestation( T3DGridPoint grid_points[4] )
{
	for ( int pi=0; pi<4; pi++ )
	{
		GridPoints[pi] = grid_points[pi];
	}
	Normalise();
};

bool TManifestation::operator == ( const TManifestation& manifestation ) const
{
	for ( int pi=0; pi<4; pi++ )
	{
		if ( GridPoints[pi] != manifestation.GridPoints[pi] ) return false;
	}
	return true;
}

bool TManifestation::operator != ( const TManifestation& manifestation ) const
{
	for ( int pi=0; pi<4; pi++ )
	{
		if ( GridPoints[pi] != manifestation.GridPoints[pi] ) return true;
	}
	return false;
}


const T3DGridPoint& TManifestation::getPoint( int point_number ) const
{
	return GridPoints[point_number];
}


void TManifestation::Normalise( void )
{
	// Determine the 'smallest' point according to the scanning order.
	int indexToSmallestPoint = -1;
	T3DGridPoint smallestPoint = Origin3D;
	for ( int pi=0; pi<4; pi++ )
	{
		if ( GridPoints[pi] < smallestPoint )
		{
			indexToSmallestPoint = pi;
			smallestPoint = GridPoints[pi];
		}
	}
	
	// Adjust the points so that the 'smallest' point is moved to the origin.
	if ( indexToSmallestPoint != -1 )
	{
		for ( int pi=0; pi<4; pi++ )
		{
			if ( pi != indexToSmallestPoint)
			{
				GridPoints[pi] -= smallestPoint;
			}
		}
		GridPoints[indexToSmallestPoint] = Origin3D - smallestPoint;
	}

	// Sort the points in ascending order
	for ( int pi=3; pi>0; pi-- )
	{
		for ( int pj=0; pj<pi; pj++ )
		{
			if ( GridPoints[pj+1] < GridPoints[pj] )
			{
				T3DGridPoint h = GridPoints[pj+1];
				GridPoints[pj+1] = GridPoints[pj];
				GridPoints[pj] = h;
			}
		}
	}
}

void TManifestation::RotateAroundX90( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundX90();
	Normalise();
}

void TManifestation::RotateAroundX180( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundX180();
	Normalise();
}

void TManifestation::RotateAroundX270( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundX270();
	Normalise();
}


void TManifestation::RotateAroundY90( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundY90();
	Normalise();
}

void TManifestation::RotateAroundY180( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundY90();
	Normalise();
}

void TManifestation::RotateAroundY270( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundY90();
	Normalise();
}

void TManifestation::RotateAroundZ90( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundZ90();
	Normalise();
}

void TManifestation::RotateAroundZ180( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundZ90();
	Normalise();
}

void TManifestation::RotateAroundZ270( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].RotateAroundZ90();
	Normalise();
}


void TManifestation::MirrorInXY( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].MirrorInXY();
	Normalise();
}
	
void TManifestation::MirrorInYZ( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].MirrorInYZ();
	Normalise();
}
	
	
void TManifestation::MirrorInZX( void )
{
	for ( int i=0; i<4; i++ ) GridPoints[i].MirrorInZX();
	Normalise();
}





// --------------------------------------------------------------------------
//
// class T3DPiece member functions
//
// --------------------------------------------------------------------------

T3DPiece::T3DPiece( T3DGridPoint grid_points[4] )
{
	// reserve space for candidate manifestations
	TManifestation* candidateManifestations[24];
	for ( int cm=0; cm<24; cm++ ) candidateManifestations[cm] = nullptr;
	
	// create a master manifestation from the grid points
	TManifestation* Master = new TManifestation( grid_points );

	// group 0: candidate manifestations 0-3 (in the XY plane)
	candidateManifestations[0] = new TManifestation( Master );
	Master->MirrorInYZ();
	candidateManifestations[1] = new TManifestation( Master );
	Master->MirrorInZX();
	candidateManifestations[2] = new TManifestation( Master );
	Master->MirrorInYZ();
	candidateManifestations[3] = new TManifestation( Master );
	Master->MirrorInZX();

	//group 1: candidate manifestations 4-7 (still in the XY plane)
	Master->RotateAroundZ90();
	candidateManifestations[4] = new TManifestation( Master );
	Master->MirrorInYZ();
	candidateManifestations[5] = new TManifestation( Master );
	Master->MirrorInZX();
	candidateManifestations[6] = new TManifestation( Master );
	Master->MirrorInYZ();
	candidateManifestations[7] = new TManifestation( Master );
	Master->MirrorInZX();
	Master->RotateAroundZ270();
	
	// group 2: candidate manifestations 8-11 (in the ZX plane)
	Master->RotateAroundX90();
	candidateManifestations[8] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[9] = new TManifestation( Master );
	Master->MirrorInYZ();
	candidateManifestations[10] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[11] = new TManifestation( Master );
	Master->MirrorInYZ();
	
	// group 3: candidate manifestations 12-15 (still in the ZX plane)
	Master->RotateAroundY90();
	candidateManifestations[12] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[13] = new TManifestation( Master );
	Master->MirrorInYZ();
	candidateManifestations[14] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[15] = new TManifestation( Master );
	Master->MirrorInYZ();
	Master->RotateAroundY270();
	Master->RotateAroundX270();
	
	// group 4: candidate manifestations 16-19 (in the YZ plane)
	Master->RotateAroundY90();
	candidateManifestations[16] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[17] = new TManifestation( Master );
	Master->MirrorInZX();
	candidateManifestations[18] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[19] = new TManifestation( Master );
	Master->MirrorInZX();
	
	// group 5: candidate manifestations 20-23 (still in the YZ plane)
	Master->RotateAroundX90();
	candidateManifestations[20] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[21] = new TManifestation( Master );
	Master->MirrorInZX();
	candidateManifestations[22] = new TManifestation( Master );
	Master->MirrorInXY();
	candidateManifestations[23] = new TManifestation( Master );
	Master->MirrorInZX();
	Master->RotateAroundX270();
	Master->RotateAroundY270();

	
	ManifestationCount = 0;
	GroupCount = 0;
	GroupSize = 0;
	
	for ( int g=0; g<6; g++ )
	{
		int NewManifestationsInThisGroup = 0;
		for ( int m=0; m<4; m++ )
		{
			bool ManifestationIsNew = true;
			for ( int cmj = 0; cmj<ManifestationCount; cmj++ )
			{
				if ( *candidateManifestations[4*g+m] == *Manifestations[cmj] )
				{
					ManifestationIsNew = false;
					break;
				}
			}
			if ( ManifestationIsNew )
			{
				Manifestations[ManifestationCount++] = new TManifestation( candidateManifestations[4*g+m] );
				NewManifestationsInThisGroup++;
			}
		}
		if ( NewManifestationsInThisGroup > 0 )
		{
			GroupSize = NewManifestationsInThisGroup;
			GroupCount++;
		}
	}
	
	for ( int cmi=0; cmi<24; cmi++ )
	{
		bool ManifestationIsNew = true;
		for ( int cmj=0; cmj<ManifestationCount; cmj++ )
		{
			if ( *candidateManifestations[cmi] == *Manifestations[cmj] )
			{
				ManifestationIsNew = false;
				break;
			}
		}
		if ( ManifestationIsNew )
		{
			Manifestations[ManifestationCount++] = new TManifestation( candidateManifestations[cmi] );
		}
	}
			
	for ( int cm=0; cm<24; cm++ )
	{
		delete candidateManifestations[cm];
		candidateManifestations[cm] = nullptr;
	}
}


T3DPiece::~T3DPiece( void )
{
	for ( int m=0; m<24; m++ )
	{
		if ( Manifestations[m] != nullptr )
		{
			delete Manifestations[m];
			Manifestations[m] = nullptr;
		}
	}
}

const int T3DPiece::getManifestationCount( void ) const
{
	return ManifestationCount;
}


const int T3DPiece::getGroupSize( void ) const
{
	return GroupSize;
}


const int T3DPiece::getGroupCount( void ) const
{
	return GroupCount;
}


const TManifestation* T3DPiece::getManifestation( int manifestation_number ) const
{
	return Manifestations[manifestation_number];
}









// --------------------------------------------------------------------------
//
// class T3DPentominoSet member functions
//
// --------------------------------------------------------------------------

T3DPentominoSet::T3DPentominoSet( void )
{
	Pieces[0] = new T3DPiece(F);
	Pieces[1] = new T3DPiece(I);
	Pieces[2] = new T3DPiece(L);
	Pieces[3] = new T3DPiece(N);
	Pieces[4] = new T3DPiece(P);
	Pieces[5] = new T3DPiece(T);
	Pieces[6] = new T3DPiece(U);
	Pieces[7] = new T3DPiece(V);
	Pieces[8] = new T3DPiece(W);
	Pieces[9] = new T3DPiece(X);
	Pieces[10] = new T3DPiece(Y);
	Pieces[11] = new T3DPiece(Z);
}


T3DPentominoSet::~T3DPentominoSet( void )
{
	for ( int p=0; p<12; p++ )
	{
		if ( Pieces[p] != nullptr )
		{
			delete Pieces[p];
			Pieces[p] = nullptr;
		}
	}
}


const T3DPiece* T3DPentominoSet::getPiece( int piece_number ) const
{
	return Pieces[piece_number];
}
