int __cdecl jinit_arith_decoder(int a1)
{
  int result; // eax
  _DWORD *v2; // ecx
  int v3; // edx
  int v4; // ebx
  bool v5; // cc
  char *v6; // edx

  result = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 188);
  *(_DWORD *)(a1 + 424) = result;
  *(_DWORD *)result = sub_378C40;
  v2 = (_DWORD *)(result + 120);
  v3 = 16;
  v4 = 0;
  do
  {
    *(v2 - 16) = 0;
    *v2++ = 0;
    --v3;
  }
  while ( v3 );
  *(_BYTE *)(result + 184) = 113;
  if ( *(_BYTE *)(a1 + 201) )
  {
    result = (**(int (__cdecl ***)(int, int, _DWORD))(a1 + 4))(a1, 1, *(_DWORD *)(a1 + 36) << 8);
    v5 = *(_DWORD *)(a1 + 36) <= 0;
    *(_DWORD *)(a1 + 140) = result;
    v6 = (char *)result;
    if ( !v5 )
    {
      do
      {
        result = -1;
        ++v4;
        memset(v6, 0xFFu, 0x100u);
        v6 += 256;
      }
      while ( v4 < *(_DWORD *)(a1 + 36) );
    }
  }
  return result;
}
