void __cdecl EC_KEY_free(ec_key_st *r)
{
  if ( r && CRYPTO_add_lock(&r->references, -1, 33, ".\\crypto\\ec\\ec_key.c", 111) <= 0 )
  {
    if ( r->group )
      EC_GROUP_free(r->group);
    if ( r->pub_key )
      EC_POINT_free(r->pub_key);
    if ( r->priv_key )
      BN_clear_free(r->priv_key);
    EC_EX_DATA_free_all_data(&r->method_data);
    OPENSSL_cleanse(r, 32);
    CRYPTO_free(r);
  }
}
