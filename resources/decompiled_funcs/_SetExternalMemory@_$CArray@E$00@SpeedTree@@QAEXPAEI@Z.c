int __thiscall SpeedTree::CArray<unsigned char,1>::SetExternalMemory(int this, int a2, int a3)
{
  int result; // eax
  unsigned int j; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  SpeedTree::CArray<unsigned char,1>::clear(this);
  result = this;
  if ( *(_BYTE *)(this + 16) )
  {
    for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
      ;
    *(_DWORD *)(this + 12) = 0;
    result = this;
    *(_DWORD *)(this + 4) = 0;
  }
  if ( a2 )
  {
    result = a3;
    *(_DWORD *)(this + 12) = a3;
    *(_DWORD *)(this + 4) = a2;
    for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
      result = j + 1;
    *(_BYTE *)(this + 16) = 1;
  }
  else
  {
    *(_BYTE *)(this + 16) = 0;
  }
  return result;
}
