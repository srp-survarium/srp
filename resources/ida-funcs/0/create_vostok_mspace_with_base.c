malloc_state *__cdecl create_vostok_mspace_with_base(
        char *base,
        unsigned __int64 capacity,
        char (__stdcall *locked)(void *, const void *, int),
        char (__stdcall *handler)(void *, const void *, int))
{
  malloc_state *inited; // esi

  inited = 0;
  init_mparams();
  if ( capacity > 0x208 && capacity < -520 - mparams.page_size )
  {
    inited = init_user_mstate(base, capacity);
    inited->out_of_memory_handler = locked;
    inited->seg.sflags = 8;
    inited->out_of_memory_parameter = handler;
  }
  return inited;
}
