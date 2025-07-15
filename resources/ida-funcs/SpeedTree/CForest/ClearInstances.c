char __thiscall SpeedTree::CForest::ClearInstances(
        SpeedTree::CForest *this,
        const struct SpeedTree::CCore *a2,
        bool a3)
{
  int *v3; // eax
  int v4; // edx
  int v6; // [esp+0h] [ebp-ACh]
  int v7; // [esp+8h] [ebp-A4h]
  _BYTE v8[8]; // [esp+7Ch] [ebp-30h] BYREF
  int v9; // [esp+84h] [ebp-28h]
  int v10; // [esp+88h] [ebp-24h]
  int v11; // [esp+8Ch] [ebp-20h]
  int v12; // [esp+90h] [ebp-1Ch]
  int v13; // [esp+94h] [ebp-18h] BYREF
  int v14; // [esp+98h] [ebp-14h]
  SpeedTree::CCellInstances *v15; // [esp+9Ch] [ebp-10h]
  int v16; // [esp+A0h] [ebp-Ch] BYREF
  int v17; // [esp+A4h] [ebp-8h]
  char v18; // [esp+ABh] [ebp-1h]

  v18 = 0;
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(&v16);
  while ( 1 )
  {
    v11 = 0;
    v12 = 0;
    if ( !v16 )
      break;
    if ( v17 )
      v7 = v16 + *(_DWORD *)(v17 + 4);
    else
      v7 = 0;
    v15 = (SpeedTree::CCellInstances *)(v7 + 64);
    if ( a2 )
      SpeedTree::CCellInstances::DeleteBaseTree(v15, a2);
    else
      SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::clear(v15);
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v16);
  }
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(&v13);
  while ( 1 )
  {
    v9 = 0;
    v10 = 0;
    if ( !v13 )
      break;
    if ( v14 )
      v6 = v13 + *(_DWORD *)(v14 + 4);
    else
      v6 = 0;
    if ( SpeedTree::CCellInstances::NumInstances((SpeedTree::CCellInstances *)(v6 + 64), 0) )
    {
      SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v13);
    }
    else
    {
      v3 = (int *)SpeedTree::CForest::DeleteTreeCell(v8, &v13);
      v4 = v3[1];
      v13 = *v3;
      v14 = v4;
    }
  }
  return 1;
}
