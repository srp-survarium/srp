char __thiscall SpeedTree::CForest::AddInstances(
        SpeedTree::CForest *this,
        const struct SpeedTree::CCore *a2,
        const struct SpeedTree::CInstance *a3,
        int a4)
{
  float m_fLargestInstanceCullRadius; // [esp+18h] [ebp-B8h]
  int v6; // [esp+1Ch] [ebp-B4h]
  int v7; // [esp+20h] [ebp-B0h]
  int v9; // [esp+74h] [ebp-5Ch] BYREF
  int v10; // [esp+78h] [ebp-58h] BYREF
  float m_fCullingRadius; // [esp+7Ch] [ebp-54h]
  SpeedTree *v12; // [esp+80h] [ebp-50h]
  int v13; // [esp+84h] [ebp-4Ch] BYREF
  int v14; // [esp+88h] [ebp-48h]
  SpeedTree::CCellInstances *v15; // [esp+8Ch] [ebp-44h]
  SpeedTree::CInstance v16; // [esp+90h] [ebp-40h] BYREF
  int v17; // [esp+B8h] [ebp-18h]
  int i; // [esp+BCh] [ebp-14h]
  char v19; // [esp+C3h] [ebp-Dh]
  int v20; // [esp+CCh] [ebp-4h]

  v19 = 0;
  for ( i = 0; i < a4; ++i )
  {
    v12 = (SpeedTree *)&a3[i];
    SpeedTree::ComputeCellCoords(v12, COERCE_CONST_STRUCT_SPEEDTREE_VEC3_(this->m_cTreeCellMap.m_fCellSize), &v9, &v10);
    SpeedTree::CCellContainer<SpeedTree::CTreeCell>::GetCellItrByRowCol_Add(&v13, v9, v10);
    if ( v14 )
    {
      if ( v13 )
        v7 = v13 + *(_DWORD *)(v14 + 4);
      else
        v7 = 0;
      v6 = v7;
    }
    else
    {
      v6 = 0;
    }
    v17 = v6 + 8;
    *(_BYTE *)(v6 + 136) = 1;
    v15 = (SpeedTree::CCellInstances *)(v17 + 56);
    qmemcpy((void *)&v16, v12, sizeof(v16));
    v20 = 0;
    SpeedTree::CInstance::ComputeCullParameters(&v16, a2);
    if ( !SpeedTree::CCellInstances::AddInstance(v15, a2, &v16) )
    {
      SpeedTree::CCore::SetError("CForest::AddInstances, internal error #1");
      v19 = 0;
      v20 = -1;
      SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&v16);
      break;
    }
    m_fCullingRadius = v16.m_fCullingRadius;
    if ( v16.m_fCullingRadius >= (double)this->m_fLargestInstanceCullRadius )
      m_fLargestInstanceCullRadius = m_fCullingRadius;
    else
      m_fLargestInstanceCullRadius = this->m_fLargestInstanceCullRadius;
    this->m_fLargestInstanceCullRadius = m_fLargestInstanceCullRadius;
    v19 = 1;
    v20 = -1;
    SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&v16);
  }
  if ( !a4 )
    return 1;
  return v19;
}
