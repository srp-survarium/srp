void __cdecl CRYPTO_cfb128_8_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        const void *key,
        unsigned __int8 *ivec,
        int *num,
        int enc,
        void (__cdecl *block)(const unsigned __int8 *, unsigned __int8 *, const void *))
{
  unsigned int v8; // ebx
  const unsigned __int8 *v9; // esi

  v8 = length;
  if ( length )
  {
    v9 = in;
    do
    {
      cfbr_encrypt_block(block, v9, (unsigned __int8 *)&v9[out - in], 8, key, ivec, enc);
      ++v9;
      --v8;
    }
    while ( v8 );
  }
}
