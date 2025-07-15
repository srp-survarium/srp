_BYTE *__cdecl sub_4876A0(int a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  bool v5; // sf
  _BYTE *result; // eax
  unsigned int v7; // edi
  int v9; // ebp
  int v10; // esi
  unsigned int i; // edx
  char v12; // cl
  int v13; // [esp+18h] [ebp+14h]

  v5 = a5 - 1 < 0;
  v13 = a5 - 1;
  result = (_BYTE *)a1;
  v7 = *(_DWORD *)(a1 + 92);
  if ( !v5 )
  {
    v9 = 4 * a3;
    do
    {
      v10 = *(_DWORD *)(*a2 + v9);
      result = *a4;
      v9 += 4;
      ++a4;
      for ( i = 0; i < v7; result += 3 )
      {
        v12 = *(_BYTE *)(i + v10);
        result[2] = v12;
        result[1] = v12;
        *result = v12;
        ++i;
      }
      --v13;
    }
    while ( v13 >= 0 );
  }
  return result;
}
