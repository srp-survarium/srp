_WORD *__cdecl sub_487FD0(int a1, int a2, int a3, int a4)
{
  _WORD *result; // eax
  int v5; // ebp
  int v6; // ebx
  int i; // edi
  unsigned __int8 *v8; // ecx
  int j; // esi
  int v10; // eax
  int v11; // edx

  result = (_WORD *)a1;
  v5 = *(_DWORD *)(a1 + 92);
  v6 = 0;
  for ( i = *(_DWORD *)(*(_DWORD *)(a1 + 440) + 24); v6 < a4; ++v6 )
  {
    v8 = *(unsigned __int8 **)(a2 + 4 * v6);
    for ( j = v5; j; --j )
    {
      v10 = (v8[2] >> 3) + 32 * (v8[1] >> 2);
      v11 = *(_DWORD *)(i + 4 * (*v8 >> 3));
      ++*(_WORD *)(v11 + 2 * v10);
      result = (_WORD *)(v11 + 2 * v10);
      if ( !*result )
        *result = -1;
      v8 += 3;
    }
  }
  return result;
}
