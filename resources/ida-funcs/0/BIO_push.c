bio_st *__cdecl BIO_push(bio_st *b, bio_st *bio)
{
  bio_st **p_next_bio; // ecx
  bio_st *v4; // eax
  bool v5; // zf

  if ( !b )
    return bio;
  p_next_bio = &b->next_bio;
  v4 = b;
  if ( b->next_bio )
  {
    do
    {
      v4 = *p_next_bio;
      v5 = (*p_next_bio)->next_bio == 0;
      p_next_bio = &(*p_next_bio)->next_bio;
    }
    while ( !v5 );
  }
  v4->next_bio = bio;
  if ( bio )
    bio->prev_bio = v4;
  BIO_ctrl(b, 6, 0, v4);
  return b;
}
