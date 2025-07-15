unsigned int __thiscall vostok_mspace_usable_size(_DWORD *mem)
{
  int v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  if ( !mem )
    return 0;
  v1 = *(mem - 1);
  if ( (v1 & 2) == 0 )
    return 0;
  if ( (v1 & 1) != 0 || (*(_BYTE *)(mem - 2) & 1) == 0 )
    v3 = 4;
  else
    v3 = 8;
  return (v1 & 0xFFFFFFF8) - v3;
}
