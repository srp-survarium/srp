void __thiscall SpeedTree::CForest::GetPopulationStats(
        SpeedTree::CForest *this,
        struct SpeedTree::CForest::SPopulationStats *a2)
{
  const struct SpeedTree::CCore *v2; // eax
  int v3; // eax
  int v4; // eax
  int m_nNumBillboards; // [esp+4h] [ebp-1E0h]
  int v6; // [esp+8h] [ebp-1DCh]
  int v7; // [esp+10h] [ebp-1D4h]
  int v8; // [esp+14h] [ebp-1D0h]
  int v9; // [esp+18h] [ebp-1CCh]
  int v10; // [esp+1Ch] [ebp-1C8h]
  int m_nMaxNumBillboardsPerCell; // [esp+24h] [ebp-1C0h]
  int v12; // [esp+28h] [ebp-1BCh]
  int v13; // [esp+30h] [ebp-1B4h]
  int *v15; // [esp+4Ch] [ebp-198h]
  int v16; // [esp+50h] [ebp-194h]
  int *v17; // [esp+D4h] [ebp-110h]
  int v18; // [esp+D8h] [ebp-10Ch]
  int *v19; // [esp+12Ch] [ebp-B8h]
  int v20; // [esp+130h] [ebp-B4h]
  _BYTE v21[8]; // [esp+154h] [ebp-90h] BYREF
  int v22; // [esp+15Ch] [ebp-88h]
  _DWORD v23[3]; // [esp+160h] [ebp-84h] BYREF
  _BYTE v24[8]; // [esp+16Ch] [ebp-78h] BYREF
  int v25; // [esp+174h] [ebp-70h]
  int v26; // [esp+178h] [ebp-6Ch]
  int v27; // [esp+17Ch] [ebp-68h]
  _BYTE v28[8]; // [esp+180h] [ebp-64h] BYREF
  int v29; // [esp+188h] [ebp-5Ch]
  int v30; // [esp+18Ch] [ebp-58h]
  _BYTE v31[8]; // [esp+190h] [ebp-54h] BYREF
  SpeedTree::SGeometry *p_m_sGeometry; // [esp+198h] [ebp-4Ch]
  int j; // [esp+19Ch] [ebp-48h]
  int v34; // [esp+1A0h] [ebp-44h] BYREF
  int v35; // [esp+1A4h] [ebp-40h]
  int *v36; // [esp+1A8h] [ebp-3Ch]
  SpeedTree::CCellBaseTreeItr v37; // [esp+1ACh] [ebp-38h] BYREF
  int v38; // [esp+1B8h] [ebp-2Ch] BYREF
  int v39; // [esp+1BCh] [ebp-28h]
  int i; // [esp+1C0h] [ebp-24h]
  int v41; // [esp+1C4h] [ebp-20h] BYREF
  int v42; // [esp+1C8h] [ebp-1Ch]
  int v43; // [esp+1CCh] [ebp-18h] BYREF
  int v44; // [esp+1D0h] [ebp-14h]
  int v45; // [esp+1D4h] [ebp-10h]
  int v46; // [esp+1E0h] [ebp-4h]

