int __cdecl sub_4880B0(int *a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // ebx
  int v4; // ebp
  int v5; // esi
  int v6; // edi
  int v7; // esi
  int v8; // edx
  _WORD *v9; // ecx
  int v10; // eax
  int v12; // eax
  int v13; // edx
  _WORD *v14; // ecx
  int v15; // eax
  int v17; // esi
  _WORD *v18; // eax
  int v19; // ecx
  int v21; // esi
  _WORD *v22; // eax
  int v23; // ecx
  int v25; // eax
  int v26; // edx
  int v27; // esi
  _WORD *v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  int v32; // esi
  _WORD *v33; // eax
  int v34; // ecx
  int v35; // edi
  int result; // eax
  int v37; // ebp
  int v38; // edx
  _WORD *v39; // eax
  int v40; // ecx
  int v41; // [esp+10h] [ebp-1Ch]
  int v42; // [esp+14h] [ebp-18h]
  int v43; // [esp+18h] [ebp-14h]
  int v44; // [esp+18h] [ebp-14h]
  int v45; // [esp+1Ch] [ebp-10h]
  int v46; // [esp+20h] [ebp-Ch]
  int v47; // [esp+20h] [ebp-Ch]
  int v48; // [esp+20h] [ebp-Ch]
  int v49; // [esp+20h] [ebp-Ch]
  int v50; // [esp+20h] [ebp-Ch]
  int v51; // [esp+20h] [ebp-Ch]
  int v52; // [esp+24h] [ebp-8h]
  int v53; // [esp+28h] [ebp-4h]

  v2 = *a1;
  v3 = a1[4];
  v4 = a1[5];
  v5 = a1[2];
  v52 = *(_DWORD *)(*(_DWORD *)(v1 + 440) + 24);
  v43 = *a1;
  v42 = a1[1];
  v41 = v5;
  v45 = a1[3];
  v53 = v4;
  if ( *a1 < v42 )
  {
    v6 = *a1;
    while ( 1 )
    {
      v7 = a1[2];
      if ( v41 <= v45 )
        break;
LABEL_9:
      if ( ++v6 > v42 )
        goto LABEL_12;
    }
    v8 = *(_DWORD *)(v52 + 4 * v6) + 2 * (v3 + 32 * v41);
    while ( 1 )
    {
      v9 = (_WORD *)v8;
      v10 = v3;
      if ( a1[4] <= v4 )
        break;
LABEL_8:
      v3 = a1[4];
      ++v7;
      v8 += 64;
      if ( v7 > v45 )
        goto LABEL_9;
    }
    while ( !*v9++ )
    {
      if ( ++v10 > v4 )
        goto LABEL_8;
    }
    v3 = a1[4];
    v43 = v6;
    *a1 = v6;
LABEL_12:
    v2 = v43;
    v12 = v42;
    v5 = v41;
    if ( v42 > v43 )
    {
      v46 = v42;
      while ( v5 > v45 )
      {
LABEL_21:
        v2 = v43;
        v5 = v41;
        v46 = --v12;
        if ( v12 < v43 )
          goto LABEL_24;
      }
      v13 = *(_DWORD *)(v52 + 4 * v12) + 2 * (v3 + 32 * v5);
      while ( 1 )
      {
        v14 = (_WORD *)v13;
        v15 = v3;
        if ( v3 <= v4 )
          break;
LABEL_19:
        ++v5;
        v13 += 64;
        if ( v5 > v45 )
        {
          v12 = v46;
          goto LABEL_21;
        }
      }
      while ( !*v14++ )
      {
        if ( ++v15 > v4 )
          goto LABEL_19;
      }
      v2 = v43;
      v5 = v41;
      v42 = v46;
      a1[1] = v46;
    }
  }
LABEL_24:
  if ( v5 < v45 )
  {
    v47 = v5;
    v17 = 2 * (v3 + 32 * v5);
    while ( v2 > v42 )
    {
LABEL_31:
      v2 = v43;
      v17 += 64;
      if ( ++v47 > v45 )
        goto LABEL_34;
    }
    while ( 1 )
    {
      v18 = (_WORD *)(v17 + *(_DWORD *)(v52 + 4 * v2));
      v19 = v3;
      if ( v3 <= v4 )
        break;
LABEL_30:
      if ( ++v2 > v42 )
        goto LABEL_31;
    }
    while ( !*v18++ )
    {
      if ( ++v19 > v4 )
        goto LABEL_30;
    }
    v2 = v43;
    v41 = v47;
    a1[2] = v47;
LABEL_34:
    if ( v45 > v41 )
    {
      v48 = v45;
      v21 = 2 * (v3 + 32 * v45);
      while ( v2 > v42 )
      {
LABEL_42:
        v21 -= 64;
        if ( --v48 < v41 )
          goto LABEL_45;
        v2 = v43;
      }
      while ( 1 )
      {
        v22 = (_WORD *)(v21 + *(_DWORD *)(v52 + 4 * v2));
        v23 = v3;
        if ( v3 <= v4 )
          break;
LABEL_41:
        if ( ++v2 > v42 )
          goto LABEL_42;
      }
      while ( !*v22++ )
      {
        if ( ++v23 > v4 )
          goto LABEL_41;
      }
      v45 = v48;
      a1[3] = v48;
    }
  }
LABEL_45:
  if ( v3 < v4 )
  {
    v25 = v3;
    v49 = v3;
    while ( 1 )
    {
      v26 = v43;
      if ( v43 <= v42 )
        break;
LABEL_54:
      v49 = ++v25;
      if ( v25 > v4 )
        goto LABEL_57;
    }
    v27 = 2 * (v25 + 32 * v41);
    while ( 1 )
    {
      v28 = (_WORD *)(v27 + *(_DWORD *)(v52 + 4 * v26));
      v29 = v41;
      if ( v41 <= v45 )
        break;
LABEL_52:
      if ( ++v26 > v42 )
      {
        v4 = v53;
        v25 = v49;
        goto LABEL_54;
      }
    }
    while ( !*v28 )
    {
      ++v29;
      v28 += 32;
      if ( v29 > v45 )
        goto LABEL_52;
    }
    v3 = v49;
    v4 = v53;
    a1[4] = v49;
LABEL_57:
    if ( v4 > v3 )
    {
      v30 = v4;
      v50 = v4;
      while ( 1 )
      {
        v31 = v43;
        if ( v43 <= v42 )
          break;
LABEL_66:
        v50 = --v30;
        if ( v30 < v3 )
          goto LABEL_69;
      }
      v32 = 2 * (v30 + 32 * v41);
      while ( 1 )
      {
        v33 = (_WORD *)(v32 + *(_DWORD *)(v52 + 4 * v31));
        v34 = v41;
        if ( v41 <= v45 )
          break;
LABEL_64:
        if ( ++v31 > v42 )
        {
          v4 = v53;
          v30 = v50;
          goto LABEL_66;
        }
      }
      while ( !*v33 )
      {
        ++v34;
        v33 += 32;
        if ( v34 > v45 )
          goto LABEL_64;
      }
      v4 = v50;
      v53 = v50;
      a1[5] = v50;
    }
  }
LABEL_69:
  v35 = v4 - v3;
  result = v43;
  a1[6] = 16 * (v42 - v43) * 16 * (v42 - v43) + 12 * (v45 - v41) * 12 * (v45 - v41) + 8 * (v4 - v3) * 8 * (v4 - v3);
  v37 = 0;
  v51 = v43;
  if ( v43 > v42 )
  {
    a1[7] = 0;
  }
  else
  {
    do
    {
      if ( v41 <= v45 )
      {
        v38 = *(_DWORD *)(v52 + 4 * v51) + 2 * (v3 + 32 * v41);
        v44 = v45 - v41 + 1;
        do
        {
          v39 = (_WORD *)v38;
          if ( v3 <= v53 )
          {
            v40 = v35 + 1;
            do
            {
              if ( *v39 )
                ++v37;
              ++v39;
              --v40;
            }
            while ( v40 );
          }
          v38 += 64;
          --v44;
        }
        while ( v44 );
      }
      result = ++v51;
    }
    while ( v51 <= v42 );
    a1[7] = v37;
  }
  return result;
}
