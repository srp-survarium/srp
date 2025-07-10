int __cdecl ssl_init_wbio_buffer(ssl_st *s, int push)
{
  bio_st *bbio; // esi
  bio_method_st *v3; // eax
  bio_st *v4; // eax

  bbio = s->bbio;
  if ( bbio )
  {
    if ( bbio == s->wbio )
      s->wbio = BIO_pop(s->wbio);
  }
  else
  {
    v3 = BIO_f_buffer();
    v4 = BIO_new(v3);
    bbio = v4;
    if ( !v4 )
      return 0;
    s->bbio = v4;
  }
  BIO_ctrl(bbio, 1, 0, 0);
  if ( !BIO_int_ctrl(bbio, 117, 1, 0) )
  {
    ERR_put_error(0x14u, 184, 7, ".\\ssl\\ssl_lib.c", 2663);
    return 0;
  }
  if ( push )
  {
    if ( s->wbio != bbio )
    {
      s->wbio = BIO_push(bbio, s->wbio);
      return 1;
    }
  }
  else if ( s->wbio == bbio )
  {
    s->wbio = BIO_pop(bbio);
  }
  return 1;
}
