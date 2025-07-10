int __cdecl seed_init_key(evp_cipher_ctx_st *ctx, const unsigned __int8 *key)
{
  SEED_set_key(key, (seed_key_st *)ctx->cipher_data);
  return 1;
}
