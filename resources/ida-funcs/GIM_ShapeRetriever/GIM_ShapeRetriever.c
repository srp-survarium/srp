GIM_ShapeRetriever *__userpurge GIM_ShapeRetriever::GIM_ShapeRetriever@<eax>(
        GIM_ShapeRetriever *this@<ecx>,
        GIM_ShapeRetriever *a2@<edi>,
        btGImpactShapeInterface *gim_shape)
{
  btPolyhedralConvexAabbCachingShape *v3; // ecx
  btPolyhedralConvexAabbCachingShape *v4; // eax
  bool v5; // zf
  GIM_ShapeRetriever::TetraShapeRetriever *p_m_tetra_retriever; // eax

  btTriangleShapeEx::btTriangleShapeEx((btTriangleShapeEx *)this, &a2->m_trishape);
  v4 = btPolyhedralConvexAabbCachingShape::btPolyhedralConvexAabbCachingShape(v3, &a2->m_tetrashape);
  v4->m_shapeType = 2;
  v4->__vftable = (btPolyhedralConvexAabbCachingShape_vtbl *)&btTetrahedronShapeEx::`vftable';
  v4[1].__vftable = (btPolyhedralConvexAabbCachingShape_vtbl *)4;
  a2->m_child_retriever.__vftable = (GIM_ShapeRetriever::ChildShapeRetriever_vtbl *)&GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  a2->m_tri_retriever.__vftable = (GIM_ShapeRetriever::TriangleShapeRetriever_vtbl *)&GIM_ShapeRetriever::TriangleShapeRetriever::`vftable';
  a2->m_tetra_retriever.__vftable = (GIM_ShapeRetriever::TetraShapeRetriever_vtbl *)&GIM_ShapeRetriever::TetraShapeRetriever::`vftable';
  a2->m_gim_shape = gim_shape;
  if ( gim_shape->needsRetrieveTriangles(gim_shape) )
  {
    a2->m_current_retriever = &a2->m_tri_retriever;
  }
  else
  {
    v5 = !a2->m_gim_shape->needsRetrieveTetrahedrons(a2->m_gim_shape);
    p_m_tetra_retriever = &a2->m_tetra_retriever;
    if ( v5 )
      p_m_tetra_retriever = (GIM_ShapeRetriever::TetraShapeRetriever *)&a2->m_child_retriever;
    a2->m_current_retriever = p_m_tetra_retriever;
  }
  a2->m_current_retriever->m_parent = a2;
  return a2;
}
