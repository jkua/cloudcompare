//##########################################################################
//#                                                                        #
//#                               CCLIB                                    #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU Library General Public License as       #
//#  published by the Free Software Foundation; version 2 of the License.  #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef SIMPLE_MESH_HEADER
#define SIMPLE_MESH_HEADER

#include "GenericIndexedMesh.h"
#include "GenericChunkedArray.h"
#include "SimpleTriangle.h"

namespace CCLib
{

class GenericIndexedCloud;

//! A simple mesh structure, with index-based vertex access
/** Implements the GenericIndexedMesh interface. This mesh is always associated
	to a (index based) point cloud that stores the mesh vertexes.
**/
#ifdef CC_USE_AS_DLL
#include "CloudCompareDll.h"

class CC_DLL_API SimpleMesh : virtual public GenericIndexedMesh
#else
class SimpleMesh : virtual public GenericIndexedMesh
#endif
{
public:

	//! SimpleMesh Constructor
	/** \param _theVertices the point cloud containing the vertices
		\param linkVerticesWithMesh specifies if the vertex cloud should be deleted when the SimpleMesh object is destructed
	**/
	SimpleMesh(GenericIndexedCloud* _theVertices, bool linkVerticesWithMesh=false);

	//! SimpleMesh destructor
	virtual ~SimpleMesh();

	//inherited methods
	virtual void forEach(genericTriangleAction& anAction);
	virtual void placeIteratorAtBegining();
	virtual GenericTriangle* _getNextTriangle(); //temporary
	virtual GenericTriangle* _getTriangle(unsigned triangleIndex); //temporary
	virtual TriangleSummitsIndexes* getNextTriangleIndexes();
	virtual TriangleSummitsIndexes* getTriangleIndexes(unsigned triangleIndex);
	virtual unsigned size() const;
	virtual void getBoundingBox(PointCoordinateType Mins[], PointCoordinateType Maxs[]);
	virtual void getTriangleSummits(unsigned triangleIndex, CCVector3& A, CCVector3& B, CCVector3& C);

	//specific methods

	//! Adds a triangle to the mesh
	/** \param i1 first summit index (relatively to the vertex cloud)
		\param i2 second summit index (relatively to the vertex cloud)
		\param i3 third summit index (relatively to the vertex cloud)
	**/
	virtual void addTriangle(unsigned i1, unsigned i2, unsigned i3);

	//! Reserves the memory to store the triangles (as 3 indexes each)
	/** \param n the number of triangles to reserve
		\return true if the method succeeds, false otherwise
	**/
	virtual bool reserve(unsigned n);

	//! Resizes the mesh database
	/** If the new number of elements is smaller than the actual size,
		the overflooding elements will be deleted.
		\param n the new number of triangles
		\return true if the method succeeds, false otherwise
	**/
	virtual bool resize(unsigned n);

protected:

    //! Updates bounding-box with a 3D point
	virtual void updateBBWithPoint(const CCVector3* P);

	//! A triangle vertices indexes container
	typedef GenericChunkedArray<3,unsigned> TriangleIndexesContainer;
	//! The triangles indexes
	TriangleIndexesContainer* m_triIndexes;

	//! Iterator on the list of triangle summits indexes
	unsigned globalIterator;
	//! Dump triangle structure to transmit temporary data
	SimpleTriangle dummyTriangle;

	//! The associated point cloud (vertexes)
	GenericIndexedCloud* theVertices;
	//! Specifies if the associated cloud should be deleted when the mesh is deleted
	bool verticesLinked;

	//! Bounding-box min corner
    CCVector3 bbMin;
	//! Bounding-box min corner
    CCVector3 bbMax;
    //! Bounding-box validity
    bool bbIsValid;
};

}

#endif //SIMPLE_MESH_HEADER
