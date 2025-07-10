unsigned int __cdecl sub_379E40(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  _DWORD *v7; // esi
  unsigned int *v8; // ebx
  unsigned int v9; // ebp
  unsigned int v10; // eax
  unsigned int result; // eax
  unsigned int v12; // [esp+10h] [ebp+4h]

  v7 = (_DWORD *)a1[103];
  v8 = v7 + 6;
  if ( !v7[6] )
    v7[3] = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, _DWORD, int))(a1[1] + 28))(a1, v7[2], v7[5], v7[4], 1);
  v9 = *v8;
  (*(void (__cdecl **)(_DWORD *, int, int, int, _DWORD, _DWORD *, _DWORD))(a1[108] + 4))(
    a1,
    a2,
    a3,
    a4,
    v7[3],
    v7 + 6,
    v7[4]);
  v10 = *v8;
  if ( *v8 > v9 )
  {
    v12 = v10 - v9;
    (*(void (__cdecl **)(_DWORD *, unsigned int, _DWORD, unsigned int))(a1[110] + 4))(a1, v7[3] + 4 * v9, 0, v10 - v9);
    *a6 += v12;
  }
  result = v7[4];
  if ( *v8 >= result )
  {
    v7[5] += result;
    *v8 = 0;
  }
  return result;
}
