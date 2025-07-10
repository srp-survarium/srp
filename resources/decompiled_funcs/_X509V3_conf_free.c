void __cdecl X509V3_conf_free(CONF_VALUE *conf)
{
  if ( conf )
  {
    if ( conf->name )
      CRYPTO_free(conf->name);
    if ( conf->value )
      CRYPTO_free(conf->value);
    if ( conf->section )
      CRYPTO_free(conf->section);
    CRYPTO_free(conf);
  }
}
