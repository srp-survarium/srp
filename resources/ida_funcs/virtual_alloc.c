virtual_alloc_region *__fastcall virtual_alloc(unsigned int size)
{
  virtual_alloc_region *result; // eax
  virtual_alloc_region *next_free_region; // ecx
  unsigned int v3; // ecx
  virtual_alloc_region *v4; // edx
  virtual_alloc_region *v5; // ecx

  if ( (_WORD)size )
    size += (unsigned int)&_sbh_sizeHeaderList - (unsigned __int16)size;
  result = g_ptmalloc3_arena.first_free_region;
  if ( g_ptmalloc3_arena.first_free_region )
  {
    while ( result->size < size )
    {
      result = result->next_free_region;
      if ( !result )
        goto LABEL_6;
    }
    if ( result->size == size )
    {
      g_ptmalloc3_arena.free_size -= size;
      --g_ptmalloc3_arena.region_count;
      if ( result->previous_free_region )
        result->previous_free_region->next_free_region = result->next_free_region;
      else
        g_ptmalloc3_arena.first_free_region = result->next_free_region;
      next_free_region = result->next_free_region;
      if ( next_free_region )
        next_free_region->previous_free_region = result->previous_free_region;
    }
    else
    {
      v3 = (((size - 1) >> 12) + 1) << 12;
      g_ptmalloc3_arena.free_size -= v3;
      v4 = (virtual_alloc_region *)((char *)result + v3);
      v4->next_free_region = result->next_free_region;
      v4->previous_free_region = result->previous_free_region;
      v4->size = result->size - v3;
      if ( result->previous_free_region )
        result->previous_free_region->next_free_region = v4;
      else
        g_ptmalloc3_arena.first_free_region = (virtual_alloc_region *)((char *)result + v3);
      v5 = result->next_free_region;
      if ( v5 )
        v5->previous_free_region = v4;
    }
  }
  else
  {
LABEL_6:
    if ( g_ptmalloc3_arena.out_of_memory_handler )
      g_ptmalloc3_arena.out_of_memory_handler(&g_ptmalloc3_arena, g_ptmalloc3_arena.out_of_memory_handler_parameter, 0);
    return (virtual_alloc_region *)-1;
  }
  return result;
}
