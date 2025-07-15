bio_st *__cdecl asn1_bio_gets(bio_st *b, char *str, int size)
{
  bio_st *result; // eax

  result = b->next_bio;
  if ( result )
    return (bio_st *)BIO_gets(b->next_bio, str, size);
  return result;
}
