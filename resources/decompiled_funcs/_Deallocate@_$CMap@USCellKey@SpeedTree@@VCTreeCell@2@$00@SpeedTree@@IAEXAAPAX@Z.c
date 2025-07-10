_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Deallocate(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  char *p; // [esp+Ch] [ebp-30h]

  if ( *a2 )
    p = (char *)(*a2 + this[4]);
  else
    p = 0;
  *((_DWORD *)p + 2) = &SpeedTree::CTreeCell::`vftable';
  SpeedTree::CCellInstances::~CCellInstances((SpeedTree::CCellInstances *)(p + 64));
  *((_DWORD *)p + 2) = &SpeedTree::CCell::`vftable';
  *(_DWORD *)(this[5] + 4 * this[7]) = *a2;
  result = this + 3;
  ++this[7];
  *a2 = 0;
  return result;
}
