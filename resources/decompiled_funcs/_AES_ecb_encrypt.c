void __cdecl AES_ecb_encrypt(const unsigned __int8 *in, unsigned __int8 *out, const aes_key_st *key, int enc)
{
  if ( enc == 1 )
    AES_encrypt(in, out, key);
  else
    AES_decrypt(in, out, key);
}
