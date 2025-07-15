void __usercall mdct_clear(mdct_lookup *l@<esi>, vostok::memory::doug_lea_mt_allocator *a2@<ecx>)
{
  float *trig; // edi
  int *bitrev; // edi
  vostok::memory *v4; // [esp+0h] [ebp-4h]

  if ( l )
  {
    trig = l->trig;
    if ( trig )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v4);
      vostok::memory::doug_lea_mt_allocator::free_impl(a2, trig);
    }
    bitrev = l->bitrev;
    if ( bitrev )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v4);
      vostok::memory::doug_lea_mt_allocator::free_impl(a2, bitrev);
    }
    l->n = 0;
    l->log2n = 0;
    l->trig = 0;
    l->bitrev = 0;
    l->scale = 0.0;
  }
}
