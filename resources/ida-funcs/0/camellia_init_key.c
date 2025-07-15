int __usercall camellia_init_key@<eax>(int a1@<ebx>, evp_cipher_ctx_st *ctx, const unsigned __int8 *key)
{
  if ( Camellia_set_key(key, 8 * ctx->key_len, ctx->cipher_data) >= 0 )
    return 1;
  ERR_put_error(a1, 6u, 159, 157, ".\\crypto\\evp\\e_camellia.c", 118);
  return 0;
}
