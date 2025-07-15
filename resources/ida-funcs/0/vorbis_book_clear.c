void __usercall vorbis_book_clear(codebook *b@<esi>)
{
  if ( b->valuelist )
    ogg_free_impl(b->valuelist);
  if ( b->codelist )
    ogg_free_impl(b->codelist);
  if ( b->dec_index )
    ogg_free_impl(b->dec_index);
  if ( b->dec_codelengths )
    ogg_free_impl(b->dec_codelengths);
  if ( b->dec_firsttable )
    ogg_free_impl(b->dec_firsttable);
  memset((int)b, 0, sizeof(codebook));
}
