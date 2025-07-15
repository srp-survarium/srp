const ssl_cipher_st *__cdecl ssl3_get_cipher(unsigned int u)
{
  if ( u >= 0x5A )
    return 0;
  else
    return &ssl3_ciphers[-u + 89];
}
