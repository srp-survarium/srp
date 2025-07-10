unsigned __int8 *__cdecl sub_37A660(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  bool v5; // sf
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // ebp
  int v9; // ecx
  unsigned __int8 *result; // eax
  _DWORD *v11; // esi
  int v12; // edi
  _BYTE *v13; // ecx
  int v14; // esi
  int v15; // ebx
  int v16; // ebp
  int v17; // esi
  int v18; // edi
  int v19; // [esp+4h] [ebp-24h]
  int v20; // [esp+4h] [ebp-24h]
  int v21; // [esp+8h] [ebp-20h]
  int v22; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 *v23; // [esp+10h] [ebp-18h]
  int v24; // [esp+14h] [ebp-14h]
  int v25; // [esp+18h] [ebp-10h]
  int v26; // [esp+1Ch] [ebp-Ch]
  int v27; // [esp+20h] [ebp-8h]
  int v28; // [esp+24h] [ebp-4h]
  int v29; // [esp+2Ch] [ebp+4h]
  int v30; // [esp+2Ch] [ebp+4h]
  int v31; // [esp+3Ch] [ebp+14h]

  v5 = a5 - 1 < 0;
  v31 = a5 - 1;
  v6 = (_DWORD *)a1[109];
  v7 = a1[73];
  v8 = a1[23];
  v22 = v6[2];
  v26 = v6[3];
  v9 = v6[4];
  result = (unsigned __int8 *)v6[5];
  v27 = v8;
  v25 = v7;
  v24 = v9;
  v23 = result;
  if ( !v5 )
  {
    v11 = a2;
    v12 = 4 * a3;
    do
    {
      v29 = *(_DWORD *)(v12 + *v11);
      result = *(unsigned __int8 **)(v12 + v11[1]);
      v19 = *(_DWORD *)(v12 + v11[2]);
      v13 = *a4;
      v12 += 4;
      v28 = v12;
      ++a4;
      if ( v8 )
      {
        v14 = v29 - (_DWORD)result;
        v15 = v19 - (_DWORD)result;
        v21 = v29 - (_DWORD)result;
        v20 = v19 - (_DWORD)result;
        v30 = v8;
        while ( 1 )
        {
          v16 = result[v15];
          v17 = result[v14];
          v18 = *result;
          *v13 = *(_BYTE *)(v17 + *(_DWORD *)(v22 + 4 * v16) + v7);
          v7 = v25;
          v13[1] = *(_BYTE *)(v17 + ((*(_DWORD *)(v24 + 4 * v16) + *(_DWORD *)&v23[4 * v18]) >> 16) + v25);
          v13[2] = *(_BYTE *)(v17 + *(_DWORD *)(v26 + 4 * v18) + v25);
          v13 += 3;
          ++result;
          if ( !--v30 )
            break;
          v14 = v21;
          v15 = v20;
        }
        v8 = v27;
        v11 = a2;
        v12 = v28;
      }
      --v31;
    }
    while ( v31 >= 0 );
  }
  return result;
}
