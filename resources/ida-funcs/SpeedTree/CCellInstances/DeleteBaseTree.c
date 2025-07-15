char __thiscall SpeedTree::CCellInstances::DeleteBaseTree(
        SpeedTree::CCellInstances *this,
        const struct SpeedTree::CCore *a2)
{
  _DWORD v3[11]; // [esp-8h] [ebp-4Ch] BYREF
  _BYTE v4[12]; // [esp+24h] [ebp-20h] BYREF
  int v5; // [esp+30h] [ebp-14h]
  int v6; // [esp+34h] [ebp-10h]
  int v7; // [esp+38h] [ebp-Ch] BYREF
  int v8; // [esp+3Ch] [ebp-8h]
  char v9; // [esp+43h] [ebp-1h]

  v3[2] = this;
  v9 = 0;
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::find(&v7, &a2);
  v5 = 0;
  v6 = 0;
  if ( v7 )
  {
    v3[3] = v3;
    v3[4] = v8;
    v3[5] = v7;
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::erase(v4, v7, v8);
    return 1;
  }
  return v9;
}
