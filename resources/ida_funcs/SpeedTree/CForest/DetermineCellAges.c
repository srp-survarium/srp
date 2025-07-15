void __thiscall SpeedTree::CForest::DetermineCellAges(
        SpeedTree::CForest *this,
        struct SpeedTree::SForestCullResults *a2)
{
  int v3; // [esp+48h] [ebp-30h] BYREF
  int i; // [esp+4Ch] [ebp-2Ch]
  unsigned __int8 *v5; // [esp+54h] [ebp-24h]
  int v6; // [esp+58h] [ebp-20h]
  int v7; // [esp+74h] [ebp-4h]

  if ( a2->m_aVisibleCells.m_uiSize )
  {
    SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::CLocalArray<SpeedTree::CTreeCell const *>(
      a2->m_aVisibleCells.m_uiSize,
      "DetermineCellAges",
      1);
    v7 = 0;
    memcpy(v5, (unsigned __int8 *)a2->m_aVisibleCells.m_pData, 4 * a2->m_aVisibleCells.m_uiSize);
    if ( SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(
           (SpeedTree::CArray<SpeedTree::CCore *,1> *)&a2->m_aVisibleCells,
           0) )
    {
      a2->m_aVisibleCells.m_uiSize = 0;
    }
    else
    {
      a2->m_aVisibleCells.m_uiSize = a2->m_aVisibleCells.m_uiDataSize;
    }
    for ( i = 0; i < v6; ++i )
    {
      v3 = *(_DWORD *)&v5[4 * i];
      if ( *(_DWORD *)(v3 + 12) == this->m_nUpdateIndex )
      {
        SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::push_back(&v3);
        if ( *(_DWORD *)(v3 + 132) == -1 || *(_BYTE *)(v3 + 128) )
          SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::push_back(&v3);
        if ( *(_BYTE *)(v3 + 128) )
          a2->m_bFrustumContainsModifiedCells = 1;
      }
      else if ( *(_DWORD *)(v3 + 132) != -1 )
      {
        SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::push_back(&v3);
      }
      *(_BYTE *)(v3 + 128) = 0;
    }
    v7 = -1;
    SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::~CLocalArray<SpeedTree::CTreeCell const *>();
  }
}
