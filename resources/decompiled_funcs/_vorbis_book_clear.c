void __usercall vorbis_book_clear(codebook *b@<edi>, vostok::memory::doug_lea_mt_allocator *a2@<ecx>)
{
  float *valuelist; // esi
  unsigned int *codelist; // esi
  int *dec_index; // esi
  char *dec_codelengths; // esi
  unsigned int *dec_firsttable; // esi
  vostok::memory *v7; // [esp+0h] [ebp-4h]

  valuelist = b->valuelist;
  if ( valuelist )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v7);
    vostok::memory::doug_lea_mt_allocator::free_impl(a2, valuelist);
  }
  codelist = b->codelist;
  if ( codelist )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v7);
    vostok::memory::doug_lea_mt_allocator::free_impl(a2, codelist);
  }
  dec_index = b->dec_index;
  if ( dec_index )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v7);
    vostok::memory::doug_lea_mt_allocator::free_impl(a2, dec_index);
  }
  dec_codelengths = b->dec_codelengths;
  if ( dec_codelengths )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v7);
    vostok::memory::doug_lea_mt_allocator::free_impl(a2, dec_codelengths);
  }
  dec_firsttable = b->dec_firsttable;
  if ( dec_firsttable )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v7);
    vostok::memory::doug_lea_mt_allocator::free_impl(a2, dec_firsttable);
  }
  memset((int)b, 0, sizeof(codebook));
}
