int __thiscall SpeedTree::CArray<char,1>::clear(int this)
{
  int result; // eax
  char *pRawBlock; // [esp+8h] [ebp-14h] BYREF

  result = this;
  if ( !*(_BYTE *)(this + 16) )
  {
    pRawBlock = *(char **)(this + 4);
    SpeedTree::st_delete_array<char>(&pRawBlock);
    result = this;
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 12) = 0;
  }
  *(_DWORD *)(this + 8) = 0;
  return result;
}
