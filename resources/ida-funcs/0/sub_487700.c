unsigned __int8 *__cdecl sub_487700(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  bool v5; // sf
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // ecx
  unsigned __int8 *result; // eax
  _DWORD *v10; // edi
  int v11; // esi
  int v12; // ebx
  _BYTE *v13; // ecx
  int v14; // esi
  int v15; // ebx
  int v16; // ebp
  int v17; // esi
  int v18; // edi
  int v19; // [esp+0h] [ebp-28h]
  int v20; // [esp+4h] [ebp-24h]
  int v21; // [esp+4h] [ebp-24h]
  int v22; // [esp+8h] [ebp-20h]
  int v23; // [esp+Ch] [ebp-1Ch]
  int v24; // [esp+10h] [ebp-18h]
  unsigned __int8 *v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch]
  int v28; // [esp+20h] [ebp-8h]
  int v29; // [esp+24h] [ebp-4h]
  int v30; // [esp+2Ch] [ebp+4h]
  int v31; // [esp+2Ch] [ebp+4h]
  int v32; // [esp+3Ch] [ebp+14h]

  v5 = a5 - 1 < 0;
  v32 = a5 - 1;
  v6 = (_DWORD *)a1[109];
  v19 = a1[23];
  v7 = a1[73];
  v24 = v6[2];
  v28 = v6[3];
  v8 = v6[4];
  result = (unsigned __int8 *)v6[5];
  v27 = v7;
  v26 = v8;
  v25 = result;
  if ( !v5 )
  {
    v10 = a2;
    v11 = 4 * a3;
    do
    {
      v12 = *(_DWORD *)(v11 + *v10);
      result = *(unsigned __int8 **)(v11 + v10[1]);
      v30 = *(_DWORD *)(v11 + v10[2]);
      v20 = *(_DWORD *)(v11 + v10[3]);
      v13 = *a4++;
      v11 += 4;
      v29 = v11;
      if ( v19 )
      {
        v14 = v12 - (_DWORD)result;
        v15 = v30 - (_DWORD)result;
        v22 = v14;
        v23 = v30 - (_DWORD)result;
        v21 = v20 - (_DWORD)result;
        v31 = v19;
        while ( 1 )
        {
          v16 = result[v15];
          v17 = result[v14];
          v18 = *result;
          *v13 = *(_BYTE *)(v7 - *(_DWORD *)(v24 + 4 * v16) - v17 + 255);
          v7 = v27;
          v13[1] = *(_BYTE *)(v27 - ((*(_DWORD *)(v26 + 4 * v16) + *(_DWORD *)&v25[4 * v18]) >> 16) - v17 + 255);
          v13 += 4;
          *(v13 - 2) = *(_BYTE *)(v27 - *(_DWORD *)(v28 + 4 * v18) - v17 + 255);
          *(v13 - 1) = (result++)[v21];
          if ( !--v31 )
            break;
          v14 = v22;
          v15 = v23;
        }
        v10 = a2;
        v11 = v29;
      }
      --v32;
    }
    while ( v32 >= 0 );
  }
  return result;
}
