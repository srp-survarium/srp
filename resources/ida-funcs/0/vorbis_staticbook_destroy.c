void __usercall vorbis_staticbook_destroy(static_codebook *b@<esi>)
{
  if ( b->allocedp )
  {
    if ( b->quantlist )
      ogg_free_impl(b->quantlist);
    if ( b->lengthlist )
      ogg_free_impl(b->lengthlist);
    memset(b, 0, sizeof(static_codebook));
    ogg_free_impl(b);
  }
}
