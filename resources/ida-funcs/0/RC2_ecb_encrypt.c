void __cdecl RC2_ecb_encrypt(const unsigned __int8 *in, unsigned __int8 *out, rc2_key_st *ks, int encrypt)
{
  int v4; // edx
  __int16 v5; // ecx^2
  __int16 v6; // ecx^2
  unsigned int d; // [esp+0h] [ebp-8h] BYREF
  int v8; // [esp+4h] [ebp-4h]

  v4 = in[5];
  d = (in[3] << 24) | (in[2] << 16) | *(unsigned __int16 *)in;
  v8 = (v4 << 8) | in[4] | (*((unsigned __int16 *)in + 3) << 16);
  if ( encrypt )
    RC2_encrypt(&d, ks);
  else
    RC2_decrypt(&d, ks);
  v5 = HIWORD(d);
  *(_WORD *)out = d;
  *((_WORD *)out + 1) = v5;
  v6 = HIWORD(v8);
  *((_WORD *)out + 2) = v8;
  *((_WORD *)out + 3) = v6;
}
