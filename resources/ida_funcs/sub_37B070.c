int __cdecl sub_37B070(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  _DWORD *v5; // ecx
  int result; // eax
  unsigned __int8 **v8; // edx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // edi
  _BYTE *v12; // ecx
  _BYTE *v13; // esi
  unsigned __int8 *v14; // edi
  int v15; // edx
  int v16; // ebp
  int v17; // edi
  int v18; // edx
  _BYTE *v19; // ecx
  int v20; // ebx
  _BYTE *v21; // esi
  bool v22; // zf
  int v23; // ebx
  int v24; // edx
  int v25; // edi
  int v26; // edx
  int v27; // ebp
  int v28; // ecx
  unsigned __int8 *v29; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *v30; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *v31; // [esp+14h] [ebp-18h]
  unsigned __int8 *v32; // [esp+18h] [ebp-14h]
  int v33; // [esp+1Ch] [ebp-10h]
  int v34; // [esp+20h] [ebp-Ch]
  int v35; // [esp+24h] [ebp-8h]
  int v36; // [esp+28h] [ebp-4h]
  int v37; // [esp+30h] [ebp+4h]
  int v38; // [esp+34h] [ebp+8h]
  int v39; // [esp+34h] [ebp+8h]
  int v40; // [esp+34h] [ebp+8h]
  int v41; // [esp+34h] [ebp+8h]
  unsigned __int8 *v42; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v43; // [esp+38h] [ebp+Ch]
  int v44; // [esp+3Ch] [ebp+10h]

  v4 = a1;
  v5 = (_DWORD *)a1[108];
  result = a1[73];
  v33 = v5[4];
  v36 = v5[5];
  v35 = v5[6];
  v34 = v5[7];
  v8 = (unsigned __int8 **)(*a2 + 8 * a3);
  v9 = *v8;
  v29 = v8[1];
  v10 = *(unsigned __int8 **)(a2[1] + 4 * a3);
  v42 = v9;
  v11 = *(unsigned __int8 **)(a2[2] + 4 * a3);
  v12 = *(_BYTE **)a4;
  v13 = *(_BYTE **)(a4 + 4);
  v44 = a1[23] >> 1;
  if ( v44 )
  {
    do
    {
      v38 = *v10;
      v14 = v11 + 1;
      v31 = v10 + 1;
      v15 = *(v14 - 1);
      v32 = v14;
      v16 = *(_DWORD *)(v33 + 4 * v15);
      v17 = *(_DWORD *)(v35 + 4 * v15) + *(_DWORD *)(v34 + 4 * v38);
      v18 = *(_DWORD *)(v36 + 4 * v38);
      v39 = *v42;
      *v12 = *(_BYTE *)(v16 + v39 + result);
      v43 = v42 + 1;
      v17 >>= 16;
      v12[1] = *(_BYTE *)(v17 + v39 + result);
      v12[2] = *(_BYTE *)(v18 + v39 + result);
      v40 = *v43;
      v12[3] = *(_BYTE *)(v16 + v40 + result);
      v12[4] = *(_BYTE *)(v17 + v40 + result);
      v19 = v12 + 3;
      v19[2] = *(_BYTE *)(v18 + v40 + result);
      v41 = *v29;
      *v13 = *(_BYTE *)(v16 + v41 + result);
      v30 = v29 + 1;
      v13[1] = *(_BYTE *)(v17 + v41 + result);
      v13[2] = *(_BYTE *)(v18 + v41 + result);
      v20 = *v30;
      v42 = v43 + 1;
      v29 = v30 + 1;
      v21 = v13 + 3;
      *v21 = *(_BYTE *)(v16 + v20 + result);
      v21[1] = *(_BYTE *)(v17 + v20 + result);
      v12 = v19 + 3;
      v21[2] = *(_BYTE *)(v18 + v20 + result);
      v13 = v21 + 3;
      v22 = v44-- == 1;
      v10 = v31;
      v11 = v32;
    }
    while ( !v22 );
    v4 = a1;
  }
  if ( (v4[23] & 1) != 0 )
  {
    v23 = *v11;
    v24 = *v10;
    v37 = *(_DWORD *)(v33 + 4 * v23);
    v25 = *(_DWORD *)(v35 + 4 * v23) + *(_DWORD *)(v34 + 4 * v24);
    v26 = *(_DWORD *)(v36 + 4 * v24);
    v27 = *v42;
    *v12 = *(_BYTE *)(v27 + v37 + result);
    v25 >>= 16;
    v12[1] = *(_BYTE *)(v25 + v27 + result);
    v12[2] = *(_BYTE *)(result + v26 + v27);
    v28 = *v29;
    *v13 = *(_BYTE *)(v28 + v37 + result);
    v13[1] = *(_BYTE *)(v28 + v25 + result);
    v13[2] = *(_BYTE *)(v26 + v28 + result);
  }
  return result;
}
