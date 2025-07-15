void __thiscall SpeedTree::CCore::ComputeLodSnapshot(
        SpeedTree::CCore *this,
        float a2,
        struct SpeedTree::SLodSnapshot *a3)
{
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  float v7; // [esp+14h] [ebp-4h]

  if ( a2 == -1.0 )
  {
    a3->m_nBranchLodIndex = -1;
    a3->m_nFrondLodIndex = -1;
    a3->m_nLeafCardLodIndex = -1;
    a3->m_nLeafMeshLodIndex = -1;
  }
  else if ( a2 > 0.0 )
  {
    if ( a2 < 1.0 )
    {
      v7 = 1.0 - a2;
      a3->m_nBranchLodIndex = (int)((double)this->m_sGeometry.m_nNumBranchLods * v7);
      a3->m_nFrondLodIndex = (int)((double)this->m_sGeometry.m_nNumFrondLods * v7);
      a3->m_nLeafMeshLodIndex = (int)((double)this->m_sGeometry.m_nNumLeafMeshLods * v7);
      a3->m_nLeafCardLodIndex = (int)((double)this->m_sGeometry.m_nNumLeafCardLods * v7);
    }
    else
    {
      a3->m_nBranchLodIndex = (this->m_sGeometry.m_nNumBranchLods > 0) - 1;
      a3->m_nFrondLodIndex = (this->m_sGeometry.m_nNumFrondLods > 0) - 1;
      a3->m_nLeafMeshLodIndex = (this->m_sGeometry.m_nNumLeafMeshLods > 0) - 1;
      a3->m_nLeafCardLodIndex = (this->m_sGeometry.m_nNumLeafCardLods > 0) - 1;
    }
  }
  else
  {
    if ( this->m_sGeometry.m_nNumBranchLods <= 0 )
      LOBYTE(v6) = -1;
    else
      v6 = this->m_sGeometry.m_nNumBranchLods - 1;
    a3->m_nBranchLodIndex = v6;
    if ( this->m_sGeometry.m_nNumFrondLods <= 0 )
      LOBYTE(v5) = -1;
    else
      v5 = this->m_sGeometry.m_nNumFrondLods - 1;
    a3->m_nFrondLodIndex = v5;
    if ( this->m_sGeometry.m_nNumLeafMeshLods <= 0 )
      LOBYTE(v4) = -1;
    else
      v4 = this->m_sGeometry.m_nNumLeafMeshLods - 1;
    a3->m_nLeafMeshLodIndex = v4;
    if ( this->m_sGeometry.m_nNumLeafCardLods <= 0 )
      LOBYTE(v3) = -1;
    else
      v3 = this->m_sGeometry.m_nNumLeafCardLods - 1;
    a3->m_nLeafCardLodIndex = v3;
  }
}
