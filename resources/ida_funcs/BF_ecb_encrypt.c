void __cdecl BF_ecb_encrypt(const unsigned __int8 *in, unsigned __int8 *out, const bf_key_st *key, int encrypt)
{
  int v4; // edx
  unsigned int v5; // ecx
  int v6; // ecx
  unsigned int v7; // [esp+0h] [ebp-8h] BYREF
  int v8; // [esp+4h] [ebp-4h]

  v4 = in[5];
  v7 = _byteswap_ulong(*(_DWORD *)in);
  v8 = (v4 << 16) | (in[4] << 24) | in[7] | (in[6] << 8);
  if ( encrypt )
    BF_encrypt(&v7, key);
  else
    BF_decrypt(&v7, key);
  v5 = v7;
  *out = HIBYTE(v7);
  out[1] = BYTE2(v5);
  out[2] = BYTE1(v5);
  out[3] = v5;
  v6 = v8;
  out[4] = HIBYTE(v8);
  out[5] = BYTE2(v6);
  out[6] = BYTE1(v6);
  out[7] = v6;
}
