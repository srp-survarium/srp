virtual_alloc_region *__usercall int_new_arena@<eax>(unsigned int size@<eax>)
{
  void *v1; // eax
  void *v2; // edi
  virtual_alloc_region *v3; // esi

  v1 = (void *)(((size + 11) & 0xFFFFFFF8) + 552);
  if ( v1 < &loc_20000 )
    v1 = &loc_20000;
  v2 = (void *)(((unsigned int)v1 + 0x1FFF) & 0xFFFFE000);
  v3 = mmap(v2);
  if ( v3 == (virtual_alloc_region *)-1 )
    return 0;
  if ( !create_vostok_mspace_with_base((char *)&v3[2], (unsigned __int64)v2 - 24, 0, 0) )
  {
    munmap(v3, (unsigned int)v2);
    return 0;
  }
  return v3;
}
