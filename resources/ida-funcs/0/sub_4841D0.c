char __cdecl sub_4841D0(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // ebx
  char result; // al
  bool v5; // cc
  int v6; // eax
  unsigned __int8 *v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // edi
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int *v16; // ebp
  int v17; // esi
  int v18; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // ebx
  int v22; // ebp
  int v23; // esi
  int v24; // esi
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int v28; // edx
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ebx
  int v33; // esi
  int v34; // edx
  int v35; // esi
  int v36; // edx
  int v37; // edx
  int v38; // ecx
  int v39; // ebx
  int v40; // ecx
  int v41; // ebx
  int v42; // esi
  int v43; // ecx
  int v44; // edx
  int v45; // eax
  int v46; // ecx
  int v47; // [esp+8h] [ebp-44h]
  int *i; // [esp+Ch] [ebp-40h]
  int v49; // [esp+10h] [ebp-3Ch]
  int *v50; // [esp+14h] [ebp-38h]
  _WORD *v51; // [esp+18h] [ebp-34h]
  int v52; // [esp+1Ch] [ebp-30h]
  int v53; // [esp+20h] [ebp-2Ch]
  unsigned __int8 *v54; // [esp+24h] [ebp-28h] BYREF
  int v55; // [esp+28h] [ebp-24h]
  int v56; // [esp+2Ch] [ebp-20h]
  int v57; // [esp+30h] [ebp-1Ch]
  _DWORD *v58; // [esp+34h] [ebp-18h]
  int v59; // [esp+38h] [ebp-14h]
  int v60; // [esp+3Ch] [ebp-10h]
  int v61; // [esp+40h] [ebp-Ch]
  int v62; // [esp+44h] [ebp-8h]
  int v63; // [esp+48h] [ebp-4h]

  v2 = a1;
  v3 = a1[106];
  v53 = v3;
  if ( a1[63] )
  {
    if ( !*(_DWORD *)(v3 + 40) )
    {
      result = sub_4833D0(a1);
      if ( !result )
        return result;
    }
  }
  if ( *(_BYTE *)(v3 + 36) )
    goto LABEL_71;
  v5 = a1[81] <= 0;
  v6 = a1[6];
  v7 = *(unsigned __int8 **)v6;
  v8 = *(_DWORD *)(v6 + 4);
  v9 = *(_DWORD *)(v3 + 8);
  v10 = *(_DWORD *)(v3 + 12);
  v54 = v7;
  v11 = *(_DWORD *)(v3 + 16);
  v55 = v8;
  v12 = *(_DWORD *)(v3 + 20);
  v59 = v11;
  v13 = *(_DWORD *)(v3 + 24);
  v60 = v12;
  v14 = *(_DWORD *)(v3 + 28);
  v61 = v13;
  v15 = *(_DWORD *)(v3 + 32);
  v58 = a1;
  v62 = v14;
  v63 = v15;
  v49 = 0;
  if ( v5 )
    goto LABEL_70;
  v16 = (int *)(v3 + 136);
  v50 = a1 + 82;
  for ( i = (int *)(v3 + 136); ; v16 = i )
  {
    v17 = *(v16 - 10);
    v51 = *(_WORD **)(a2 + 4 * v49);
    if ( v10 >= 8 )
      goto LABEL_12;
    if ( !sub_4831F0(&v54, v9, v10, 0) )
      return 0;
    v10 = v57;
    v9 = v56;
    if ( v57 >= 8 )
    {
LABEL_12:
      v19 = (unsigned __int8)(v9 >> (v10 - 8));
      v20 = *(_DWORD *)(v17 + 4 * v19 + 144);
      if ( v20 )
      {
        v21 = *(unsigned __int8 *)(v19 + v17 + 1168);
        v10 -= v20;
        goto LABEL_17;
      }
      v18 = 9;
    }
    else
    {
      v18 = 1;
    }
    v21 = sub_483310(v9, v18, v10, (int)&v54, v17);
    if ( v21 < 0 )
      return 0;
    v9 = v56;
    v10 = v57;
LABEL_17:
    v22 = *v16;
    v23 = 1;
    v52 = i[10];
    if ( !v52 )
    {
      if ( !v21 )
        goto LABEL_46;
      if ( v10 < v21 )
      {
        if ( !sub_4831F0(&v54, v9, v10, v21) )
          return 0;
        v9 = v56;
        v10 = v57;
      }
      v10 -= v21;
      while ( 1 )
      {
LABEL_46:
        if ( v10 >= 8 )
          goto LABEL_55;
        if ( !sub_4831F0(&v54, v9, v10, 0) )
          return 0;
        v10 = v57;
        v9 = v56;
        if ( v57 >= 8 )
        {
LABEL_55:
          v37 = (unsigned __int8)(v9 >> (v10 - 8));
          v38 = *(_DWORD *)(v22 + 4 * v37 + 144);
          if ( v38 )
          {
            v39 = *(unsigned __int8 *)(v37 + v22 + 1168);
            v10 -= v38;
            goto LABEL_60;
          }
          v36 = 9;
        }
        else
        {
          v36 = 1;
        }
        v39 = sub_483310(v9, v36, v10, (int)&v54, v22);
        if ( v39 < 0 )
          return 0;
        v9 = v56;
        v10 = v57;
LABEL_60:
        v40 = v39 >> 4;
        v41 = v39 & 0xF;
        if ( v41 )
        {
          v42 = v40 + v23;
          if ( v10 < v41 )
          {
            if ( !sub_4831F0(&v54, v9, v10, v41) )
              return 0;
            v9 = v56;
            v10 = v57;
          }
          v10 -= v41;
        }
        else
        {
          if ( v40 != 15 )
            goto LABEL_68;
          v42 = v23 + 15;
        }
        v23 = v42 + 1;
        if ( v23 >= 64 )
          goto LABEL_68;
      }
    }
    if ( v21 )
    {
      if ( v10 < v21 )
      {
        if ( !sub_4831F0(&v54, v9, v10, v21) )
          return 0;
        v9 = v56;
        v10 = v57;
      }
      v24 = dword_6F62A0[v21];
      v10 -= v21;
      v25 = v24 & (v9 >> v10);
      if ( v25 <= dword_6F629C[v21] )
        v25 -= v24;
      v23 = 1;
      v21 = v25;
    }
    v26 = *v50;
    *(&v60 + v26) += v21;
    *v51 = *(&v60 + v26);
    if ( v52 <= 1 )
      goto LABEL_46;
    do
    {
      if ( v10 >= 8 )
        goto LABEL_30;
      if ( !sub_4831F0(&v54, v9, v10, 0) )
        return 0;
      v10 = v57;
      v9 = v56;
      if ( v57 >= 8 )
      {
LABEL_30:
        v28 = (unsigned __int8)(v9 >> (v10 - 8));
        v29 = *(_DWORD *)(v22 + 4 * v28 + 144);
        if ( v29 )
        {
          v30 = *(unsigned __int8 *)(v28 + v22 + 1168);
          v10 -= v29;
          goto LABEL_35;
        }
        v27 = 9;
      }
      else
      {
        v27 = 1;
      }
      v30 = sub_483310(v9, v27, v10, (int)&v54, v22);
      if ( v30 < 0 )
        return 0;
      v9 = v56;
      v10 = v57;
LABEL_35:
      v31 = v30 >> 4;
      v32 = v30 & 0xF;
      if ( v32 )
      {
        v47 = v31 + v23;
        if ( v10 < v32 )
        {
          if ( !sub_4831F0(&v54, v9, v10, v32) )
            return 0;
          v9 = v56;
          v10 = v57;
        }
        v33 = dword_6F62A0[v32];
        v10 -= v32;
        v34 = v33 & (v9 >> v10);
        if ( v34 <= dword_6F629C[v32] )
          LOWORD(v34) = v34 - v33;
        v51[jpeg_natural_order[v47]] = v34;
        v35 = v47;
      }
      else
      {
        if ( v31 != 15 )
          goto LABEL_68;
        v35 = v23 + 15;
      }
      v23 = v35 + 1;
    }
    while ( v23 < v52 );
    if ( v23 < 64 )
      goto LABEL_46;
LABEL_68:
    ++i;
    ++v50;
    if ( ++v49 >= a1[81] )
      break;
  }
  v3 = v53;
  v2 = a1;
LABEL_70:
  *(_DWORD *)v2[6] = v54;
  *(_DWORD *)(v2[6] + 4) = v55;
  v43 = v60;
  v44 = v61;
  *(_DWORD *)(v3 + 8) = v9;
  *(_DWORD *)(v3 + 16) = v59;
  v45 = v62;
  *(_DWORD *)(v3 + 20) = v43;
  v46 = v63;
  *(_DWORD *)(v3 + 24) = v44;
  *(_DWORD *)(v3 + 28) = v45;
  *(_DWORD *)(v3 + 12) = v10;
  *(_DWORD *)(v3 + 32) = v46;
LABEL_71:
  --*(_DWORD *)(v3 + 40);
  return 1;
}
