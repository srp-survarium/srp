void __cdecl pkey_ec_cleanup(evp_pkey_ctx_st *ctx)
{
  ec_group_st **data; // esi

  data = (ec_group_st **)ctx->data;
  if ( data )
  {
    if ( *data )
      EC_GROUP_free(*data);
    CRYPTO_free(data);
  }
}
