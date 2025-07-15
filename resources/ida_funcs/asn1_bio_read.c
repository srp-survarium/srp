bio_st *__cdecl asn1_bio_read(bio_st *b, char *in, int inl)
{
  bio_st *result; // eax

  result = b->next_bio;
  if ( result )
    return (bio_st *)BIO_read(b->next_bio, in, inl);
  return result;
}
