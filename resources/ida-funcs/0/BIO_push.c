bio_st *__usercall BIO_push@<eax>(int a1@<ebx>, bio_st *b, bio_st *bio)
{
  bio_st **p_next_bio; // ecx
  bio_st *v5; // eax
  bool v6; // zf

  if ( !b )
    return bio;
  p_next_bio = &b->next_bio;
  v5 = b;
  if ( b->next_bio )
  {
    do
    {
      v5 = *p_next_bio;
      v6 = (*p_next_bio)->next_bio == 0;
      p_next_bio = &(*p_next_bio)->next_bio;
    }
    while ( !v6 );
  }
  v5->next_bio = bio;
  if ( bio )
    bio->prev_bio = v5;
  BIO_ctrl(a1, b, 6, 0, v5);
  return b;
}
