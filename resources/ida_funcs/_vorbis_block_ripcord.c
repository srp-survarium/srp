void __usercall _vorbis_block_ripcord(
        vorbis_block *vb@<edi>,
        vostok::memory::doug_lea_mt_allocator *a2@<ecx>,
        vostok::debug *a3@<ebx>)
{
  alloc_chain *reap; // esi
  alloc_chain *next; // ebx
  void *ptr; // ebp
  vostok::memory::doug_lea_mt_allocator *v6; // ecx
  int totaluse; // eax
  vostok::memory::doug_lea_mt_allocator *v8; // ecx
  void *localstore; // ebp
  unsigned int v10; // esi
  void *v11; // eax
  vostok::debug *v12; // [esp-4h] [ebp-14h]
  char *v13; // [esp-4h] [ebp-14h]
  char *v14; // [esp-4h] [ebp-14h]
  volatile int *v15; // [esp+0h] [ebp-10h]
  vostok::memory::inplace_constructor v16; // [esp+4h] [ebp-Ch]
  vostok::memory::doug_lea_mt_allocator **pointer; // [esp+8h] [ebp-8h]
  vostok::memory::doug_lea_mt_allocator **v18; // [esp+Ch] [ebp-4h]

  reap = vb->reap;
  if ( reap )
  {
    v12 = a3;
    do
    {
      next = reap->next;
      ptr = reap->ptr;
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        vostok::debug::preinitialize(v12);
        if ( !vostok::core::g_log_callback )
        {
          vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
          vostok::debug::set_log_callback(vostok::core::debug_log_callback);
        }
        LOBYTE(pointer) = 0;
        vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
          pointer,
          (char (*)[112])v13,
          v15,
          v16);
      }
      vostok::memory::doug_lea_mt_allocator::free_impl(a2, ptr);
      reap->ptr = 0;
      reap->next = 0;
      if ( !vostok::memory::g_crt_allocator.__vftable )
      {
        vostok::debug::preinitialize(v12);
        if ( !vostok::core::g_log_callback )
        {
          vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
          vostok::debug::set_log_callback(vostok::core::debug_log_callback);
        }
        LOBYTE(v18) = 0;
        vostok::bind_pointer_to_buffer_mt_safe<vostok::memory::doug_lea_mt_allocator,vostok::memory::inplace_constructor>(
          v18,
          (char (*)[112])v14,
          v15,
          v16);
      }
      vostok::memory::doug_lea_mt_allocator::free_impl(v6, reap);
      reap = next;
    }
    while ( next );
  }
  totaluse = vb->totaluse;
  v8 = 0;
  if ( totaluse )
  {
    localstore = vb->localstore;
    v10 = totaluse + vb->localalloc;
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator((vostok::memory *)v15);
    v11 = vostok::memory::doug_lea_mt_allocator::realloc_impl(v8, localstore, v10);
    vb->localalloc += vb->totaluse;
    vb->localstore = v11;
    vb->totaluse = 0;
    vb->localtop = 0;
    vb->reap = 0;
  }
  else
  {
    vb->localtop = 0;
    vb->reap = 0;
  }
}
