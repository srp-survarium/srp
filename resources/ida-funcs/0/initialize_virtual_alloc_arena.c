void __usercall initialize_virtual_alloc_arena(
        virtual_alloc_region *buffer@<eax>,
        const char *arena_id@<esi>,
        virtual_alloc_arena *result)
{
  buffer->size = (unsigned int)result;
  buffer->next_free_region = 0;
  buffer->previous_free_region = 0;
  g_ptmalloc3_arena.arena_id = arena_id;
  g_ptmalloc3_arena.out_of_memory_handler = (char (__stdcall *)(void *, const void *, int))out_of_memory_0;
  g_ptmalloc3_arena.out_of_memory_handler_parameter = 0;
  g_ptmalloc3_arena.start_pointer = (char *)buffer;
  g_ptmalloc3_arena.first_free_region = buffer;
  g_ptmalloc3_arena.total_size = (unsigned int)result;
  g_ptmalloc3_arena.free_size = (unsigned int)result;
  g_ptmalloc3_arena.region_count = 1;
}
