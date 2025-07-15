int __usercall sub_37C340@<eax>(int a1@<eax>)
{
  int v1; // esi
  int result; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // esi

  v1 = *(_DWORD *)(a1 + 440);
  result = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 2044) + 1020;
  *(_DWORD *)(v1 + 40) = result;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = (_DWORD *)result;
  do
  {
    *(_DWORD *)(result + 4 * v4) = v3;
    *v6 = v5;
    ++v4;
    --v6;
    ++v3;
    --v5;
  }
  while ( v4 < 16 );
  if ( v4 < 48 )
  {
    v7 = (_DWORD *)(result - 4 * v4);
    do
    {
      *(_DWORD *)(result + 4 * v4) = v3;
      *v7 = -v3;
      ++v4;
      --v7;
      v3 += (v4 & 1) == 0;
    }
    while ( v4 < 48 );
  }
  if ( v4 <= 255 )
  {
    v8 = (_DWORD *)(result - 4 * v4);
    do
    {
      *(_DWORD *)(result + 4 * v4) = v3;
      *v8 = -v3;
      ++v4;
      --v8;
    }
    while ( v4 <= 255 );
  }
  return result;
}
