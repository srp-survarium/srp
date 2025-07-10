void ptmalloc_init()
{
  malloc_state *inited; // eax

  if ( __malloc_initialized < 0 )
  {
    __malloc_initialized = 0;
    save_malloc_hook = __malloc_hook;
    save_memalign_hook = __memalign_hook;
    save_free_hook = __free_hook;
    __malloc_hook = (void *(__cdecl *)(unsigned int, const void *))malloc_starter;
    __memalign_hook = (void *(__cdecl *)(unsigned int, unsigned int, const void *))memalign_starter;
    __free_hook = (void (__cdecl *)(void *, const void *))free_starter;
    main_arena.mutex = 0;
    main_arena.next = &main_arena;
    init_mparams();
    if ( -520 - mparams.page_size > 0x210 )
    {
      inited = init_user_mstate(main_arena.buf_, 0x210u);
      inited->seg.sflags = 8;
      inited->out_of_memory_handler = 0;
      inited->out_of_memory_parameter = 0;
    }
    list_lock = 0;
    arena_key = TlsAlloc();
    TlsSetValue(arena_key, &main_arena);
    __free_hook = save_free_hook;
    __malloc_hook = save_malloc_hook;
    __memalign_hook = save_memalign_hook;
    if ( s_crt_allocator_creation.m_arena_end )
      ((void (__cdecl *)())s_crt_allocator_creation.m_arena_end)();
    __malloc_initialized = 1;
  }
}
