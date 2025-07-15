_BYTE *__cdecl sub_487BE0(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4)
{
  _DWORD *v4; // edx
  _DWORD *v5; // eax
  int v6; // ecx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // ebx
  _BYTE *result; // eax
  int v11; // ebp
  int v12; // edx
  int v13; // esi
  int v14; // ebp
  int v15; // edx
  int v16; // ebp
  _BYTE *v17; // eax
  char v18; // bl
  int v19; // edx
  int v20; // ebx
  int v21; // edi
  int v22; // ebp
  int v23; // esi
  unsigned __int8 *v24; // [esp+10h] [ebp-14h]
  int v25; // [esp+14h] [ebp-10h]
  int v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]
  int v29; // [esp+2Ch] [ebp+8h]
  int v30; // [esp+30h] [ebp+Ch]
  unsigned __int8 *v31; // [esp+34h] [ebp+10h]

  v4 = a1;
  v5 = (_DWORD *)a1[108];
  v6 = a1[73];
  v28 = v5[4];
  v27 = v5[5];
  v26 = v5[6];
  v25 = v5[7];
  v7 = *(unsigned __int8 **)(*a2 + 4 * a3);
  v8 = *(unsigned __int8 **)(a2[1] + 4 * a3);
  v9 = *(unsigned __int8 **)(a2[2] + 4 * a3);
  result = *a4;
  v29 = a1[23] >> 1;
  if ( v29 )
  {
    do
    {
      v11 = *v9;
      v12 = *v8;
      v31 = v8 + 1;
      v24 = v9 + 1;
      v30 = *(_DWORD *)(v28 + 4 * v11);
      v13 = *(_DWORD *)(v26 + 4 * v11) + *(_DWORD *)(v25 + 4 * v12);
      v14 = *v7;
      v15 = *(_DWORD *)(v27 + 4 * v12);
      *result = *(_BYTE *)(v14 + v30 + v6);
      v13 >>= 16;
      result[1] = *(_BYTE *)(v13 + v14 + v6);
      result[2] = *(_BYTE *)(v6 + v15 + v14);
      v16 = v7[1];
      v17 = result + 3;
      *v17 = *(_BYTE *)(v16 + v30 + v6);
      v18 = *(_BYTE *)(v16 + v13 + v6);
      v8 = v31;
      v17[1] = v18;
      v9 = v24;
      v17[2] = *(_BYTE *)(v6 + v15 + v16);
      v7 += 2;
      result = v17 + 3;
      --v29;
    }
    while ( v29 );
    v4 = a1;
  }
  if ( (v4[23] & 1) != 0 )
  {
    v19 = *v8;
    v20 = *v9;
    v21 = *v7;
    v22 = *(_DWORD *)(v27 + 4 * v19);
    v23 = (*(_DWORD *)(v26 + 4 * v20) + *(_DWORD *)(v25 + 4 * v19)) >> 16;
    *result = *(_BYTE *)(v21 + *(_DWORD *)(v28 + 4 * v20) + v6);
    result[1] = *(_BYTE *)(v21 + v23 + v6);
    result[2] = *(_BYTE *)(v22 + v21 + v6);
  }
  return result;
}
