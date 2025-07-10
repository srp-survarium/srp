int __thiscall SpeedTree::CArray<int,1>::clear(int this)
{
  int result; // eax
  _DWORD v3[4]; // [esp+8h] [ebp-14h] BYREF

  result = this;
  if ( !*(_BYTE *)(this + 16) )
  {
    v3[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<float>(v3);
    result = this;
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 12) = 0;
  }
  *(_DWORD *)(this + 8) = 0;
  return result;
}
