int __thiscall SpeedTree::CBasicString<1>::~CBasicString<1>(_BYTE *this)
{
  *(_DWORD *)this = &SpeedTree::CBasicString<1>::`vftable';
  SpeedTree::CArray<char,1>::clear(this);
  *(_DWORD *)this = &SpeedTree::CArray<char,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<char,1>::SetExternalMemory(0, 0);
  return SpeedTree::CArray<char,1>::clear(this);
}
