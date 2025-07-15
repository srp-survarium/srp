unsigned __int8 *__cdecl sub_37A7E0(unsigned __int8 *a1, _DWORD *a2, int a3, int *a4, int a5)
{
  bool v5; // sf
  unsigned __int8 *result; // eax
  int v7; // ebp
  _DWORD *v8; // ecx
  int v9; // edx
  int v10; // esi
  int v11; // ebx
  int v12; // edi
  int v13; // ecx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  bool v17; // zf
  int v18; // [esp+4h] [ebp-8h]
  int v19; // [esp+8h] [ebp-4h]
  int v20; // [esp+10h] [ebp+4h]
  int v21; // [esp+20h] [ebp+14h]

  v5 = a5 - 1 < 0;
  v21 = a5 - 1;
  result = a1;
  v7 = *(_DWORD *)(*((_DWORD *)a1 + 109) + 24);
  v18 = *((_DWORD *)a1 + 23);
  if ( !v5 )
  {
    v8 = a2;
    v9 = 4 * a3;
    do
    {
      v10 = *(_DWORD *)(v9 + *v8);
      v11 = *a4;
      result = *(unsigned __int8 **)(v9 + v8[1]);
      v12 = *(_DWORD *)(v9 + v8[2]);
      ++a4;
      v9 += 4;
      v19 = v9;
      if ( v18 )
      {
        v13 = v12 - (_DWORD)result;
        v14 = v10 - (_DWORD)result;
        v15 = v11 - (_DWORD)result;
        v20 = v18;
        do
        {
          v16 = *(_DWORD *)(v7 + 4 * *result + 1024)
              + *(_DWORD *)(v7 + 4 * result[v14])
              + *(_DWORD *)(v7 + 4 * result[v13] + 2048);
          ++result;
          v17 = v20-- == 1;
          result[v15 - 1] = BYTE2(v16);
        }
        while ( !v17 );
        v8 = a2;
        v9 = v19;
      }
      --v21;
    }
    while ( v21 >= 0 );
  }
  return result;
}
