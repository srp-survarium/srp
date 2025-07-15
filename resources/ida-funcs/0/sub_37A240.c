signed int __cdecl sub_37A240(int a1, int a2, char **a3, int *a4)
{
  int v4; // ecx
  int v5; // edx
  signed int result; // eax
  int v7; // edx
  int v8; // ebx
  char *v9; // ebp
  unsigned int v10; // esi
  unsigned int v11; // edi
  char v12; // dl
  int v13; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  unsigned __int8 *value; // [esp+Ch] [ebp-4h]
  signed int v17; // [esp+20h] [ebp+10h]

  v4 = a1;
  v13 = *a4;
  v5 = *(_DWORD *)(a1 + 432) + *(_DWORD *)(a2 + 4);
  result = *(unsigned __int8 *)(v5 + 140);
  v7 = *(unsigned __int8 *)(v5 + 150);
  v8 = 0;
  v17 = result;
  for ( i = v7; v8 < *(_DWORD *)(v4 + 276); v8 += i )
  {
    v9 = *a3;
    v10 = *(_DWORD *)(v13 + 4 * v8);
    v11 = v10 + *(_DWORD *)(v4 + 92);
    if ( v10 < v11 )
    {
      do
      {
        v12 = *v9++;
        LOBYTE(value) = v12;
        if ( result > 0 )
        {
          memset(v10, value, result);
          v4 = a1;
          result = v17;
          v10 += v17;
        }
      }
      while ( v10 < v11 );
      v7 = i;
    }
    if ( v7 > 1 )
    {
      jcopy_sample_rows(v13, v8, v13, v8 + 1, v7 - 1, *(_DWORD *)(v4 + 92));
      v4 = a1;
      result = v17;
    }
    v7 = i;
    ++a3;
  }
  return result;
}
