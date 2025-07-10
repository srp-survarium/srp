char __thiscall SpeedTree::CForest::DeleteInstances(
        SpeedTree::CForest *this,
        const struct SpeedTree::CCore *a2,
        const struct SpeedTree::CInstance *a3,
        int a4,
        bool a5)
{
  int v7; // [esp+10h] [ebp-D4h]
  int v9; // [esp+B0h] [ebp-34h] BYREF
  int v10; // [esp+B4h] [ebp-30h] BYREF
  _BYTE v11[8]; // [esp+B8h] [ebp-2Ch] BYREF
  int v12; // [esp+C0h] [ebp-24h]
  int v13; // [esp+C4h] [ebp-20h]
  SpeedTree::CCellInstances *v14; // [esp+C8h] [ebp-1Ch]
  int v15; // [esp+CCh] [ebp-18h]
  const struct SpeedTree::CInstance *v16; // [esp+D0h] [ebp-14h]
  int v17; // [esp+D4h] [ebp-10h] BYREF
  int v18; // [esp+D8h] [ebp-Ch]
  int i; // [esp+DCh] [ebp-8h]
  char v20; // [esp+E1h] [ebp-3h]
  char v21; // [esp+E2h] [ebp-2h]
  char v22; // [esp+E3h] [ebp-1h]

  v22 = 0;
  if ( a2 && a3 )
  {
    v20 = 0;
    v21 = 0;
    for ( i = 0; i < a4; ++i )
    {
      v16 = &a3[i];
      SpeedTree::ComputeCellCoords(
        (SpeedTree *)v16,
        COERCE_CONST_STRUCT_SPEEDTREE_VEC3_(this->m_cTreeCellMap.m_fCellSize),
        &v9,
        &v10);
      SpeedTree::CCellContainer<SpeedTree::CTreeCell>::GetCellItrByRowCol_Add(&v17, v9, v10);
      v12 = 0;
      v13 = 0;
      if ( v17 )
      {
        if ( v18 )
          v7 = v17 + *(_DWORD *)(v18 + 4);
        else
          v7 = 0;
        v15 = v7 + 8;
        *(_BYTE *)(v7 + 136) = 1;
        v14 = (SpeedTree::CCellInstances *)(v15 + 56);
        if ( SpeedTree::CCellInstances::DeleteInstance((SpeedTree::CCellInstances *)(v15 + 56), a2, v16) )
        {
          if ( a5 && !SpeedTree::CCellInstances::NumInstances(v14, 0) )
            SpeedTree::CForest::DeleteTreeCell(v11, &v17);
        }
        else
        {
          v21 = 1;
          SpeedTree::CCore::SetError(
            "CForest::DeleteInstances, failed to find instance [%d of %d] in cell [row: %d, col: %d] in CForest::DeleteInstances()",
            i + 1,
            a4,
            *(_DWORD *)(v15 + 4),
            *(_DWORD *)(v15 + 8));
        }
      }
      else
      {
        v20 = 1;
        SpeedTree::CCore::SetError(
          "CForest::DeleteInstances, failed to find cell for instance [%d of %d] in CForest::DeleteInstances()",
          i + 1,
          a4);
      }
    }
    return !v21 && !v20;
  }
  else
  {
    SpeedTree::CCore::SetError("CForest::DeleteInstances, NULL pointer passed in");
  }
  return v22;
}
