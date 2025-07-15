void __cdecl mdc2_body(mdc2_ctx_st *c, unsigned int len)
{
  unsigned __int8 *v2; // ecx
  unsigned __int8 *v3; // esi
  unsigned __int8 *h; // edi
  unsigned __int8 *hh; // ebp
  int v6; // ebx
  int v7; // eax
  unsigned __int8 *v8; // esi
  int v9; // ecx
  int v10; // edx
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  int v15; // ebx
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // ebx
  int v21; // [esp+8h] [ebp-A0h]
  int v22; // [esp+8h] [ebp-A0h]
  unsigned int v23; // [esp+10h] [ebp-98h]
  int v24; // [esp+14h] [ebp-94h] BYREF
  int v25; // [esp+18h] [ebp-90h]
  int v26; // [esp+1Ch] [ebp-8Ch] BYREF
  int v27; // [esp+20h] [ebp-88h]
  DES_ks schedule; // [esp+24h] [ebp-84h] BYREF

  v3 = v2;
  if ( len )
  {
    h = c->h;
    hh = c->hh;
    v23 = ((len - 1) >> 3) + 1;
    do
    {
      v6 = *v3;
      v7 = v3[1];
      v8 = v3 + 1;
      v9 = *++v8;
      v10 = v8[1];
      v11 = (v7 << 8) | v6;
      v12 = (++v8)[1];
      ++v8;
      v13 = (v9 << 16) | v11;
      v14 = *++v8;
      v15 = (v10 << 24) | v13;
      v16 = *++v8;
      v17 = (v16 << 16) | (v14 << 8) | v12;
      LOBYTE(v16) = *h;
      v21 = (v8[1] << 24) | v17;
      v25 = v21;
      v27 = v21;
      LOBYTE(v17) = *hh & 0x9F | 0x20;
      v24 = v15;
      v26 = v15;
      v3 = v8 + 2;
      *h = v16 & 0x9F | 0x40;
      *hh = v17;
      DES_set_odd_parity((unsigned __int8 (*)[8])h);
      DES_set_key_unchecked((unsigned __int8 (*)[8])h, &schedule);
      DES_encrypt1(&v26, &schedule, 1);
      DES_set_odd_parity((unsigned __int8 (*)[8])hh);
      DES_set_key_unchecked((unsigned __int8 (*)[8])hh, &schedule);
      DES_encrypt1(&v24, &schedule, 1);
      v18 = v21 ^ v25;
      v22 = v27 ^ v21;
      v19 = v15 ^ v24;
      v20 = v26 ^ v15;
      *h = v20;
      c->h[1] = BYTE1(v20);
      c->h[2] = BYTE2(v20);
      c->h[3] = HIBYTE(v20);
      *(_DWORD *)&c->h[4] = v18;
      *hh = v19;
      c->hh[1] = BYTE1(v19);
      c->hh[2] = BYTE2(v19);
      c->hh[3] = HIBYTE(v19);
      *(_DWORD *)&c->hh[4] = v22;
      --v23;
    }
    while ( v23 );
  }
}
