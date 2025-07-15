int __usercall virtual_free@<eax>(virtual_alloc_region *pointer_raw@<esi>, unsigned int size@<edi>)
{
  virtual_alloc_region *first_free_region; // eax
  virtual_alloc_region *v3; // ecx
  char v4; // bl
  bool v5; // dl
  virtual_alloc_region *next_free_region; // eax

  first_free_region = g_ptmalloc3_arena.first_free_region;
  g_ptmalloc3_arena.free_size += size;
  v3 = 0;
  if ( !g_ptmalloc3_arena.first_free_region )
    goto LABEL_7;
  do
  {
    if ( first_free_region >= pointer_raw )
      break;
    v3 = first_free_region;
    first_free_region = first_free_region->next_free_region;
  }
  while ( first_free_region );
  if ( v3 && (virtual_alloc_region *)((char *)v3 + v3->size) == pointer_raw )
    v4 = 1;
  else
LABEL_7:
    v4 = 0;
  v5 = first_free_region && (virtual_alloc_region *)((char *)pointer_raw + size) == first_free_region;
  if ( v4 )
  {
    if ( v5 )
    {
      --g_ptmalloc3_arena.region_count;
      v3->next_free_region = first_free_region->next_free_region;
      v3->size += size + first_free_region->size;
      next_free_region = first_free_region->next_free_region;
      if ( next_free_region )
        next_free_region->previous_free_region = v3;
    }
    else
    {
      v3->size += size;
    }
  }
  else
  {
    pointer_raw->previous_free_region = v3;
    if ( v5 )
    {
      pointer_raw->next_free_region = first_free_region->next_free_region;
      pointer_raw->size = size + first_free_region->size;
      first_free_region = first_free_region->next_free_region;
    }
    else
    {
      pointer_raw->next_free_region = first_free_region;
      pointer_raw->size = size;
      ++g_ptmalloc3_arena.region_count;
    }
    if ( v3 )
      v3->next_free_region = pointer_raw;
    else
      g_ptmalloc3_arena.first_free_region = pointer_raw;
    if ( first_free_region )
      first_free_region->previous_free_region = pointer_raw;
  }
  return 0;
}
