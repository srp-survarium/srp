char __thiscall SpeedTree::CCellInstances::AddInstance(
        SpeedTree::CCellInstances *this,
        const struct SpeedTree::CCore *a2,
        const struct SpeedTree::CInstance *tNew)
{
  int v3; // eax
  const SpeedTree::CInstance *v5; // [esp-4h] [ebp-D4h]
  int v6; // [esp+C4h] [ebp-Ch] BYREF
  char v7; // [esp+CFh] [ebp-1h]

  v7 = 0;
  SpeedTree::CCellInstances::AddBaseTree(this, a2);
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::find(&v6, &a2);
  if ( v6 )
  {
    v5 = tNew;
    v3 = SpeedTree::CArray<SpeedTree::CInstance,1>::higher(tNew);
    SpeedTree::CArray<SpeedTree::CInstance,1>::insert(v3, v5);
    return 1;
  }
  return v7;
}
