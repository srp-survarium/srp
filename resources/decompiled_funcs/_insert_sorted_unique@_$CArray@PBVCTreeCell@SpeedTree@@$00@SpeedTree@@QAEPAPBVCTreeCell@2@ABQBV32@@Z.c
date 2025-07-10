int __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::insert_sorted_unique(_DWORD *this, int a2)
{
  int v4; // [esp+50h] [ebp-8h] BYREF
  int v5; // [esp+54h] [ebp-4h] BYREF

  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::lower_and_higher(a2, &v4, &v5);
  if ( v4 != this[1] + 4 * this[2] && v4 == v5 )
    return v4;
  else
    return SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::insert(v5, a2);
}
