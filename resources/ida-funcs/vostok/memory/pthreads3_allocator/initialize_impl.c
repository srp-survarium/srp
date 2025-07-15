void __thiscall vostok::memory::pthreads3_allocator::initialize_impl(
        vostok::memory::pthreads3_allocator *this,
        virtual_alloc_region *buffer,
        unsigned __int64 buffer_size,
        const char *arena_id)
{
  buffer->size = buffer_size;
  buffer->next_free_region = 0;
  buffer->previous_free_region = 0;
  g_ptmalloc3_arena.arena_id = arena_id;
  g_ptmalloc3_arena.out_of_memory_handler = (char (__stdcall *)(void *, const void *, int))out_of_memory;
  g_ptmalloc3_arena.out_of_memory_handler_parameter = 0;
  g_ptmalloc3_arena.start_pointer = (char *)buffer;
  g_ptmalloc3_arena.first_free_region = buffer;
  g_ptmalloc3_arena.total_size = buffer_size;
  g_ptmalloc3_arena.free_size = buffer_size;
  g_ptmalloc3_arena.region_count = 1;
}
