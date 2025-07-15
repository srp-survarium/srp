unsigned int __thiscall vostok_mspace_usable_size(_DWORD *mem)
{
  int v1; // eax
  bool v2; // zf
  int v3; // ecx

  if ( !mem )
    return 0;
  v1 = *(mem - 1);
  if ( (v1 & 2) == 0 )
    return 0;
  if ( (v1 & 1) != 0 || (v2 = (*(_BYTE *)(mem - 2) & 1) == 0, v3 = 8, v2) )
    v3 = 4;
  return (v1 & 0xFFFFFFF8) - v3;
}
