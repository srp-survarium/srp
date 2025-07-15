unsigned int __cdecl sub_486BB0(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // esi
  unsigned int v8; // edi
  unsigned int result; // eax

  v7 = (_DWORD *)a1[103];
  if ( !v7[6] )
    v7[3] = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))(a1[1] + 28))(a1, v7[2], v7[5], v7[4], 0);
  v8 = v7[4] - v7[6];
  if ( v8 > a7 - *a6 )
    v8 = a7 - *a6;
  if ( v8 > a1[24] - v7[5] )
    v8 = a1[24] - v7[5];
  (*(void (__cdecl **)(_DWORD *, int, int, unsigned int))(a1[110] + 4))(a1, v7[3] + 4 * v7[6], a5 + 4 * *a6, v8);
  *a6 += v8;
  v7[6] += v8;
  result = v7[4];
  if ( v7[6] >= result )
  {
    v7[5] += result;
    v7[6] = 0;
  }
  return result;
}
