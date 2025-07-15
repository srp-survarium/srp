btTriangleShape *__userpurge btTriangleShape::btTriangleShape@<eax>(
        btTriangleShape *this@<ecx>,
        btConvexInternalShape *a2@<eax>,
        const btVector3 *p0,
        const btVector3 *p1,
        const btVector3 *p2)
{
  btTriangleShape *result; // eax
  btVector3 *v6; // ecx

  result = (btTriangleShape *)btConvexInternalShape::btConvexInternalShape(this, a2);
  result->m_polyhedron = 0;
  result->__vftable = (btTriangleShape_vtbl *)&btTriangleShape::`vftable';
  result->m_shapeType = 1;
  result->m_vertices1[0] = (btVector3)v6->mVec128;
  result->m_vertices1[1] = (btVector3)p0->mVec128;
  result->m_vertices1[2] = (btVector3)p1->mVec128;
  return result;
}
