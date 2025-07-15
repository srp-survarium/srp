void __cdecl idea_ecb_encrypt(const unsigned __int8 *in, unsigned __int8 *out, idea_key_st *ks)
{
  int v3; // edx
  unsigned int v4; // ecx
  int v5; // ecx
  unsigned int d; // [esp+0h] [ebp-8h] BYREF
  int v7; // [esp+4h] [ebp-4h]

  v3 = in[5];
  d = _byteswap_ulong(*(_DWORD *)in);
  v7 = (v3 << 16) | (in[4] << 24) | in[7] | (in[6] << 8);
  idea_encrypt(&d, ks);
  v4 = d;
  *out = HIBYTE(d);
  out[1] = BYTE2(v4);
  out[2] = BYTE1(v4);
  out[3] = v4;
  v5 = v7;
  out[4] = HIBYTE(v7);
  out[5] = BYTE2(v5);
  out[6] = BYTE1(v5);
  out[7] = v5;
}
