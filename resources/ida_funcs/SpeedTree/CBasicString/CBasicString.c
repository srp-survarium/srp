_DWORD *__thiscall SpeedTree::CBasicString<1>::CBasicString<1>(_DWORD *this)
{
  *this = &SpeedTree::CArray<char,1>::`vftable';
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  *((_BYTE *)this + 16) = 0;
  *this = &SpeedTree::CBasicString<1>::`vftable';
  SpeedTree::CBasicString<1>::operator=((unsigned __int8 *)&buf);
  return this;
}
