virtual_alloc_region *__thiscall virtual_alloc(void *size)
{
  unsigned int v1; // ecx
  virtual_alloc_region *result; // eax
  virtual_alloc_region *next_free_region; // ecx
  virtual_alloc_region *previous_free_region; // edx
  unsigned int v5; // ecx

  v1 = vostok::math::align_up<unsigned long>((unsigned int)&_sbh_sizeHeaderList);
  result = g_ptmalloc3_arena.first_free_region;
  if ( !g_ptmalloc3_arena.first_free_region )
    goto LABEL_17;
  do
  {
    if ( result->size >= v1 )
      break;
    result = result->next_free_region;
  }
  while ( result );
  if ( result )
  {
    if ( result->size == v1 )
    {
      g_ptmalloc3_arena.free_size -= v1;
      --g_ptmalloc3_arena.region_count;
      if ( result->previous_free_region )
        result->previous_free_region->next_free_region = result->next_free_region;
      else
        g_ptmalloc3_arena.first_free_region = result->next_free_region;
      next_free_region = result->next_free_region;
      if ( next_free_region )
      {
        previous_free_region = result->previous_free_region;
LABEL_11:
        next_free_region->previous_free_region = previous_free_region;
      }
    }
    else
    {
      v5 = (((v1 - 1) >> 12) + 1) << 12;
      g_ptmalloc3_arena.free_size -= v5;
      previous_free_region = (virtual_alloc_region *)((char *)result + v5);
      previous_free_region->next_free_region = result->next_free_region;
      previous_free_region->previous_free_region = result->previous_free_region;
      previous_free_region->size = result->size - v5;
      if ( result->previous_free_region )
        result->previous_free_region->next_free_region = previous_free_region;
      else
        g_ptmalloc3_arena.first_free_region = (virtual_alloc_region *)((char *)result + v5);
      next_free_region = result->next_free_region;
      if ( next_free_region )
        goto LABEL_11;
    }
  }
  else
  {
LABEL_17:
    if ( g_ptmalloc3_arena.out_of_memory_handler )
      g_ptmalloc3_arena.out_of_memory_handler(&g_ptmalloc3_arena, g_ptmalloc3_arena.out_of_memory_handler_parameter, 0);
    return (virtual_alloc_region *)-1;
  }
  return result;
}
