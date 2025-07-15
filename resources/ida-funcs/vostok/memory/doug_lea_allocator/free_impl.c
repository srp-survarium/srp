void __userpurge vostok::memory::doug_lea_allocator::free_impl(
        vostok::memory::doug_lea_allocator *this@<ecx>,
        int a2@<esi>,
        char *pointer,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  if ( pointer )
  {
    *(_BYTE *)(a2 + 42) = 0;
    if ( *(_BYTE *)(a2 + 43) )
    {
      if ( *(_BYTE *)(a2 + 16) )
        vostok::memory::monitor::on_free((void **)&pointer, (vostok::command_line::key *)this);
    }
    vostok_mspace_free(pointer, *(malloc_state **)(a2 + 20));
  }
}
