void ptmalloc_init()
{
  if ( __malloc_initialized < 0 )
  {
    save_malloc_hook = __malloc_hook;
    save_memalign_hook = __memalign_hook;
    __malloc_initialized = 0;
    save_free_hook = __free_hook;
    __malloc_hook = (void *(__cdecl *)(unsigned int, const void *))malloc_starter;
    __memalign_hook = (void *(__cdecl *)(unsigned int, unsigned int, const void *))memalign_starter;
    __free_hook = (void (__cdecl *)(void *, const void *))free_starter;
    main_arena.mutex = 0;
    main_arena.next = &main_arena;
    create_vostok_mspace_with_base(main_arena.buf_, 0x210u, 0, 0);
    list_lock = 0;
    arena_key = TlsAlloc();
    TlsSetValue(arena_key, &main_arena);
    __malloc_hook = save_malloc_hook;
    __memalign_hook = save_memalign_hook;
    __free_hook = save_free_hook;
    if ( __malloc_initialize_hook )
      __malloc_initialize_hook();
    __malloc_initialized = 1;
  }
}
