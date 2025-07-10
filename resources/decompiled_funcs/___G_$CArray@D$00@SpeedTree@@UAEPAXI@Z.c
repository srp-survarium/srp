_BYTE *__thiscall SpeedTree::CArray<char,1>::`scalar deleting destructor'(_BYTE *this, char a2)
{
  *(_DWORD *)this = &SpeedTree::CArray<char,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<char,1>::SetExternalMemory(0, 0);
  SpeedTree::CArray<char,1>::clear(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
