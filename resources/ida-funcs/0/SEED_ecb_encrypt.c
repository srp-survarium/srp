void __cdecl SEED_ecb_encrypt(const unsigned __int8 *in, unsigned __int8 *out, const seed_key_st *ks, int enc)
{
  if ( enc )
    SEED_encrypt(in, out, ks);
  else
    SEED_decrypt(in, out, ks);
}
