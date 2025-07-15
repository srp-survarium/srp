int __cdecl sub_488D40(_DWORD *a1, int a2, _BYTE **a3, int a4)
{
  int v4; // edx
  int v5; // esi
  int *v6; // eax
  int result; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // ebp
  unsigned __int8 *v11; // eax
  _WORD *v12; // ebx
  int v13; // esi
  int v14; // ebp
  int v15; // esi
  int v16; // edi
  int v17; // ebp
  int v18; // ecx
  int v19; // edx
  bool v20; // zf
  unsigned __int16 *v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // ebp
  int v25; // ecx
  int v26; // eax
  int v27; // edi
  __int16 v28; // dx
  int v29; // eax
  int v30; // ebp
  unsigned __int16 v31; // dx
  int v32; // [esp+8h] [ebp-60h]
  _BYTE *v33; // [esp+Ch] [ebp-5Ch]
  int v34; // [esp+10h] [ebp-58h]
  __int16 v35; // [esp+14h] [ebp-54h]
  __int16 v36; // [esp+18h] [ebp-50h]
  unsigned __int16 v37; // [esp+1Ch] [ebp-4Ch]
  _BYTE **v38; // [esp+20h] [ebp-48h]
  __int16 v39; // [esp+24h] [ebp-44h]
  __int16 v40; // [esp+28h] [ebp-40h]
  __int16 v41; // [esp+2Ch] [ebp-3Ch]
  int v42; // [esp+30h] [ebp-38h]
  int v43; // [esp+34h] [ebp-34h]
  int v44; // [esp+38h] [ebp-30h]
  int v45; // [esp+3Ch] [ebp-2Ch]
  int v46; // [esp+40h] [ebp-28h]
  int v47; // [esp+44h] [ebp-24h]
  int v48; // [esp+4Ch] [ebp-1Ch]
  unsigned __int16 *v49; // [esp+58h] [ebp-10h]
  int v50; // [esp+5Ch] [ebp-Ch]
  int v51; // [esp+60h] [ebp-8h]
  int v52; // [esp+64h] [ebp-4h]
  int v53; // [esp+78h] [ebp+10h]

  v4 = a1[23];
  v5 = a1[110];
  v48 = *(_DWORD *)(v5 + 24);
  v6 = (int *)a1[29];
  v50 = *v6;
  v51 = v6[1];
  v52 = v6[2];
  result = a4;
  v34 = a1[73];
  v8 = *(_DWORD *)(v5 + 40);
  v9 = 0;
  v46 = v5;
  v44 = v4;
  v45 = v8;
  if ( a4 > 0 )
  {
    v10 = a2 - (_DWORD)a3;
    v38 = a3;
    v47 = a4;
    while ( 1 )
    {
      v11 = *(_BYTE **)((char *)v38 + v10);
      v32 = (int)v11;
      v33 = *v38;
      if ( *(_BYTE *)(v5 + 36) )
      {
        v32 = (int)&v11[2 * v4 - 3 + v4];
        v33 = &(*v38)[v4 - 1];
        v12 = (_WORD *)(*(_DWORD *)(v5 + 32) + 2 * (3 * v4 + 3));
        v11 = (unsigned __int8 *)v32;
        v42 = -1;
        v53 = -3;
        *(_BYTE *)(v5 + 36) = 0;
      }
      else
      {
        v12 = *(_WORD **)(v5 + 32);
        v42 = 1;
        v53 = 3;
        *(_BYTE *)(v5 + 36) = 1;
      }
      v4 = v44;
      v13 = 0;
      v14 = 0;
      v41 = 0;
      v40 = 0;
      v39 = 0;
      v37 = 0;
      v36 = 0;
      v35 = 0;
      v43 = v44;
      if ( v44 )
      {
        while ( 1 )
        {
          v15 = *(unsigned __int8 *)(*v11 + *(_DWORD *)(v8 + 4 * (((__int16)v12[v53] + v13 + 8) >> 4)) + v34);
          v16 = *(unsigned __int8 *)(v11[1] + *(_DWORD *)(v8 + 4 * (((__int16)v12[v53 + 1] + v9 + 8) >> 4)) + v34);
          v17 = *(unsigned __int8 *)(v11[2] + *(_DWORD *)(v8 + 4 * (((__int16)v12[v53 + 2] + v14 + 8) >> 4)) + v34);
          v18 = (v17 >> 3) + 32 * (v16 >> 2);
          v19 = *(_DWORD *)(v48 + 4 * (v15 >> 3));
          v20 = *(_WORD *)(v19 + 2 * v18) == 0;
          v21 = (unsigned __int16 *)(v19 + 2 * v18);
          v49 = v21;
          if ( v20 )
          {
            sub_488B40((int)a1, v15 >> 3, v17 >> 3);
            v21 = v49;
          }
          v22 = *v21 - 1;
          *v33 = v22;
          v23 = v16 - *(unsigned __int8 *)(v22 + v51);
          v24 = v17 - *(unsigned __int8 *)(v22 + v52);
          v25 = v15 - *(unsigned __int8 *)(v22 + v50);
          *v12 = 3 * v25 + v35;
          v35 = 5 * v25 + v39;
          v13 = 7 * v25;
          v39 = v25;
          LOWORD(v25) = v23;
          v26 = 2 * v23;
          v23 *= 3;
          v12[1] = v23 + v36;
          v27 = v26 + v23;
          v28 = v27 + v40;
          v9 = v26 + v27;
          v29 = 2 * v24;
          v36 = v28;
          v40 = v25;
          LOWORD(v25) = v24;
          v24 *= 3;
          v12[2] = v24 + v37;
          v30 = v29 + v24;
          v31 = v30 + v41;
          v41 = v25;
          v33 += v42;
          v8 = v45;
          v14 = v29 + v30;
          v32 += v53;
          v20 = v43-- == 1;
          v37 = v31;
          v12 += v53;
          if ( v20 )
            break;
          v11 = (unsigned __int8 *)v32;
        }
        v4 = v44;
      }
      ++v38;
      v5 = v46;
      *v12 = v35;
      v12[1] = v36;
      result = v37;
      v9 = 0;
      v20 = v47-- == 1;
      v12[2] = v37;
      if ( v20 )
        break;
      v10 = a2 - (_DWORD)a3;
    }
  }
  return result;
}
