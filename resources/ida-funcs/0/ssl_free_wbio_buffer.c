void __usercall ssl_free_wbio_buffer(int a1@<edi>, int a2@<ebx>, ssl_st *s)
{
  bio_st *bbio; // eax

  bbio = s->bbio;
  if ( bbio )
  {
    if ( bbio == s->wbio )
      s->wbio = BIO_pop(a2, s->wbio);
    BIO_free(a1, a2, s->bbio);
    s->bbio = 0;
  }
}
