int __cdecl md_write(bio_st *b, const char *in, int inl)
{
  int v3; // edi
  env_md_ctx_st *ptr; // ebp
  bio_st *next_bio; // eax

  v3 = 0;
  if ( !in || inl <= 0 )
    return 0;
  ptr = (env_md_ctx_st *)b->ptr;
  if ( ptr )
  {
    next_bio = b->next_bio;
    if ( next_bio )
      v3 = BIO_write(next_bio, in, inl);
  }
  if ( b->init && v3 > 0 )
    EVP_DigestUpdate(ptr);
  if ( b->next_bio )
  {
    BIO_clear_flags(b, 15);
    BIO_copy_next_retry(b);
  }
  return v3;
}
