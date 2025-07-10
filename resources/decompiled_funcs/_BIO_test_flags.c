int __cdecl BIO_test_flags(const bio_st *b, int flags)
{
  return flags & b->flags;
}
