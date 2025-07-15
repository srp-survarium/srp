char __cdecl RC4(int a1, int a2, _BYTE *a3, int a4)
{
  _BYTE *v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // ecx
  int v15; // ebp
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // ebp
  int v20; // edx
  int v21; // edx
  int v22; // ecx
  int v23; // ebp
  int v24; // edx
  bool v25; // cf
  int v26; // edx
  char v27; // cl
  char v28; // dl
  char v29; // dl
  _BYTE *v31; // [esp+18h] [ebp+8h]
  unsigned int v32; // [esp+1Ch] [ebp+Ch]
  int v33; // [esp+20h] [ebp+10h]

  v5 = a3;
  v6 = 0;
  v7 = 0;
  if ( a2 )
  {
    LOBYTE(v7) = *(_BYTE *)(a1 + 4);
    v8 = a1 + 8;
    v9 = a4 - (_DWORD)a3;
    v31 = &a3[a2];
    LOBYTE(v6) = *(_BYTE *)a1 + 1;
    if ( *(_DWORD *)(a1 + 264) == -1 )
    {
      v27 = *(_BYTE *)(v8 + v6);
      do
      {
        LOBYTE(v7) = v27 + v7;
        v28 = *(_BYTE *)(v8 + v7);
        *(_BYTE *)(v8 + v7) = v27;
        *(_BYTE *)(v8 + v6) = v28;
        LOBYTE(v6) = v6 + 1;
        v29 = *v5++ ^ *(_BYTE *)(v8 + (unsigned __int8)(v27 + v28));
        v27 = *(_BYTE *)(v8 + v6);
        v5[v9 - 1] = v29;
      }
      while ( v5 < v31 );
      goto $L004done;
    }
    v10 = *(_DWORD *)(v8 + 4 * v6);
    v11 = a2 & 0xFFFFFFFC;
    if ( v11 )
    {
      v32 = (unsigned int)&a3[v11 - 4];
      v33 = v9;
      do
      {
        LOBYTE(v7) = v10 + v7;
        v12 = *(_DWORD *)(v8 + 4 * v7);
        *(_DWORD *)(v8 + 4 * v7) = v10;
        *(_DWORD *)(v8 + 4 * v6) = v12;
        LOBYTE(v6) = v6 + 1;
        v13 = (unsigned __int8)(v10 + v12);
        v14 = *(_DWORD *)(v8 + 4 * v6);
        v15 = *(_DWORD *)(v8 + 4 * v13);
        LOBYTE(v7) = v14 + v7;
        v16 = *(_DWORD *)(v8 + 4 * v7);
        *(_DWORD *)(v8 + 4 * v7) = v14;
        *(_DWORD *)(v8 + 4 * v6) = v16;
        LOBYTE(v6) = v6 + 1;
        v17 = (unsigned __int8)(v14 + v16);
        v18 = *(_DWORD *)(v8 + 4 * v6);
        v19 = *(_DWORD *)(v8 + 4 * v17) | __ROR4__(v15, 8);
        LOBYTE(v7) = v18 + v7;
        v20 = *(_DWORD *)(v8 + 4 * v7);
        *(_DWORD *)(v8 + 4 * v7) = v18;
        *(_DWORD *)(v8 + 4 * v6) = v20;
        LOBYTE(v6) = v6 + 1;
        v21 = (unsigned __int8)(v18 + v20);
        v22 = *(_DWORD *)(v8 + 4 * v6);
        v23 = *(_DWORD *)(v8 + 4 * v21) | __ROR4__(v19, 8);
        LOBYTE(v7) = v22 + v7;
        v24 = *(_DWORD *)(v8 + 4 * v7);
        *(_DWORD *)(v8 + 4 * v7) = v22;
        *(_DWORD *)(v8 + 4 * v6) = v24;
        LOBYTE(v6) = v6 + 1;
        v25 = (unsigned int)v5 < v32;
        *(_DWORD *)&v5[v33] = *(_DWORD *)v5
                            ^ __ROR4__(*(_DWORD *)(v8 + 4 * (unsigned __int8)(v22 + v24)) | __ROR4__(v23, 8), 8);
        v5 += 4;
        v10 = *(_DWORD *)(v8 + 4 * v6);
      }
      while ( v25 );
      if ( v5 == v31 )
        goto $L004done;
      v9 = v33;
    }
    do
    {
      LOBYTE(v7) = v10 + v7;
      v26 = *(_DWORD *)(v8 + 4 * v7);
      *(_DWORD *)(v8 + 4 * v7) = v10;
      *(_DWORD *)(v8 + 4 * v6) = v26;
      LOBYTE(v6) = v6 + 1;
      LOBYTE(v26) = *v5++ ^ *(_DWORD *)(v8 + 4 * (unsigned __int8)(v10 + v26));
      v10 = *(_DWORD *)(v8 + 4 * v6);
      v5[v9 - 1] = v26;
    }
    while ( v5 < v31 );
$L004done:
    LOBYTE(v6) = v6 - 1;
    *(_BYTE *)(a1 + 4) = v7;
    *(_BYTE *)a1 = v6;
  }
  return v6;
}
