int __cdecl DES_encrypt3(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // esi
  int v5; // edx
  unsigned int v6; // edi
  int v7; // edx
  int v8; // edi
  unsigned int v9; // esi
  int v10; // edx
  int v11; // esi
  int v12; // edi
  int v13; // esi
  int v14; // edi
  int v15; // edx
  int v16; // esi
  int v17; // edx
  unsigned int v18; // edi
  int v19; // esi
  int v20; // eax
  unsigned int v21; // edi
  int v22; // esi
  int v23; // edi
  int v24; // eax
  int v25; // esi
  int v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // edi
  unsigned int v30; // esi
  int v31; // eax
  int v32; // esi
  unsigned int v33; // edi
  int result; // eax

  v4 = a1[1];
  v5 = __ROL4__(*a1, 4);
  v6 = (v4 ^ v5) & 0xF0F0F0F0;
  v7 = v6 ^ v5;
  v8 = __ROL4__(v6 ^ v4, 20);
  v9 = (v7 ^ v8) & 0xFFF0000F;
  v10 = v9 ^ v7;
  v11 = __ROL4__(v9 ^ v8, 14);
  v12 = (v10 ^ v11) & 0x33333333;
  v13 = v12 ^ v11;
  v14 = __ROL4__(v12 ^ v10, 22);
  v15 = (v13 ^ v14) & 0x3FC03FC;
  v16 = v15 ^ v13;
  v17 = __ROL4__(v15 ^ v14, 9);
  v18 = (v16 ^ v17) & 0xAAAAAAAA;
  a1[1] = __ROR4__(v18 ^ v16, 2);
  *a1 = __ROR4__(v18 ^ v17, 3);
  DES_encrypt2(a1, a2, 1);
  DES_encrypt2(a1, a3, 0);
  DES_encrypt2(a1, a4, 1);
  v19 = __ROL4__(a1[1], 2);
  v20 = __ROL4__(*a1, 3);
  v21 = (v19 ^ v20) & 0xAAAAAAAA;
  v22 = v21 ^ v19;
  v23 = __ROL4__(v21 ^ v20, 23);
  v24 = (v22 ^ v23) & 0x3FC03FC;
  v25 = v24 ^ v22;
  v26 = __ROL4__(v24 ^ v23, 10);
  v27 = (v25 ^ v26) & 0x33333333;
  v28 = v27 ^ v26;
  v29 = __ROL4__(v27 ^ v25, 18);
  v30 = (v28 ^ v29) & 0xFFF0000F;
  v31 = v30 ^ v28;
  v32 = __ROL4__(v30 ^ v29, 12);
  v33 = (v31 ^ v32) & 0xF0F0F0F0;
  result = __ROR4__(v33 ^ v31, 4);
  *a1 = result;
  a1[1] = v33 ^ v32;
  return result;
}
