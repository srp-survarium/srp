int __cdecl RC4_set_key(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // edi
  int v4; // esi
  int v5; // ebp
  int v6; // eax
  bool v7; // cf
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  bool v11; // zf
  int v12; // ebx
  int v13; // ecx
  int v14; // edx
  char v15; // al
  char v16; // bl
  int result; // eax

  v3 = a1 + 2;
  v4 = a3 + a2;
  v5 = -a2;
  v6 = 0;
  a1[1] = -a2;
  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x14u) )
  {
    do
    {
      *((_BYTE *)v3 + v6) = v6;
      v7 = __CFADD__((_BYTE)v6, 1);
      LOBYTE(v6) = v6 + 1;
    }
    while ( !v7 );
    v13 = 0;
    v14 = 0;
    do
    {
      v15 = *((_BYTE *)v3 + v13);
      LOBYTE(v14) = v15 + *(_BYTE *)(v4 + v5) + v14;
      v11 = v5++ == -1;
      v16 = *((_BYTE *)v3 + v14);
      if ( v11 )
        v5 = a1[1];
      *((_BYTE *)v3 + v14) = v15;
      *((_BYTE *)v3 + v13) = v16;
      v7 = __CFADD__((_BYTE)v13, 1);
      LOBYTE(v13) = v13 + 1;
    }
    while ( !v7 );
    a1[66] = -1;
  }
  else
  {
    do
    {
      v3[v6] = v6;
      v7 = __CFADD__((_BYTE)v6, 1);
      LOBYTE(v6) = v6 + 1;
    }
    while ( !v7 );
    v8 = 0;
    v9 = 0;
    do
    {
      v10 = v3[v8];
      LOBYTE(v9) = v10 + *(_BYTE *)(v4 + v5) + v9;
      v11 = v5++ == -1;
      v12 = v3[v9];
      if ( v11 )
        v5 = a1[1];
      v3[v9] = v10;
      v3[v8] = v12;
      v7 = __CFADD__((_BYTE)v8, 1);
      LOBYTE(v8) = v8 + 1;
    }
    while ( !v7 );
  }
  result = 0;
  *a1 = 0;
  a1[1] = 0;
  return result;
}
