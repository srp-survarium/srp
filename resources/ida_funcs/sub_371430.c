char __usercall sub_371430@<al>(char a1@<al>, char a2@<dl>, char a3@<cl>, int a4@<esi>)
{
  unsigned __int8 **v4; // ebp
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v8; // ebx
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // edi
  int v13; // ecx
  unsigned __int8 *v14; // ebx
  unsigned __int8 *v15; // edi
  unsigned __int8 *v16; // ebx
  int v17; // eax
  unsigned __int8 *v18; // edi
  unsigned __int8 *v19; // ebx
  unsigned __int8 *v20; // edi
  unsigned __int8 *v21; // ebx
  int v22; // ecx
  unsigned __int8 *v23; // edi
  unsigned __int8 *v24; // ebx
  unsigned __int8 *v25; // edi
  _DWORD *v26; // eax
  int v27; // ecx
  unsigned __int8 *v28; // ebx
  unsigned __int8 *v29; // edi
  int *v30; // ebp
  int v31; // ecx
  unsigned __int8 *v32; // ebx
  unsigned __int8 *v33; // edi
  unsigned __int8 *v34; // ebx
  int v35; // ecx
  int v36; // eax
  unsigned __int8 *v37; // edi
  int v38; // ecx
  _DWORD *v39; // eax
  int v40; // [esp+Ch] [ebp-8h]
  int v41; // [esp+Ch] [ebp-8h]
  int v42; // [esp+Ch] [ebp-8h]
  int i; // [esp+Ch] [ebp-8h]
  unsigned __int8 **v44; // [esp+10h] [ebp-4h]

  v4 = *(unsigned __int8 ***)(a4 + 24);
  v5 = v4[1];
  v6 = *v4;
  v44 = v4;
  *(_BYTE *)(a4 + 200) = a1;
  *(_BYTE *)(a4 + 201) = a3;
  *(_BYTE *)(a4 + 202) = a2;
  if ( !v5 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v6 = *v4;
    v5 = v4[1];
  }
  v8 = v5 - 1;
  v9 = *v6 << 8;
  v10 = v6 + 1;
  v40 = v9;
  if ( !v8 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v10 = *v4;
    v8 = v4[1];
  }
  v41 = *v10 + v40;
  v11 = v8 - 1;
  v12 = v10 + 1;
  if ( !v11 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v12 = *v4;
    v11 = v4[1];
  }
  v13 = *v12;
  v14 = v11 - 1;
  v15 = v12 + 1;
  *(_DWORD *)(a4 + 192) = v13;
  if ( !v14 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v15 = *v4;
    v14 = v4[1];
  }
  v16 = v14 - 1;
  v17 = *v15 << 8;
  v18 = v15 + 1;
  *(_DWORD *)(a4 + 32) = v17;
  if ( !v16 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v18 = *v4;
    v16 = v4[1];
  }
  *(_DWORD *)(a4 + 32) += *v18;
  v19 = v16 - 1;
  v20 = v18 + 1;
  if ( !v19 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v20 = *v4;
    v19 = v4[1];
  }
  v21 = v19 - 1;
  v22 = *v20 << 8;
  v23 = v20 + 1;
  *(_DWORD *)(a4 + 28) = v22;
  if ( !v21 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v23 = *v4;
    v21 = v4[1];
  }
  *(_DWORD *)(a4 + 28) += *v23;
  v24 = v21 - 1;
  v25 = v23 + 1;
  if ( !v24 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int))v4[3])(a4) )
      return 0;
    v25 = *v4;
    v24 = v4[1];
  }
  v26 = *(_DWORD **)a4;
  v27 = *(_DWORD *)(a4 + 396);
  v42 = v41 - 8;
  *(_DWORD *)(a4 + 36) = *v25;
  v26 += 6;
  *v26 = v27;
  v26[1] = *(_DWORD *)(a4 + 28);
  v26[2] = *(_DWORD *)(a4 + 32);
  v26[3] = *(_DWORD *)(a4 + 36);
  *(_DWORD *)(*(_DWORD *)a4 + 20) = 102;
  v28 = v24 - 1;
  v29 = v25 + 1;
  (*(void (__cdecl **)(int, int))(*(_DWORD *)a4 + 4))(a4, 1);
  if ( *(_BYTE *)(*(_DWORD *)(a4 + 420) + 13) )
  {
    *(_DWORD *)(*(_DWORD *)a4 + 20) = 60;
    (**(void (__cdecl ***)(int))a4)(a4);
  }
  if ( !*(_DWORD *)(a4 + 32) || !*(_DWORD *)(a4 + 28) || *(int *)(a4 + 36) <= 0 )
  {
    *(_DWORD *)(*(_DWORD *)a4 + 20) = 33;
    (**(void (__cdecl ***)(int))a4)(a4);
  }
  if ( v42 != 3 * *(_DWORD *)(a4 + 36) )
  {
    *(_DWORD *)(*(_DWORD *)a4 + 20) = 12;
    (**(void (__cdecl ***)(int))a4)(a4);
  }
  if ( !*(_DWORD *)(a4 + 196) )
    *(_DWORD *)(a4 + 196) = (**(int (__cdecl ***)(int, int, int))(a4 + 4))(a4, 1, 88 * *(_DWORD *)(a4 + 36));
  v30 = *(int **)(a4 + 196);
  for ( i = 0; i < *(_DWORD *)(a4 + 36); ++i )
  {
    v30[1] = i;
    if ( !v28 )
    {
      if ( !((unsigned __int8 (__cdecl *)(int))v44[3])(a4) )
        return 0;
      v29 = *v44;
      v28 = v44[1];
    }
    v31 = *v29;
    v32 = v28 - 1;
    v33 = v29 + 1;
    *v30 = v31;
    if ( !v32 )
    {
      if ( !((unsigned __int8 (__cdecl *)(int))v44[3])(a4) )
        return 0;
      v33 = *v44;
      v32 = v44[1];
    }
    v34 = v32 - 1;
    v35 = ((int)*v33 >> 4) & 0xF;
    v36 = *v33 & 0xF;
    v37 = v33 + 1;
    v30[2] = v35;
    v30[3] = v36;
    if ( !v34 )
    {
      if ( !((unsigned __int8 (__cdecl *)(int))v44[3])(a4) )
        return 0;
      v37 = *v44;
      v34 = v44[1];
    }
    v38 = *v30;
    v30[4] = *v37;
    v39 = (_DWORD *)(*(_DWORD *)a4 + 24);
    *v39 = v38;
    v39[1] = v30[2];
    v39[2] = v30[3];
    v39[3] = v30[4];
    *(_DWORD *)(*(_DWORD *)a4 + 20) = 103;
    v28 = v34 - 1;
    v29 = v37 + 1;
    (*(void (__cdecl **)(int, int))(*(_DWORD *)a4 + 4))(a4, 1);
    v30 += 22;
  }
  *(_BYTE *)(*(_DWORD *)(a4 + 420) + 13) = 1;
  *v44 = v29;
  v44[1] = v28;
  return 1;
}
