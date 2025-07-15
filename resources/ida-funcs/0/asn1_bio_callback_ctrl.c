bio_st *__cdecl asn1_bio_callback_ctrl(
        bio_st *b,
        int cmd,
        void (__cdecl *fp)(bio_st *, int, const char *, int, int, int))
{
  bio_st *result; // eax

  result = b->next_bio;
  if ( result )
    return (bio_st *)BIO_callback_ctrl(b->next_bio, cmd, fp);
  return result;
}
