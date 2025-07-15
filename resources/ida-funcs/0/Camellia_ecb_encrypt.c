void __cdecl Camellia_ecb_encrypt(unsigned __int8 *in, unsigned __int8 *out, const camellia_key_st *key, const int enc)
{
  if ( enc == 1 )
    Camellia_encrypt(in, out, key);
  else
    Camellia_decrypt(in, out, key);
}
