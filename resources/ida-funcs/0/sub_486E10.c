int __cdecl sub_486E10(_DWORD *a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6, int a7)
{
  int v8; // ebp
  int v9; // ebx
  bool v10; // cc
  int v11; // esi
  unsigned int v12; // esi
  int result; // eax
  int v14; // [esp+14h] [ebp+4h]

  v8 = a1[108];
  if ( *(_DWORD *)(v8 + 92) >= a1[69] )
  {
    v9 = 0;
    v10 = a1[9] <= 0;
    v14 = a1[49];
    if ( !v10 )
    {
      v11 = v8 + 12;
      do
      {
        (*(void (__cdecl **)(_DWORD *, int, int, int))(v11 + 40))(
          a1,
          v14,
          *(_DWORD *)(a2 + 4 * v9) + 4 * *a3 * *(_DWORD *)(v11 + 88),
          v11);
        v14 += 88;
        ++v9;
        v11 += 4;
      }
      while ( v9 < a1[9] );
    }
    *(_DWORD *)(v8 + 92) = 0;
  }
  v12 = a1[69] - *(_DWORD *)(v8 + 92);
  if ( v12 > *(_DWORD *)(v8 + 96) )
    v12 = *(_DWORD *)(v8 + 96);
  if ( v12 > a7 - *a6 )
    v12 = a7 - *a6;
  result = (*(int (__cdecl **)(_DWORD *, int, _DWORD, int, unsigned int))(a1[109] + 4))(
             a1,
             v8 + 12,
             *(_DWORD *)(v8 + 92),
             a5 + 4 * *a6,
             v12);
  *a6 += v12;
  *(_DWORD *)(v8 + 96) -= v12;
  *(_DWORD *)(v8 + 92) += v12;
  if ( *(_DWORD *)(v8 + 92) >= a1[69] )
  {
    result = (int)a3;
    ++*a3;
  }
  return result;
}
