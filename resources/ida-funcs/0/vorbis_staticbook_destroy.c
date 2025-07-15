void __usercall vorbis_staticbook_destroy(static_codebook *b@<esi>, vostok::memory::doug_lea_mt_allocator *a2@<ecx>)
{
  int *quantlist; // edi
  int *lengthlist; // edi
  vostok::memory *v4; // [esp+0h] [ebp-4h]

  if ( b->allocedp )
  {
    quantlist = b->quantlist;
    if ( quantlist )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v4);
      vostok::memory::doug_lea_mt_allocator::free_impl(a2, quantlist);
    }
    lengthlist = b->lengthlist;
    if ( lengthlist )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v4);
      vostok::memory::doug_lea_mt_allocator::free_impl(a2, lengthlist);
    }
    b->dim = 0;
    b->entries = 0;
    b->lengthlist = 0;
    b->maptype = 0;
    b->q_min = 0;
    b->q_delta = 0;
    b->q_quant = 0;
    b->q_sequencep = 0;
    b->quantlist = 0;
    b->allocedp = 0;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v4);
    vostok::memory::doug_lea_mt_allocator::free_impl(a2, b);
  }
}
