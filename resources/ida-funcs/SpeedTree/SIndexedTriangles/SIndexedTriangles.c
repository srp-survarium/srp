SpeedTree::SIndexedTriangles *__thiscall SpeedTree::SIndexedTriangles::SIndexedTriangles(
        SpeedTree::SIndexedTriangles *this)
{
  this->m_nNumMaterialGroups = 0;
  this->m_pDrawCallInfo = 0;
  this->m_pTriangleIndices16 = 0;
  this->m_pTriangleIndices32 = 0;
  this->m_nNumVertices = 0;
  this->m_pCoords = 0;
  this->m_pLodCoords = 0;
  this->m_pNormals = 0;
  this->m_pBinormals = 0;
  this->m_pTangents = 0;
  this->m_pTexCoordsDiffuse = 0;
  this->m_pTexCoordsDetail = 0;
  this->m_pAmbientOcclusionValues = 0;
  this->m_fWindDataMagnitude = 1.0;
  this->m_pWindData = 0;
  this->m_pFrondRipple = 0;
  this->m_pLeafMeshWind = 0;
  return this;
}
