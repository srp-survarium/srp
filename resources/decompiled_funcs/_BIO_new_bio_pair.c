int __cdecl BIO_new_bio_pair(bio_st **bio1_p, unsigned int writebuf1, bio_st **bio2_p, unsigned int writebuf2)
{
  bio_st *v4; // esi
  bio_st *v5; // edi

  v4 = 0;
  v5 = BIO_new(&methods_biop);
  if ( v5 )
  {
    v4 = BIO_new(&methods_biop);
    if ( v4
      && (!writebuf1 || BIO_ctrl(v5, 136, writebuf1, 0))
      && (!writebuf2 || BIO_ctrl(v4, 136, writebuf2, 0))
      && BIO_ctrl(v5, 138, 0, v4) )
    {
      *bio1_p = v5;
      *bio2_p = v4;
      return 1;
    }
    BIO_free((unsigned int)v5, v5);
    v5 = 0;
    if ( v4 )
    {
      BIO_free(0, v4);
      v4 = 0;
    }
  }
  *bio1_p = v5;
  *bio2_p = v4;
  return 0;
}
