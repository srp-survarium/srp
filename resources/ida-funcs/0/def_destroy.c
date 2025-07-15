int __cdecl def_destroy(conf_st *conf)
{
  if ( !conf )
    return 0;
  _CONF_free_data(conf);
  CRYPTO_free(conf);
  return 1;
}
