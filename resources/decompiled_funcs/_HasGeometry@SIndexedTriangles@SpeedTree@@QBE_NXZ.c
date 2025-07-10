bool __thiscall SpeedTree::SIndexedTriangles::HasGeometry(SpeedTree::SIndexedTriangles *this)
{
  return this->m_nNumVertices > 0
      && this->m_pCoords
      && this->m_nNumMaterialGroups > 0
      && this->m_pDrawCallInfo
      && (this->m_pTriangleIndices16 || this->m_pTriangleIndices32);
}
