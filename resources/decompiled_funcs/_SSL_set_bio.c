void __cdecl SSL_set_bio(ssl_st *s, bio_st *rbio, bio_st *wbio)
{
  bio_st *bbio; // eax
  bio_st *v4; // ecx
  bio_st *v5; // eax
  bio_st *v6; // eax

  bbio = s->bbio;
  if ( bbio )
  {
    v4 = s->wbio;
    if ( v4 == bbio )
    {
      s->wbio = v4->next_bio;
      bbio->next_bio = 0;
    }
  }
  v5 = s->rbio;
  if ( v5 && v5 != rbio )
    BIO_free_all(s->rbio);
  v6 = s->wbio;
  if ( v6 )
  {
    if ( v6 != wbio && s->rbio != v6 )
      BIO_free_all(v6);
    s->wbio = wbio;
    s->rbio = rbio;
  }
  else
  {
    s->rbio = rbio;
    s->wbio = wbio;
  }
}
