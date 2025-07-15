void __cdecl BIO_clear_flags(bio_st *b, int flags)
{
  b->flags &= ~flags;
}
