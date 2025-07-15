_DWORD *__cdecl sub_486090(_DWORD *a1)
{
  _DWORD *v1; // esi
  _DWORD *result; // eax
  int v3; // ebp
  _DWORD *v4; // ebx
  int v5; // edi
  unsigned int v6; // esi
  int v7; // edx
  _DWORD *v8; // ecx
  _DWORD *v9; // [esp+Ch] [ebp-4h]

  v1 = a1;
  result = (_DWORD *)a1[101];
  v3 = 0;
  v9 = result;
  if ( (int)a1[9] > 0 )
  {
    v4 = (_DWORD *)(a1[49] + 12);
    while ( 1 )
    {
      v5 = *v4 * v4[7] / v1[71];
      v6 = v4[9] % (unsigned int)(*v4 * v4[7]);
      if ( !v6 )
        v6 = *v4 * v4[7];
      if ( !v3 )
        v9[18] = (int)(v6 - 1) / v5 + 1;
      result = *(_DWORD **)(v9[v9[16] + 14] + 4 * v3);
      v7 = 2 * v5;
      if ( 2 * v5 > 0 )
      {
        v8 = &result[v6];
        result = v8;
        do
        {
          *result++ = *(v8 - 1);
          --v7;
        }
        while ( v7 );
      }
      ++v3;
      v4 += 22;
      if ( v3 >= a1[9] )
        break;
      v1 = a1;
    }
  }
  return result;
}
