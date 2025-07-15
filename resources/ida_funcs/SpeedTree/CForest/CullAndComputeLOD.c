void __thiscall SpeedTree::CForest::CullAndComputeLOD(
        SpeedTree::CForest *this,
        struct SpeedTree::CView *a2,
        struct SpeedTree::SForestCullResults *a3,
        char a4)
{
  int *v4; // eax
  int v5; // edx
  struct SpeedTree::CView *p_m_vLodRefPoint; // [esp+10h] [ebp-15Ch]
  int v7; // [esp+14h] [ebp-158h]
  int v9; // [esp+44h] [ebp-128h]
  int v10; // [esp+48h] [ebp-124h]
  float v11; // [esp+54h] [ebp-118h]
  float v12; // [esp+58h] [ebp-114h]
  float v13; // [esp+5Ch] [ebp-110h]
  float v14; // [esp+60h] [ebp-10Ch]
  float v15; // [esp+64h] [ebp-108h]
  float v16; // [esp+68h] [ebp-104h]
  float v17; // [esp+6Ch] [ebp-100h]
  float v18; // [esp+70h] [ebp-FCh]
  float v19; // [esp+74h] [ebp-F8h]
  float v20; // [esp+78h] [ebp-F4h]
  float v21; // [esp+7Ch] [ebp-F0h]
  float v22; // [esp+80h] [ebp-ECh]
  int v23; // [esp+84h] [ebp-E8h]
  _BYTE v24[8]; // [esp+BCh] [ebp-B0h] BYREF
  int v25; // [esp+C4h] [ebp-A8h]
  int v26; // [esp+C8h] [ebp-A4h]
  struct SpeedTree::Vec3 v27; // [esp+CCh] [ebp-A0h] BYREF
  struct SpeedTree::Vec3 v28; // [esp+D8h] [ebp-94h] BYREF
  struct SpeedTree::Vec3 v29; // [esp+E4h] [ebp-88h] BYREF
  struct SpeedTree::Vec3 v30; // [esp+F0h] [ebp-7Ch] BYREF
  int v31; // [esp+FCh] [ebp-70h]
  int v32; // [esp+100h] [ebp-6Ch]
  int v33; // [esp+104h] [ebp-68h]
  int v34; // [esp+108h] [ebp-64h] BYREF
  signed int i; // [esp+10Ch] [ebp-60h]
  int v36; // [esp+110h] [ebp-5Ch] BYREF
  int v37; // [esp+114h] [ebp-58h] BYREF
  int v38; // [esp+118h] [ebp-54h] BYREF
  struct SpeedTree::Vec4 *m_avFrustumPlanes; // [esp+11Ch] [ebp-50h]
  SpeedTree::Vec3 *p_m_cMax; // [esp+120h] [ebp-4Ch]
  int v41; // [esp+124h] [ebp-48h] BYREF
  int v42; // [esp+128h] [ebp-44h]
  int v43; // [esp+12Ch] [ebp-40h] BYREF
  int v44; // [esp+130h] [ebp-3Ch]
  SpeedTree::CExtents *p_m_cFrustumExtents; // [esp+134h] [ebp-38h]
  struct SpeedTree::Vec3 v46; // [esp+138h] [ebp-34h] BYREF
  SpeedTree::CExtents m_cFrustumExtents; // [esp+144h] [ebp-28h] BYREF
  int v48[4]; // [esp+15Ch] [ebp-10h] BYREF

  SpeedTree::CForest::RemoveDeletedCells(this, a3);
  if ( this->m_bBaseTreesChanged )
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::clear(&a3->m_m3dInstances);
  for ( i = 0; i < (signed int)this->m_aBaseTrees.m_uiSize; ++i )
  {
    v23 = SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::operator[](&this->m_aBaseTrees.m_pData[i]);
    if ( (unsigned __int8)SpeedTree::CArray<SpeedTree::SInstanceLod,1>::reserve(0) )
      *(_DWORD *)(v23 + 8) = 0;
    else
      *(_DWORD *)(v23 + 8) = *(_DWORD *)(v23 + 12);
  }
  a3->m_pBaseTrees = &this->m_aBaseTrees;
  m_cFrustumExtents = a2->m_cFrustumExtents;
  v48[3] = 0;
  SpeedTree::CCoordSys::ConvertFromStd(
    &v46,
    this->m_fLargestInstanceCullRadius,
    this->m_fLargestInstanceCullRadius,
    0.0);
  p_m_cFrustumExtents = &m_cFrustumExtents;
  p_m_cMax = &m_cFrustumExtents.m_cMax;
  v20 = v46.x + m_cFrustumExtents.m_cMin.x;
  v21 = v46.y + m_cFrustumExtents.m_cMin.y;
  v22 = v46.z + m_cFrustumExtents.m_cMin.z;
  v30.x = v20;
  v30.y = v21;
  v30.z = v22;
  SpeedTree::CExtents::ExpandAround(&m_cFrustumExtents, &v30);
  v17 = p_m_cFrustumExtents->m_cMin.x - v46.x;
  v18 = p_m_cFrustumExtents->m_cMin.y - v46.y;
  v19 = p_m_cFrustumExtents->m_cMin.z - v46.z;
  v29.x = v17;
  v29.y = v18;
  v29.z = v19;
  SpeedTree::CExtents::ExpandAround(&m_cFrustumExtents, &v29);
  v14 = v46.x + p_m_cMax->x;
  v15 = v46.y + p_m_cMax->y;
  v16 = v46.z + p_m_cMax->z;
  v28.x = v14;
  v28.y = v15;
  v28.z = v16;
  SpeedTree::CExtents::ExpandAround(&m_cFrustumExtents, &v28);
  v11 = p_m_cMax->x - v46.x;
  v12 = p_m_cMax->y - v46.y;
  v13 = p_m_cMax->z - v46.z;
  v27.x = v11;
  v27.y = v12;
  v27.z = v13;
  SpeedTree::CExtents::ExpandAround(&m_cFrustumExtents, &v27);
  v48[0] = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  SpeedTree::ComputeCellCoords(
    (SpeedTree *)&m_cFrustumExtents,
    COERCE_CONST_STRUCT_SPEEDTREE_VEC3_(this->m_cTreeCellMap.m_fCellSize),
    v48,
    &v36);
  SpeedTree::ComputeCellCoords(
    (SpeedTree *)&m_cFrustumExtents.m_cMax,
    COERCE_CONST_STRUCT_SPEEDTREE_VEC3_(this->m_cTreeCellMap.m_fCellSize),
    &v37,
    &v38);
  if ( v37 < v48[0] )
  {
    v10 = v48[0];
    v48[0] = v37;
    v37 = v10;
  }
  if ( v38 < v36 )
  {
    v9 = v36;
    v36 = v38;
    v38 = v9;
  }
  SpeedTree::CArray<SpeedTree::CTreeCell *,1>::resize(0);
  SpeedTree::CArray<SpeedTree::CTreeCell *,1>::resize(0);
  a3->m_bFrustumContainsModifiedCells = 0;
  m_avFrustumPlanes = a2->m_avFrustumPlanes;
  v41 = v48[0];
  v42 = v36;
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::higher(&v43, &v41);
  while ( 1 )
  {
    v25 = 0;
    v26 = 0;
    if ( !v43 )
      break;
    v7 = v44 ? v43 + *(_DWORD *)(v44 + 4) : 0;
    v34 = v7 + 8;
    v33 = *(_DWORD *)(v7 + 12);
    v32 = *(_DWORD *)(v7 + 16);
    if ( v33 > v37 || v33 == v37 && v32 > v38 )
      break;
    if ( v32 >= v36 )
    {
      if ( v32 <= v38 )
      {
        v31 = FrustumCullsSphere_Detailed(m_avFrustumPlanes, v34 + 40, *(float *)(v34 + 52));
        if ( v31 != 2 )
        {
          if ( a2->m_bLodRefPointSet )
            p_m_vLodRefPoint = (struct SpeedTree::CView *)&a2->m_vLodRefPoint;
          else
            p_m_vLodRefPoint = a2;
          ProcessCellInstances(m_avFrustumPlanes, v34, v31, a3, &p_m_vLodRefPoint->m_vCameraPos, a4);
          *(_DWORD *)(v34 + 12) = this->m_nUpdateIndex;
          SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::insert_sorted_unique(&v34);
        }
        v41 = v33;
        v42 = v32 + 1;
      }
      else
      {
        v41 = v33 + 1;
        v42 = v36;
      }
    }
    else
    {
      v41 = v33;
      v42 = v36;
    }
    v4 = (int *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::higher(v24, &v41);
    v5 = v4[1];
    v43 = *v4;
    v44 = v5;
  }
  SpeedTree::CForest::DetermineCellAges(this, a3);
}
