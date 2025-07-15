int __thiscall SpeedTree::CForest::UpdateTreeCellExtents(SpeedTree::CForest *this)
{
  int v2; // [esp+4h] [ebp-44h]
  int v3; // [esp+8h] [ebp-40h]
  int v4; // [esp+Ch] [ebp-3Ch]
  int v5; // [esp+10h] [ebp-38h]
  SpeedTree::CExtents *v6; // [esp+14h] [ebp-34h]
  int v7; // [esp+3Ch] [ebp-Ch] BYREF
  int v8; // [esp+40h] [ebp-8h]
  int v9; // [esp+44h] [ebp-4h]

  v9 = 0;
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(&v7);
  while ( v7 )
  {
    if ( v8 )
      v6 = (SpeedTree::CExtents *)(v7 + *(_DWORD *)(v8 + 4));
    else
      v6 = 0;
    if ( !SpeedTree::CExtents::Valid(v6 + 1)
      || (!v8 ? (v4 = 0) : (!v7 ? (v5 = 0) : (v5 = v7 + *(_DWORD *)(v8 + 4)), v4 = v5), *(_BYTE *)(v4 + 136)) )
    {
      if ( v8 )
      {
        if ( v7 )
          v3 = v7 + *(_DWORD *)(v8 + 4);
        else
          v3 = 0;
        v2 = v3;
      }
      else
      {
        v2 = 0;
      }
      (*(void (__thiscall **)(int, int))(*(_DWORD *)(v2 + 8) + 4))(v2 + 8, v2 + 8);
      ++v9;
    }
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v7);
  }
  return v9;
}
