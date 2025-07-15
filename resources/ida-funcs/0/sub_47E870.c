char __cdecl sub_47E870(_DWORD *a1)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v5; // esi
  int v6; // eax
  unsigned __int8 *v7; // ebx
  int v8; // eax
  unsigned __int8 *v9; // esi
  unsigned __int8 *v10; // ebx
  unsigned int v11; // eax
  unsigned __int8 *v12; // esi
  int i; // edi
  int v14; // edx
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int j; // edi
  unsigned int v32; // eax
  int v33; // esi
  int v34; // eax
  int v35; // ecx
  int v36; // edx
  int v37; // ecx
  unsigned __int8 *v38; // [esp+10h] [ebp-12Ch]
  int v39; // [esp+14h] [ebp-128h]
  int v40; // [esp+14h] [ebp-128h]
  int v41; // [esp+14h] [ebp-128h]
  int v42; // [esp+18h] [ebp-124h]
  unsigned __int8 **v43; // [esp+1Ch] [ebp-120h]
  unsigned int v44; // [esp+20h] [ebp-11Ch]
  int v45; // [esp+24h] [ebp-118h]
  int v46; // [esp+28h] [ebp-114h]
  int v47; // [esp+2Ch] [ebp-110h]
  int v48; // [esp+30h] [ebp-10Ch]
  unsigned __int8 v49; // [esp+34h] [ebp-108h]
  _BYTE v50[256]; // [esp+38h] [ebp-104h] BYREF

  v1 = (unsigned __int8 **)a1[6];
  v2 = v1[1];
  v3 = *v1;
  v43 = v1;
  if ( !v2 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v3 = *v1;
    v2 = v1[1];
  }
  v5 = v2 - 1;
  v6 = *v3 << 8;
  v7 = v3 + 1;
  v39 = v6;
  if ( !v5 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v7 = *v1;
    v5 = v1[1];
    v6 = v39;
  }
  v8 = *v7 + v6 - 2;
  v9 = v5 - 1;
  v10 = v7 + 1;
  v40 = v8;
  if ( v8 > 16 )
  {
    do
    {
      if ( !v9 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
          return 0;
        v10 = *v1;
        v9 = v1[1];
      }
      v11 = *v10;
      *(_DWORD *)(*a1 + 20) = 82;
      *(_DWORD *)(*a1 + 24) = v11;
      v44 = v11;
      v12 = v9 - 1;
      ++v10;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
      LOBYTE(v45) = 0;
      v42 = 0;
      for ( i = 1; i <= 16; ++i )
      {
        if ( !v12 )
        {
          if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v43[3])(a1) )
            return 0;
          v10 = *v43;
          v12 = v43[1];
        }
        v42 += *v10;
        *((_BYTE *)&v45 + i) = *v10;
        --v12;
        ++v10;
        v38 = v12;
      }
      v14 = BYTE2(v45);
      v15 = (_DWORD *)(*a1 + 24);
      v41 = v40 - 17;
      *v15 = BYTE1(v45);
      v16 = HIBYTE(v45);
      v15[1] = v14;
      v17 = (unsigned __int8)v46;
      v15[2] = v16;
      v18 = BYTE1(v46);
      v15[3] = v17;
      v19 = BYTE2(v46);
      v15[4] = v18;
      v20 = HIBYTE(v46);
      v15[5] = v19;
      v21 = (unsigned __int8)v47;
      v15[6] = v20;
      v15[7] = v21;
      *(_DWORD *)(*a1 + 20) = 88;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 2);
      v22 = BYTE2(v47);
      v23 = (_DWORD *)(*a1 + 24);
      *v23 = BYTE1(v47);
      v24 = HIBYTE(v47);
      v23[1] = v22;
      v25 = (unsigned __int8)v48;
      v23[2] = v24;
      v26 = BYTE1(v48);
      v23[3] = v25;
      v27 = BYTE2(v48);
      v23[4] = v26;
      v28 = HIBYTE(v48);
      v23[5] = v27;
      v29 = v49;
      v23[6] = v28;
      v23[7] = v29;
      *(_DWORD *)(*a1 + 20) = 88;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 2);
      if ( v42 > 256 || v42 > v41 )
      {
        *(_DWORD *)(*a1 + 20) = 9;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      v30 = v42;
      for ( j = 0; j < v30; v38 = v12 )
      {
        if ( !v12 )
        {
          if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v43[3])(a1) )
            return 0;
          v10 = *v43;
          v30 = v42;
          v12 = v43[1];
        }
        v50[j] = *v10;
        --v12;
        ++j;
        ++v10;
      }
      v40 = v41 - v30;
      v32 = v44;
      if ( (v44 & 0x10) != 0 )
      {
        v32 = v44 - 16;
        v33 = (int)&a1[v44 + 28];
      }
      else
      {
        v33 = (int)&a1[v44 + 40];
      }
      if ( v32 >= 4 )
      {
        *(_DWORD *)(*a1 + 20) = 31;
        *(_DWORD *)(*a1 + 24) = v32;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      if ( !*(_DWORD *)v33 )
        *(_DWORD *)v33 = jpeg_alloc_huff_table(a1);
      v34 = *(_DWORD *)v33;
      v35 = v46;
      *(_DWORD *)v34 = v45;
      v36 = v47;
      *(_DWORD *)(v34 + 4) = v35;
      v37 = v48;
      *(_DWORD *)(v34 + 8) = v36;
      LOBYTE(v36) = v49;
      *(_DWORD *)(v34 + 12) = v37;
      *(_BYTE *)(v34 + 16) = v36;
      qmemcpy((void *)(*(_DWORD *)v33 + 17), v50, 0x100u);
      v9 = v38;
      v1 = v43;
    }
    while ( v40 > 16 );
    v8 = v40;
  }
  if ( v8 )
  {
    *(_DWORD *)(*a1 + 20) = 12;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  *v1 = v10;
  v1[1] = v9;
  return 1;
}