  a2->m_nNumCells = this->m_cTreeCellMap.m_uiSize;
  a2->m_nNumBaseTrees = this->m_aBaseTrees.m_uiSize;
  a2->m_nNumInstances = 0;
  v19 = (int *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(v31);
  v20 = v19[1];
  v43 = *v19;
  v44 = v20;
  while ( 1 )
  {
    v29 = 0;
    v30 = 0;
    if ( !v43 )
      break;
    if ( v44 )
      v13 = v43 + *(_DWORD *)(v44 + 4);
    else
      v13 = 0;
    a2->m_nNumInstances += SpeedTree::CCellInstances::NumInstances((SpeedTree::CCellInstances *)(v13 + 64), 0);
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v43);
  }
  a2->m_fAverageNumInstancesPerBase = (double)a2->m_nNumInstances / (double)a2->m_nNumBaseTrees;
  a2->m_nMaxNumBillboardsPerCell = 0;
  v17 = (int *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(v28);
  v18 = v17[1];
  v41 = *v17;
  v42 = v18;
  while ( 1 )
  {
    v26 = 0;
    v27 = 0;
    if ( !v41 )
      break;
    if ( v42 )
      v12 = v41 + *(_DWORD *)(v42 + 4);
    else
      v12 = 0;
    v25 = SpeedTree::CCellInstances::NumInstances((SpeedTree::CCellInstances *)(v12 + 64), 0);
    if ( a2->m_nMaxNumBillboardsPerCell <= v25 )
      m_nMaxNumBillboardsPerCell = v25;
    else
      m_nMaxNumBillboardsPerCell = a2->m_nMaxNumBillboardsPerCell;
    a2->m_nMaxNumBillboardsPerCell = m_nMaxNumBillboardsPerCell;
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v41);
  }
  a2->m_nMaxNumInstancesPerCell = a2->m_nMaxNumBillboardsPerCell;
  for ( i = 0; i < a2->m_nNumBaseTrees; ++i )
    *(_DWORD *)SpeedTree::CMap<SpeedTree::CCore const *,int,1>::operator[](&this->m_aBaseTrees.m_pData[i]) = 0;
  v15 = (int *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(v24);
  v16 = v15[1];
  v38 = *v15;
  v39 = v16;
  while ( 1 )
  {
    v23[1] = 0;
    v23[2] = 0;
    if ( !v38 )
      break;
    if ( v39 )
      v10 = v38 + *(_DWORD *)(v39 + 4);
    else
      v10 = 0;
    SpeedTree::CCellInstances::FirstBaseTree((SpeedTree::CCellInstances *)(v10 + 64), &v37);
    v46 = 0;
    while ( SpeedTree::CCellBaseTreeItr::TreePtr(&v37) )
    {
      v23[0] = SpeedTree::CCellBaseTreeItr::TreePtr(&v37);
      v36 = (int *)SpeedTree::CMap<SpeedTree::CCore const *,int,1>::operator[](v23);
      if ( v39 )
      {
        if ( v38 )
          v9 = v38 + *(_DWORD *)(v39 + 4);
        else
          v9 = 0;
        v8 = v9;
      }
      else
      {
        v8 = 0;
      }
      v2 = SpeedTree::CCellBaseTreeItr::TreePtr(&v37);
      v22 = SpeedTree::CCellInstances::NumInstances((SpeedTree::CCellInstances *)(v8 + 64), v2);
      if ( *v36 <= v22 )
        v7 = v22;
      else
        v7 = *v36;
      *v36 = v7;
      SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::iterator_base::operator++(&v37);
    }
    v46 = -1;
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v38);
  }
  v45 = 0;
  v3 = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(v21);
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::const_iterator::const_iterator(v3);
  while ( v34 )
  {
    if ( v35 )
      v6 = v34 + *(_DWORD *)(v35 + 4);
    else
      v6 = 0;
    v4 = SpeedTree::CCellInstances::NumInstances((SpeedTree::CCellInstances *)(v6 + 64), 0);
    v45 += v4;
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v34);
  }
  if ( a2->m_nNumCells <= 0 )
    a2->m_fAverageInstancesPerCell = 0.0;
  else
    a2->m_fAverageInstancesPerCell = (double)v45 / (double)a2->m_nNumCells;
  a2->m_nMaxNumBillboardImages = 0;
  for ( j = 0; j < a2->m_nNumBaseTrees; ++j )
  {
    p_m_sGeometry = &this->m_aBaseTrees.m_pData[j]->m_sGeometry;
    if ( p_m_sGeometry )
    {
      if ( a2->m_nMaxNumBillboardImages <= p_m_sGeometry->m_sVertBBs.m_nNumBillboards )
        m_nNumBillboards = p_m_sGeometry->m_sVertBBs.m_nNumBillboards;
      else
        m_nNumBillboards = a2->m_nMaxNumBillboardImages;
      a2->m_nMaxNumBillboardImages = m_nNumBillboards;
    }
  }
}
