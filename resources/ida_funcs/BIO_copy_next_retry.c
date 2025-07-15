void __cdecl BIO_copy_next_retry(bio_st *b)
{
  bio_st *next_bio; // ecx

  next_bio = b->next_bio;
  b->flags |= next_bio->flags & 0xF;
  b->retry_reason = next_bio->retry_reason;
}
