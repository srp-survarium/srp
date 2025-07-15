int __cdecl md_read(bio_st *b, char *out, int outl)
{
  env_md_ctx_st *ptr; // ebp
  bio_st *next_bio; // eax
  int v6; // eax
  int v7; // edi

  if ( !out )
    return 0;
  ptr = (env_md_ctx_st *)b->ptr;
  if ( !ptr )
    return 0;
  next_bio = b->next_bio;
  if ( !next_bio )
    return 0;
  v6 = BIO_read(next_bio, out, outl);
  v7 = v6;
  if ( b->init && v6 > 0 && EVP_DigestUpdate(ptr) <= 0 )
    return -1;
  BIO_clear_flags(b, 15);
  BIO_copy_next_retry(b);
  return v7;
}
