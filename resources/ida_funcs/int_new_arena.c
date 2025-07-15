virtual_alloc_arena *__usercall int_new_arena@<eax>(unsigned int size@<eax>, const void *a2@<edi>)
{
  void *v2; // eax
  unsigned int v3; // esi
  virtual_alloc_arena *v4; // edi

  v2 = (void *)(((size + 11) & 0xFFFFFFF8) + 552);
  if ( v2 < &loc_20000 )
    v2 = &loc_20000;
  v3 = ((unsigned int)v2 + 0x1FFF) & 0xFFFFE000;
  v4 = (virtual_alloc_arena *)mmap(v3);
  if ( v4 == (virtual_alloc_arena *)-1 )
    return 0;
  if ( !create_vostok_mspace_with_base(&v4->free_size, v3 - 24, 0, 0, a2) )
  {
    munmap(v4, v4, v3);
    return 0;
  }
  return v4;
}
