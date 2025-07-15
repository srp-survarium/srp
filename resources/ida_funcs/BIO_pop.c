bio_st *__cdecl BIO_pop(bio_st *b)
{
  bio_st *result; // eax
  bio_st *next_bio; // edi
  bio_st *prev_bio; // eax
  bio_st *v4; // eax

  if ( !b )
    return 0;
  next_bio = b->next_bio;
  BIO_ctrl(b, 7, 0, b);
  prev_bio = b->prev_bio;
  if ( prev_bio )
    prev_bio->next_bio = b->next_bio;
  v4 = b->next_bio;
  if ( v4 )
    v4->prev_bio = b->prev_bio;
  result = next_bio;
  b->next_bio = 0;
  b->prev_bio = 0;
  return result;
}
