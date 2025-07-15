void __cdecl CRYPTO_cfb128_1_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int bits,
        const void *key,
        unsigned __int8 *ivec,
        int *num,
        int enc,
        void (__cdecl *block)(const unsigned __int8 *, unsigned __int8 *, const void *))
{
  unsigned int i; // ebp
  char v9; // bl
  unsigned int v10; // esi
  unsigned __int8 v11; // [esp+6h] [ebp-2h] BYREF
  unsigned __int8 v12; // [esp+7h] [ebp-1h] BYREF

  for ( i = 0; i < bits; out[v10] = ((unsigned __int8)(v12 & 0x80) >> v9) | out[v10] & ~(1 << (7 - v9)) )
  {
    v9 = i & 7;
    v10 = i >> 3;
    v11 = ((unsigned __int8)(1 << (7 - (i & 7))) & in[i >> 3]) != 0 ? 0x80 : 0;
    cfbr_encrypt_block(block, &v11, &v12, 1, key, ivec, enc);
    ++i;
  }
}
