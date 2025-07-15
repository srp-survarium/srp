bio_st *__usercall BIO_pop@<eax>(int a1@<ebx>, bio_st *b)
{
  bio_st *result; // eax
  bio_st *next_bio; // edi
  bio_st *prev_bio; // eax
  bio_st *v5; // eax

  if ( !b )
    return 0;
  next_bio = b->next_bio;
  BIO_ctrl(a1, b, 7, 0, b);
  prev_bio = b->prev_bio;
  if ( prev_bio )
    prev_bio->next_bio = b->next_bio;
  v5 = b->next_bio;
  if ( v5 )
    v5->prev_bio = b->prev_bio;
  result = next_bio;
  b->next_bio = 0;
  b->prev_bio = 0;
  return result;
}
