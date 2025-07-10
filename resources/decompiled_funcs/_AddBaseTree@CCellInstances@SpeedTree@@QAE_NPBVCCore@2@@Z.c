char __thiscall SpeedTree::CCellInstances::AddBaseTree(
        SpeedTree::CCellInstances *this,
        const struct SpeedTree::CCore *a2)
{
  _DWORD v3[8]; // [esp+3Ch] [ebp-30h] BYREF
  bool v4; // [esp+5Fh] [ebp-Dh]
  int v5; // [esp+60h] [ebp-Ch] BYREF
  char v6; // [esp+6Bh] [ebp-1h]

  v6 = 0;
  v3[0] = a2;
  v4 = 0;
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::find(&v5, v3);
  v3[6] = 0;
  v3[7] = 0;
  v4 = v5 != 0;
  if ( !v5 )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::operator[](&a2);
    return 1;
  }
  return v6;
}
