char *__usercall _vorbis_block_alloc@<eax>(
        vorbis_block *vb@<esi>,
        int bytes@<eax>,
        vostok::memory::doug_lea_mt_allocator *localstore@<ecx>)
{
  unsigned int v3; // edi
  alloc_chain *v4; // eax
  alloc_chain *reap; // edx
  int localtop; // ecx
  char *result; // eax
  vostok::memory *v8; // [esp+0h] [ebp-4h]

  v3 = (bytes + 7) & 0xFFFFFFF8;
  if ( (signed int)(v3 + vb->localtop) > vb->localalloc )
  {
    if ( vb->localstore )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v8);
      v4 = (alloc_chain *)vostok::memory::doug_lea_mt_allocator::malloc_impl(localstore, 8u);
      reap = vb->reap;
      vb->totaluse += vb->localtop;
      v4->next = reap;
      localstore = (vostok::memory::doug_lea_mt_allocator *)vb->localstore;
      v4->ptr = localstore;
      vb->reap = v4;
    }
    vb->localalloc = v3;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v8);
    vb->localstore = vostok::memory::doug_lea_mt_allocator::malloc_impl(localstore, v3);
    vb->localtop = 0;
  }
  localtop = vb->localtop;
  result = (char *)vb->localstore + localtop;
  vb->localtop = v3 + localtop;
  return result;
}
