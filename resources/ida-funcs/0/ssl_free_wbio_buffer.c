void __usercall ssl_free_wbio_buffer(unsigned int a1@<edi>, ssl_st *s)
{
  bio_st *bbio; // eax

  bbio = s->bbio;
  if ( bbio )
  {
    if ( bbio == s->wbio )
      s->wbio = BIO_pop(s->wbio);
    BIO_free(a1, s->bbio);
    s->bbio = 0;
  }
}
