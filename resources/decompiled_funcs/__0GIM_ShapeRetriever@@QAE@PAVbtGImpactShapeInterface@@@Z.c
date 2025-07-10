GIM_ShapeRetriever *__userpurge GIM_ShapeRetriever::GIM_ShapeRetriever@<eax>(
        GIM_ShapeRetriever *this@<ecx>,
        GIM_ShapeRetriever *a2@<esi>,
        btGImpactShapeInterface *gim_shape)
{
  const vostok::math::float4x4 *v3; // xmm0_4

  btTriangleShapeEx::btTriangleShapeEx((btTriangleShapeEx *)this, &a2->m_trishape);
  v3 = clear_value;
  a2->m_tetrashape.m_userPointer = 0;
  a2->m_tetrashape.m_localScaling.mVec128.m128_i32[0] = (int)v3;
  a2->m_tetrashape.m_localScaling.mVec128.m128_i32[1] = (int)v3;
  a2->m_tetrashape.m_localScaling.mVec128.m128_i32[2] = (int)v3;
  a2->m_tetrashape.m_localScaling.mVec128.m128_i32[3] = 0;
  a2->m_tetrashape.m_collisionMargin = 0.039999999;
  a2->m_tetrashape.m_polyhedron = 0;
  a2->m_tetrashape.m_localAabbMin.mVec128.m128_i32[0] = (int)v3;
  a2->m_tetrashape.m_localAabbMin.mVec128.m128_i32[1] = (int)v3;
  a2->m_tetrashape.m_localAabbMin.mVec128.m128_i32[2] = (int)v3;
  a2->m_tetrashape.m_localAabbMin.mVec128.m128_i32[3] = 0;
  a2->m_tetrashape.m_localAabbMax.mVec128.m128_i32[0] = -1082130432;
  a2->m_tetrashape.m_localAabbMax.mVec128.m128_i32[1] = -1082130432;
  a2->m_tetrashape.m_localAabbMax.mVec128.m128_i32[2] = -1082130432;
  a2->m_tetrashape.m_localAabbMax.mVec128.m128_i32[3] = 0;
  a2->m_tetrashape.m_isLocalAabbValid = 0;
  a2->m_tetrashape.m_shapeType = 2;
  a2->m_tetrashape.__vftable = (btTetrahedronShapeEx_vtbl *)&btTetrahedronShapeEx::`vftable';
  a2->m_tetrashape.m_numVertices = 4;
  a2->m_child_retriever.__vftable = (GIM_ShapeRetriever::ChildShapeRetriever_vtbl *)&GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  a2->m_tri_retriever.__vftable = (GIM_ShapeRetriever::TriangleShapeRetriever_vtbl *)&GIM_ShapeRetriever::TriangleShapeRetriever::`vftable';
  a2->m_tetra_retriever.__vftable = (GIM_ShapeRetriever::TetraShapeRetriever_vtbl *)&GIM_ShapeRetriever::TetraShapeRetriever::`vftable';
  a2->m_gim_shape = gim_shape;
  if ( gim_shape->needsRetrieveTriangles(gim_shape) )
  {
    a2->m_current_retriever = &a2->m_tri_retriever;
    a2->m_tri_retriever.m_parent = a2;
    return a2;
  }
  else
  {
    if ( a2->m_gim_shape->needsRetrieveTetrahedrons(a2->m_gim_shape) )
    {
      a2->m_current_retriever = &a2->m_tetra_retriever;
      a2->m_tetra_retriever.m_parent = a2;
    }
    else
    {
      a2->m_current_retriever = &a2->m_child_retriever;
      a2->m_child_retriever.m_parent = a2;
    }
    return a2;
  }
}
