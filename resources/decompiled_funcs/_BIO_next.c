bio_st *__cdecl BIO_next(bio_st *b)
{
  bio_st *result; // eax

  result = b;
  if ( b )
    return b->next_bio;
  return result;
}
