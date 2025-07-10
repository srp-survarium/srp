void __thiscall SpeedTree::CCore::InventoryGeometry(SpeedTree::CCore *this)
{
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]
  int k; // [esp+8h] [ebp-4h]
  int m; // [esp+8h] [ebp-4h]

  if ( this->m_sGeometry.m_pBranchLods )
  {
    for ( i = 0; i < this->m_sGeometry.m_nNumBranchLods; ++i )
    {
      if ( SpeedTree::SIndexedTriangles::HasGeometry(&this->m_sGeometry.m_pBranchLods[i]) )
      {
        this->m_abGeometryTypesPresent[0] = 1;
        break;
      }
    }
  }
  if ( this->m_sGeometry.m_pFrondLods )
  {
    for ( j = 0; j < this->m_sGeometry.m_nNumFrondLods; ++j )
    {
      if ( SpeedTree::SIndexedTriangles::HasGeometry(&this->m_sGeometry.m_pFrondLods[j]) )
      {
        this->m_abGeometryTypesPresent[1] = 1;
        break;
      }
    }
  }
  if ( this->m_sGeometry.m_pLeafMeshLods )
  {
    for ( k = 0; k < this->m_sGeometry.m_nNumLeafMeshLods; ++k )
    {
      if ( SpeedTree::SIndexedTriangles::HasGeometry(&this->m_sGeometry.m_pLeafMeshLods[k]) )
      {
        this->m_abGeometryTypesPresent[3] = 1;
        break;
      }
    }
  }
  for ( m = 0; m < this->m_sGeometry.m_nNumLeafCardLods; ++m )
  {
    if ( SpeedTree::SLeafCards::HasGeometry(&this->m_sGeometry.m_pLeafCardLods[m]) )
    {
      this->m_abGeometryTypesPresent[2] = 1;
      break;
    }
  }
  if ( this->m_sGeometry.m_sVertBBs.m_nNumBillboards > 0
    && this->m_sGeometry.m_sVertBBs.m_pTexCoords
    && this->m_sGeometry.m_sVertBBs.m_fWidth > 0.0 )
  {
    this->m_abGeometryTypesPresent[4] = 1;
  }
  this->m_abGeometryTypesPresent[5] = this->m_sGeometry.m_sHorzBB.m_bPresent;
}
