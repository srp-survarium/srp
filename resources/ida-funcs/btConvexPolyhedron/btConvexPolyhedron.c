btConvexPolyhedron *__usercall btConvexPolyhedron::btConvexPolyhedron@<eax>(
        btConvexPolyhedron *this@<ecx>,
        btConvexPolyhedron *result@<eax>)
{
  result->__vftable = (btConvexPolyhedron_vtbl *)&btConvexPolyhedron::`vftable';
  result->m_vertices.m_data = 0;
  result->m_vertices.m_size = 0;
  result->m_vertices.m_capacity = 0;
  result->m_vertices.m_ownsMemory = 1;
  result->m_faces.m_ownsMemory = 1;
  result->m_faces.m_data = 0;
  result->m_faces.m_size = 0;
  result->m_faces.m_capacity = 0;
  result->m_uniqueEdges.m_ownsMemory = 1;
  result->m_uniqueEdges.m_data = 0;
  result->m_uniqueEdges.m_size = 0;
  result->m_uniqueEdges.m_capacity = 0;
  return result;
}
