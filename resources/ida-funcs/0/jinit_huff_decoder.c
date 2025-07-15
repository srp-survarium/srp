int __cdecl jinit_huff_decoder(int a1)
{
  int (__cdecl **v1)(int *); // ebx
  int result; // eax
  int v3; // ebp
  bool v4; // cc
  char *v5; // edx

  v1 = (int (__cdecl **)(int *))(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 216);
  *(_DWORD *)(a1 + 424) = v1;
  *v1 = sub_377950;
  if ( *(_BYTE *)(a1 + 201) )
  {
    result = (**(int (__cdecl ***)(int, int, _DWORD))(a1 + 4))(a1, 1, *(_DWORD *)(a1 + 36) << 8);
    v3 = 0;
    v4 = *(_DWORD *)(a1 + 36) <= 0;
    *(_DWORD *)(a1 + 140) = result;
    v5 = (char *)result;
    if ( !v4 )
    {
      do
      {
        result = -1;
        ++v3;
        memset(v5, 0xFFu, 0x100u);
        v5 += 256;
      }
      while ( v3 < *(_DWORD *)(a1 + 36) );
    }
    v1[11] = 0;
    v1[12] = 0;
    v1[13] = 0;
    v1[14] = 0;
  }
  else
  {
    result = 0;
    v1[20] = 0;
    v1[16] = 0;
    v1[21] = 0;
    v1[17] = 0;
    v1[22] = 0;
    v1[18] = 0;
    v1[23] = 0;
    v1[19] = 0;
  }
  return result;
}
