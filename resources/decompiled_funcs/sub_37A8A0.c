_BYTE *__cdecl sub_37A8A0(int a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  bool v5; // sf
  _BYTE *result; // eax
  _DWORD *v7; // ebx
  int v8; // ebp
  int v9; // esi
  int v10; // edi
  _BYTE *v11; // ecx
  int v12; // edx
  int v13; // esi
  int v14; // edi
  int v15; // [esp+4h] [ebp+4h]
  int v16; // [esp+14h] [ebp+14h]

  v5 = a5 - 1 < 0;
  v16 = a5 - 1;
  result = (_BYTE *)a1;
  v15 = *(_DWORD *)(a1 + 92);
  if ( !v5 )
  {
    v7 = a2;
    v8 = 4 * a3;
    do
    {
      v9 = *(_DWORD *)(*v7 + v8);
      v10 = *(_DWORD *)(v7[2] + v8);
      v11 = *a4;
      result = *(_BYTE **)(v7[1] + v8);
      ++a4;
      v12 = v15;
      v8 += 4;
      if ( v15 )
      {
        v13 = v9 - (_DWORD)result;
        v14 = v10 - (_DWORD)result;
        do
        {
          *v11 = result[v13];
          v11[1] = *result;
          v11[2] = result[v14];
          v11 += 3;
          ++result;
          --v12;
        }
        while ( v12 );
        v7 = a2;
      }
      --v16;
    }
    while ( v16 >= 0 );
  }
  return result;
}
