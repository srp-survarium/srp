int __cdecl DES_encrypt1(_DWORD *a1, _DWORD *a2, int a3)
{
  int v3; // edi
  int v4; // esi
  unsigned int v5; // eax
  int v6; // esi
  int v7; // eax
  unsigned int v8; // edi
  int v9; // esi
  int v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // eax
  unsigned int v14; // esi
  int v15; // edi
  int v16; // esi
  unsigned int v17; // eax
  int v18; // esi
  int v19; // edi
  int v20; // esi
  int v21; // eax
  unsigned int v22; // edi
  int v23; // esi
  int v24; // edi
  unsigned int v25; // eax
  int v26; // esi
  int v27; // eax
  int v28; // edi
  int v29; // eax
  int v30; // edi
  unsigned int v31; // esi
  int v32; // eax
  int v33; // esi
  unsigned int v34; // edi
  int result; // eax

  v3 = a1[1];
  v4 = __ROL4__(*a1, 4);
  v5 = (v3 ^ v4) & 0xF0F0F0F0;
  v6 = v5 ^ v4;
  v7 = __ROL4__(v5 ^ v3, 20);
  v8 = (v6 ^ v7) & 0xFFF0000F;
  v9 = v8 ^ v6;
  v10 = __ROL4__(v8 ^ v7, 14);
  v11 = (v9 ^ v10) & 0x33333333;
  v12 = v11 ^ v10;
  v13 = __ROL4__(v11 ^ v9, 22);
  v14 = (unsigned int)&vostok::memory::s_CRT_arena[55644724] & (v12 ^ v13);
  v15 = v14 ^ v12;
  v16 = __ROL4__(v14 ^ v13, 9);
  v17 = (v15 ^ v16) & 0xAAAAAAAA;
  v18 = v17 ^ v16;
  v19 = __ROL4__(v17 ^ v15, 1);
  if ( a3 )
    _x86_DES_encrypt(a2, (int)&DES_SPtrans, v19, v18);
  else
    _x86_DES_decrypt(a2, (int)&DES_SPtrans, v19, v18);
  v20 = __ROR4__(v18, 1);
  v21 = v19;
  v22 = (v20 ^ v19) & 0xAAAAAAAA;
  v23 = v22 ^ v20;
  v24 = __ROL4__(v22 ^ v21, 23);
  v25 = (unsigned int)&vostok::memory::s_CRT_arena[55644724] & (v23 ^ v24);
  v26 = v25 ^ v23;
  v27 = __ROL4__(v25 ^ v24, 10);
  v28 = (v26 ^ v27) & 0x33333333;
  v29 = v28 ^ v27;
  v30 = __ROL4__(v28 ^ v26, 18);
  v31 = (v29 ^ v30) & 0xFFF0000F;
  v32 = v31 ^ v29;
  v33 = __ROL4__(v31 ^ v30, 12);
  v34 = (v32 ^ v33) & 0xF0F0F0F0;
  result = __ROR4__(v34 ^ v32, 4);
  *a1 = result;
  a1[1] = v34 ^ v33;
  return result;
}
