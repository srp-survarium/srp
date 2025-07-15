char __cdecl sub_483980(_DWORD *a1, int *a2)
{
  _DWORD *v2; // ebp
  int v3; // ebx
  char result; // al
  int v5; // ecx
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  unsigned __int8 *v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // ebp
  int v21; // ebx
  int v22; // ebp
  int v23; // edx
  __int16 *v24; // ebx
  __int16 v25; // ax
  __int16 v26; // ax
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  __int16 *v30; // ebx
  __int16 v31; // ax
  __int16 v32; // ax
  int i; // eax
  int v34; // edx
  int v35; // [esp+Ch] [ebp-140h]
  int v36; // [esp+10h] [ebp-13Ch]
  int v37; // [esp+14h] [ebp-138h]
  int v38; // [esp+18h] [ebp-134h]
  int v39; // [esp+1Ch] [ebp-130h]
  int v40; // [esp+20h] [ebp-12Ch]
  unsigned __int8 *v41; // [esp+24h] [ebp-128h] BYREF
  int v42; // [esp+28h] [ebp-124h]
  int v43; // [esp+2Ch] [ebp-120h]
  int v44; // [esp+30h] [ebp-11Ch]
  _DWORD *v45; // [esp+34h] [ebp-118h]
  int v46; // [esp+38h] [ebp-114h]
  int v47; // [esp+3Ch] [ebp-110h]
  int v48; // [esp+40h] [ebp-10Ch]
  int v49; // [esp+44h] [ebp-108h]
  int v50[65]; // [esp+48h] [ebp-104h]

  v2 = a1;
  v3 = a1[106];
  v39 = v3;
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
  {
LABEL_64:
    --*(_DWORD *)(v3 + 40);
    return 1;
  }
  v5 = a1[95];
  v6 = *(_DWORD *)(v3 + 8);
  v7 = *(_DWORD *)(v3 + 12);
  v37 = a1[93];
  v8 = -1 << v5;
  v9 = 1 << v5;
  v10 = a1[97];
  v47 = v8;
  v11 = a1[6];
  v46 = v10;
  v12 = *(unsigned __int8 **)v11;
  v13 = *(_DWORD *)(v11 + 4);
  v41 = v12;
  v40 = *a2;
  v14 = *(_DWORD *)(v3 + 60);
  v42 = v13;
  v15 = *(_DWORD *)(v3 + 16);
  v50[0] = v14;
  v16 = a1[92];
  v38 = v9;
  v45 = a1;
  v36 = v15;
  v48 = 0;
  v35 = v16;
  if ( v15 )
  {
LABEL_48:
    if ( v36 )
    {
      v29 = v35;
      if ( v35 <= v37 )
      {
        do
        {
          v30 = (__int16 *)(v40 + 2 * *(_DWORD *)(v46 + 4 * v29));
          if ( *v30 )
          {
            if ( v7 < 1 )
            {
              if ( !sub_4831F0(&v41, v6, v7, 1) )
                goto LABEL_65;
              v6 = v43;
              v7 = v44;
              v9 = v38;
            }
            if ( ((v6 >> --v7) & 1) != 0 )
            {
              v31 = *v30;
              if ( (*v30 & v9) == 0 )
              {
                if ( v31 < 0 )
                  v32 = v47 + v31;
                else
                  v32 = v9 + v31;
                *v30 = v32;
              }
            }
          }
          v29 = ++v35;
        }
        while ( v35 <= v37 );
        v3 = v39;
      }
      --v36;
    }
    goto LABEL_63;
  }
  if ( v16 > v37 )
  {
LABEL_63:
    *(_DWORD *)v2[6] = v41;
    *(_DWORD *)(v2[6] + 4) = v42;
    *(_DWORD *)(v3 + 8) = v6;
    *(_DWORD *)(v3 + 12) = v7;
    *(_DWORD *)(v3 + 16) = v36;
    goto LABEL_64;
  }
  while ( 1 )
  {
    if ( v7 >= 8 )
      goto LABEL_11;
    if ( !sub_4831F0(&v41, v6, v7, 0) )
      goto LABEL_65;
    v7 = v44;
    v6 = v43;
    if ( v44 >= 8 )
    {
LABEL_11:
      v18 = (unsigned __int8)(v6 >> (v7 - 8));
      v19 = *(_DWORD *)(v50[0] + 4 * v18 + 144);
      if ( v19 )
      {
        v20 = *(unsigned __int8 *)(v18 + v50[0] + 1168);
        v7 -= v19;
        goto LABEL_16;
      }
      v17 = 9;
    }
    else
    {
      v17 = 1;
    }
    v20 = sub_483310(v6, v17, v7, (int)&v41, v50[0]);
    if ( v20 < 0 )
      goto LABEL_65;
    v6 = v43;
    v7 = v44;
LABEL_16:
    v21 = v20 >> 4;
    v22 = v20 & 0xF;
    v49 = v21;
    if ( !v22 )
      break;
    if ( v22 != 1 )
    {
      *(_DWORD *)(*a1 + 20) = 121;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
    }
    if ( v7 < 1 )
    {
      if ( !sub_4831F0(&v41, v6, v7, 1) )
        goto LABEL_65;
      v6 = v43;
      v7 = v44;
    }
    if ( ((v6 >> --v7) & 1) != 0 )
      v22 = v38;
    else
      v22 = v47;
    do
    {
LABEL_26:
      v23 = v35;
      v24 = (__int16 *)(v40 + 2 * *(_DWORD *)(v46 + 4 * v35));
      if ( *v24 )
      {
        if ( v7 < 1 )
        {
          if ( !sub_4831F0(&v41, v6, v7, 1) )
            goto LABEL_65;
          v6 = v43;
          v7 = v44;
        }
        if ( ((v6 >> --v7) & 1) != 0 )
        {
          v25 = *v24;
          if ( (*v24 & v38) == 0 )
          {
            if ( v25 < 0 )
              v26 = v47 + v25;
            else
              v26 = v38 + v25;
            *v24 = v26;
          }
        }
      }
      else if ( --v49 < 0 )
      {
        break;
      }
      v23 = ++v35;
    }
    while ( v35 <= v37 );
    if ( v22 )
    {
      v27 = *(_DWORD *)(v46 + 4 * v23);
      *(_WORD *)(v40 + 2 * v27) = v22;
      v28 = v48;
      v50[v48 + 1] = v27;
      v48 = v28 + 1;
    }
    v35 = v23 + 1;
    if ( v23 + 1 > v37 )
    {
      v2 = a1;
      v3 = v39;
      goto LABEL_63;
    }
  }
  if ( v21 == 15 )
    goto LABEL_26;
  v36 = 1 << v21;
  if ( !v21 )
    goto LABEL_47;
  if ( v7 >= v21 )
    goto LABEL_46;
  if ( sub_4831F0(&v41, v6, v7, v21) )
  {
    v6 = v43;
    v7 = v44;
LABEL_46:
    v7 -= v21;
    v36 = (dword_6F62A0[v21] & (v6 >> v7)) + (1 << v21);
LABEL_47:
    v3 = v39;
    v9 = v38;
    v2 = a1;
    goto LABEL_48;
  }
LABEL_65:
  for ( i = v48; i > 0; *(_WORD *)(v40 + 2 * v34) = 0 )
    v34 = v50[i--];
  return 0;
}
