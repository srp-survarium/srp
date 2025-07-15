int __cdecl SSL_get_error(const ssl_st *s, int i)
{
  int result; // eax
  unsigned int v3; // eax
  bool v4; // zf
  bio_st *rbio; // edi
  const ecdsa_method *ECDSA; // eax

  if ( i > 0 )
    return 0;
  v3 = ERR_peek_error();
  if ( v3 )
    return 4 * ((v3 & 0xFF000000) == 0x2000000) + 1;
  v4 = i == 0;
  if ( i < 0 )
  {
    if ( s->rwstate == 3 )
    {
      rbio = s->rbio;
      if ( BIO_test_flags(rbio, 1) )
        return 2;
      if ( BIO_test_flags(rbio, 2) )
        return 3;
      if ( BIO_test_flags(rbio, 4) )
        goto LABEL_16;
    }
    if ( s->rwstate == 2 )
    {
      rbio = s->wbio;
      if ( BIO_test_flags(rbio, 2) )
        return 3;
      if ( BIO_test_flags(rbio, 1) )
        return 2;
      if ( BIO_test_flags(rbio, 4) )
      {
LABEL_16:
        ECDSA = ENGINE_get_ECDSA((const engine_st *)rbio);
        if ( ECDSA == (const ecdsa_method *)2 )
          return 7;
        else
          return ECDSA != (const ecdsa_method *)3 ? 5 : 8;
      }
    }
    result = 4;
    if ( s->rwstate == 4 )
      return result;
    v4 = i == 0;
  }
  if ( !v4 )
    return 5;
  if ( s->version == 2 )
    return 6;
  if ( (s->shutdown & 2) == 0 )
    return 5;
  result = 6;
  if ( s->s3->warn_alert )
    return 5;
  return result;
}
