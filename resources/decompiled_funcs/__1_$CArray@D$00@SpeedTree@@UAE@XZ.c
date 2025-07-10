int __thiscall SpeedTree::CArray<char,1>::~CArray<char,1>(_BYTE *this)
{
  *(_DWORD *)this = &SpeedTree::CArray<char,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<char,1>::SetExternalMemory(0, 0);
  return SpeedTree::CArray<char,1>::clear(this);
}
