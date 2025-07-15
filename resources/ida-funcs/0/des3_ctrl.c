int __cdecl des3_ctrl(evp_cipher_ctx_st *c, int type, int arg, unsigned __int8 *ptr)
{
  if ( type != 6 )
    return -1;
  if ( RAND_bytes((int)c) <= 0 )
    return 0;
  DES_set_odd_parity((unsigned __int8 (*)[8])ptr);
  if ( c->key_len >= 16 )
    DES_set_odd_parity((unsigned __int8 (*)[8])(ptr + 1));
  if ( c->key_len >= 24 )
    DES_set_odd_parity((unsigned __int8 (*)[8])(ptr + 2));
  return 1;
}
