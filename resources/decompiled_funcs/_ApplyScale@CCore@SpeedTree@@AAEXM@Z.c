void __thiscall SpeedTree::CCore::ApplyScale(SpeedTree::CCore *this, float a2)
{
  int v3[3]; // [esp+Ch] [ebp-60h] BYREF
  int v4[3]; // [esp+18h] [ebp-54h] BYREF
  int v5[3]; // [esp+24h] [ebp-48h] BYREF
  int v6[3]; // [esp+30h] [ebp-3Ch] BYREF
  int v7[3]; // [esp+3Ch] [ebp-30h] BYREF
  SpeedTree::SCollisionObject *v8; // [esp+48h] [ebp-24h]
  int ii; // [esp+4Ch] [ebp-20h]
  int n; // [esp+50h] [ebp-1Ch]
  int m; // [esp+54h] [ebp-18h]
  int k; // [esp+58h] [ebp-14h]
  int j; // [esp+5Ch] [ebp-10h]
  int i; // [esp+60h] [ebp-Ch]
  SpeedTree::SHorizontalBillboard *p_m_sHorzBB; // [esp+64h] [ebp-8h]
  SpeedTree::SVerticalBillboards *p_m_sVertBBs; // [esp+68h] [ebp-4h]

  if ( a2 != 1.0 )
  {
    if ( this->m_sGeometry.m_pBranchLods && this->m_sGeometry.m_nNumBranchLods > 0 )
    {
      for ( i = 0; i < this->m_sGeometry.m_nNumBranchLods; ++i )
        ApplyScaleToIndexedTriangles(&this->m_sGeometry.m_pBranchLods[i], a2);
    }
    if ( this->m_sGeometry.m_pFrondLods && this->m_sGeometry.m_nNumFrondLods > 0 )
    {
      for ( j = 0; j < this->m_sGeometry.m_nNumFrondLods; ++j )
        ApplyScaleToIndexedTriangles(&this->m_sGeometry.m_pFrondLods[j], a2);
    }
    if ( this->m_sGeometry.m_pLeafMeshLods && this->m_sGeometry.m_nNumLeafMeshLods > 0 )
    {
      for ( k = 0; k < this->m_sGeometry.m_nNumLeafMeshLods; ++k )
        ApplyScaleToIndexedTriangles(&this->m_sGeometry.m_pLeafMeshLods[k], a2);
    }
    if ( this->m_sGeometry.m_pLeafCardLods && this->m_sGeometry.m_nNumLeafCardLods > 0 )
    {
      for ( m = 0; m < this->m_sGeometry.m_nNumLeafCardLods; ++m )
        ApplyScaleToLeafCards(&this->m_sGeometry.m_pLeafCardLods[m], a2);
    }
    p_m_sVertBBs = &this->m_sGeometry.m_sVertBBs;
    this->m_sGeometry.m_sVertBBs.m_fWidth = this->m_sGeometry.m_sVertBBs.m_fWidth * a2;
    p_m_sVertBBs->m_fTopCoord = p_m_sVertBBs->m_fTopCoord * a2;
    p_m_sVertBBs->m_fBottomCoord = p_m_sVertBBs->m_fBottomCoord * a2;
    p_m_sHorzBB = &this->m_sGeometry.m_sHorzBB;
    if ( this->m_sGeometry.m_sHorzBB.m_bPresent )
    {
      for ( n = 0; n < 4; ++n )
        SpeedTree::Vec3::operator*=((int)v7, a2);
    }
    SpeedTree::CWind::Scale(&this->m_cWind, a2);
    for ( ii = 0; ii < this->m_nNumCollisionObjects; ++ii )
    {
      v8 = &this->m_pCollisionObjects[ii];
      SpeedTree::Vec3::operator*=((int)v6, a2);
      SpeedTree::Vec3::operator*=((int)v5, a2);
      v8->m_fRadius = v8->m_fRadius * a2;
    }
    SpeedTree::Vec3::operator*=((int)v4, a2);
    SpeedTree::Vec3::operator*=((int)v3, a2);
  }
}
