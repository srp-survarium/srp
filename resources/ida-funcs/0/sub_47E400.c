char __usercall sub_47E400@<al>(_DWORD *a1@<esi>)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // ebx
  unsigned __int8 *v3; // ebp
  unsigned __int8 *v5; // ebp
  int v6; // eax
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // ebp
  int v9; // eax
  unsigned __int8 *v10; // ebx
  int v11; // eax
  unsigned __int8 *v12; // ebp
  unsigned __int8 *v13; // ebx
  int v14; // eax
  int v15; // edx
  unsigned __int8 *v16; // ebp
  unsigned __int8 *v17; // ebx
  int v18; // eax
  _DWORD *v19; // edi
  int v20; // ecx
  _DWORD *v21; // eax
  int v22; // eax
  unsigned __int8 *v23; // ebp
  unsigned __int8 *v24; // ebx
  int v25; // eax
  unsigned __int8 *v26; // ebp
  unsigned __int8 *v27; // ebx
  int v28; // edx
  int v29; // ecx
  _DWORD *v30; // eax
  unsigned __int8 *v31; // ebp
  unsigned __int8 *v32; // ebx
  int v33; // [esp+Ch] [ebp-18h]
  int v34; // [esp+10h] [ebp-14h]
  int v35; // [esp+10h] [ebp-14h]
  int v36; // [esp+10h] [ebp-14h]
  _DWORD *v37; // [esp+14h] [ebp-10h]
  int v38; // [esp+18h] [ebp-Ch]
  unsigned __int8 **v39; // [esp+1Ch] [ebp-8h]
  int v40; // [esp+20h] [ebp-4h]

  v1 = (unsigned __int8 **)a1[6];
  v2 = *v1;
  v3 = v1[1];
  v39 = v1;
  if ( !*(_BYTE *)(a1[105] + 13) )
  {
    *(_DWORD *)(*a1 + 20) = 64;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( !v3 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v2 = *v1;
    v3 = v1[1];
  }
  v5 = v3 - 1;
  v6 = *v2 << 8;
  v7 = v2 + 1;
  v34 = v6;
  if ( !v5 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v7 = *v1;
    v5 = v1[1];
    v6 = v34;
  }
  v8 = v5 - 1;
  v9 = *v7 + v6;
  v10 = v7 + 1;
  v35 = v9;
  if ( !v8 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v10 = *v1;
    v8 = v1[1];
  }
  v11 = *v10;
  *(_DWORD *)(*a1 + 20) = 105;
  *(_DWORD *)(*a1 + 24) = v11;
  v33 = v11;
  v12 = v8 - 1;
  v13 = v10 + 1;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  v14 = v33;
  if ( v35 != 2 * v33 + 6 || v33 > 4 || !v33 && !*((_BYTE *)a1 + 201) )
  {
    *(_DWORD *)(*a1 + 20) = 12;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    v14 = v33;
  }
  a1[74] = v14;
  v38 = 0;
  if ( v14 > 0 )
  {
    v37 = a1 + 75;
    do
    {
      if ( !v12 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
          return 0;
        v13 = *v1;
        v12 = v1[1];
      }
      v15 = *v13;
      v16 = v12 - 1;
      v17 = v13 + 1;
      v36 = v15;
      if ( !v16 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
          return 0;
        v17 = *v1;
        v16 = v1[1];
      }
      v18 = *v17;
      v19 = (_DWORD *)a1[49];
      v20 = 0;
      v12 = v16 - 1;
      v13 = v17 + 1;
      v40 = v18;
      if ( (int)a1[9] <= 0 )
      {
LABEL_29:
        *(_DWORD *)(*a1 + 20) = 4;
        *(_DWORD *)(*a1 + 24) = v36;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
        v18 = v40;
      }
      else
      {
        while ( v36 != *v19 )
        {
          ++v20;
          v19 += 22;
          if ( v20 >= a1[9] )
            goto LABEL_29;
        }
      }
      *v37 = v19;
      v19[6] = v18 & 0xF;
      v19[5] = (v18 >> 4) & 0xF;
      v21 = (_DWORD *)(*a1 + 24);
      *v21 = v36;
      v21[1] = v19[5];
      v21[2] = v19[6];
      *(_DWORD *)(*a1 + 20) = 106;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
      ++v37;
      v1 = v39;
      ++v38;
    }
    while ( v38 < v33 );
  }
  if ( !v12 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v13 = *v1;
    v12 = v1[1];
  }
  v22 = *v13;
  v23 = v12 - 1;
  v24 = v13 + 1;
  a1[92] = v22;
  if ( !v23 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v24 = *v1;
    v23 = v1[1];
  }
  v25 = *v24;
  v26 = v23 - 1;
  v27 = v24 + 1;
  a1[93] = v25;
  if ( !v26 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v27 = *v1;
    v26 = v1[1];
  }
  v28 = a1[92];
  v29 = *v27;
  a1[95] = v29 & 0xF;
  v30 = (_DWORD *)*a1;
  a1[94] = (v29 >> 4) & 0xF;
  v30 += 6;
  *v30 = v28;
  v30[1] = a1[93];
  v30[2] = a1[94];
  v30[3] = a1[95];
  *(_DWORD *)(*a1 + 20) = 107;
  v31 = v26 - 1;
  v32 = v27 + 1;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  *(_DWORD *)(a1[105] + 16) = 0;
  if ( v33 )
    ++a1[31];
  *v1 = v32;
  v1[1] = v31;
  return 1;
}
