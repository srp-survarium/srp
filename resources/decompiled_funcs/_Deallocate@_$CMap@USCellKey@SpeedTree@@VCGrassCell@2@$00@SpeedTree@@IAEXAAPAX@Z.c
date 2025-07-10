_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *p; // [esp+8h] [ebp-Ch]

  if ( *a2 )
    p = (_DWORD *)(*a2 + this[4]);
  else
    p = 0;
  p[2] = &SpeedTree::CGrassCell::`vftable';
  p[2] = &SpeedTree::CCell::`vftable';
  *(_DWORD *)(this[5] + 4 * this[7]) = *a2;
  result = this + 3;
  ++this[7];
  *a2 = 0;
  return result;
}
