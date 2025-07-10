const ssl_cipher_st *__cdecl ssl2_get_cipher(unsigned int u)
{
  if ( u >= 7 )
    return 0;
  else
    return &ssl2_ciphers[-u + 6];
}
