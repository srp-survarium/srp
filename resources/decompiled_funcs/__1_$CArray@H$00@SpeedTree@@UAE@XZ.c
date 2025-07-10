int __thiscall SpeedTree::CArray<int,1>::~CArray<int,1>(_BYTE *this)
{
  *(_DWORD *)this = &SpeedTree::CArray<float,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<float,1>::SetExternalMemory(0, 0);
  return SpeedTree::CArray<int,1>::clear(this);
}
