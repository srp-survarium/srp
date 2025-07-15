_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::const_iterator::const_iterator(
        _DWORD *this,
        _DWORD *a2)
{
  int v3; // [esp+4h] [ebp-8h]

  v3 = a2[1];
  *this = *a2;
  this[1] = v3;
  return this;
}
