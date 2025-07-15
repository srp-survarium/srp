int __usercall ssl_init_wbio_buffer@<eax>(int a1@<ebx>, ssl_st *s, int push)
{
  bio_st *bbio; // esi
  bio_method_st *v4; // eax
  bio_st *v5; // eax

  bbio = s->bbio;
  if ( bbio )
  {
    if ( bbio == s->wbio )
      s->wbio = BIO_pop(a1, s->wbio);
  }
  else
  {
    v4 = BIO_f_buffer();
    v5 = BIO_new(a1, v4);
    bbio = v5;
    if ( !v5 )
      return 0;
    s->bbio = v5;
  }
  BIO_ctrl(a1, bbio, 1, 0, 0);
  if ( !BIO_int_ctrl(a1, bbio, 117, 1, 0) )
  {
    ERR_put_error(a1, 0x14u, 184, 7, ".\\ssl\\ssl_lib.c", 2663);
    return 0;
  }
  if ( push )
  {
    if ( s->wbio != bbio )
    {
      s->wbio = BIO_push(a1, bbio, s->wbio);
      return 1;
    }
  }
  else if ( s->wbio == bbio )
  {
    s->wbio = BIO_pop(a1, bbio);
  }
  return 1;
}
