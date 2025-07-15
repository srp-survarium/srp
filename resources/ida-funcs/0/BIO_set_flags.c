void __cdecl BIO_set_flags(bio_st *b, int flags)
{
  b->flags |= flags;
}
