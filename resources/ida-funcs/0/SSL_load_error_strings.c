int SSL_load_error_strings()
{
  ERR_load_crypto_strings();
  return ERR_load_SSL_strings();
}
