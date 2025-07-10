void __usercall reduce_resources_arenas(
        vostok::memory::platform::region *managed_arena@<esi>,
        vostok::memory::platform::region *unmanaged_arena@<edi>,
        unsigned __int64 size_to_reduce,
        unsigned __int64 minimum_resources_size)
{
  unsigned __int64 v4; // kr00_8
  unsigned __int64 v5; // kr08_8
  unsigned int v6; // ebp
  SIZE_T v7; // ebx
  unsigned __int64 v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  SIZE_T v11; // ebp
  char *address; // ecx
  char *v13; // eax
  unsigned int size_high; // ecx
  void *v15; // edx
  unsigned int v16; // eax
  void *v17; // edx
  unsigned __int64 size; // [esp-8h] [ebp-24h]
  unsigned __int64 new_size; // [esp+8h] [ebp-14h]
  unsigned int new_unmanaged_size_4; // [esp+14h] [ebp-8h]
  unsigned int previous_size; // [esp+28h] [ebp+Ch]

  v4 = size_to_reduce;
  if ( size_to_reduce % minimum_resources_size )
  {
    v5 = minimum_resources_size - size_to_reduce % minimum_resources_size + size_to_reduce;
    size_to_reduce = v5;
    v4 = v5;
  }
  new_size = managed_arena->size + unmanaged_arena->size - v4;
  v6 = (unsigned __int64)((double)new_size * 0.66666669) >> 32;
  v7 = (unsigned __int64)((double)new_size * 0.66666669);
  v8 = (unsigned __int64)((double)new_size * 0.66666669) % minimum_resources_size;
  if ( v8 )
  {
    v6 = (minimum_resources_size + __PAIR64__(v6, v7) - v8) >> 32;
    v7 = minimum_resources_size + v7 - v8;
  }
  v9 = v6;
  v10 = (new_size - __PAIR64__(v6, v7)) >> 32;
  v11 = new_size - v7;
  new_unmanaged_size_4 = v10;
  if ( s_crt_allocator_creation.m_arena_start )
  {
    HIDWORD(managed_arena->size) = v9;
    LODWORD(managed_arena->size) = v7;
    HIDWORD(unmanaged_arena->size) = v10;
    address = (char *)unmanaged_arena->address;
    LODWORD(unmanaged_arena->size) = v11;
    v13 = (char *)managed_arena->address;
    if ( v13 >= address )
      managed_arena->address = &address[v11];
    else
      unmanaged_arena->address = &v13[LODWORD(managed_arena->size)];
    VirtualFree(s_crt_allocator_creation.m_arena_start, 0, 0x8000u);
    *(_QWORD *)&s_crt_allocator_creation.m_arena_id -= size_to_reduce;
    s_crt_allocator_creation.m_arena_start = VirtualAlloc(
                                               s_crt_allocator_creation.m_arena_start,
                                               (SIZE_T)s_crt_allocator_creation.m_arena_id,
                                               0x3000u,
                                               4u);
  }
  else
  {
    size_high = HIDWORD(managed_arena->size);
    previous_size = managed_arena->size;
    if ( __PAIR64__(v9, v7) > managed_arena->size )
    {
      v16 = (new_size - managed_arena->size) >> 32;
      v11 = new_size - LODWORD(managed_arena->size);
    }
    else
    {
      v15 = managed_arena->address;
      LODWORD(managed_arena->size) = v7;
      HIDWORD(managed_arena->size) = v9;
      vostok::memory::platform::free_region(v15, __PAIR64__(size_high, previous_size));
      managed_arena->address = VirtualAlloc(managed_arena->address, v7, 0x3000u, 4u);
      v16 = new_unmanaged_size_4;
    }
    if ( __PAIR64__(v16, v11) <= unmanaged_arena->size )
    {
      size = unmanaged_arena->size;
      v17 = unmanaged_arena->address;
      LODWORD(unmanaged_arena->size) = v11;
      HIDWORD(unmanaged_arena->size) = v16;
      vostok::memory::platform::free_region(v17, size);
      unmanaged_arena->address = VirtualAlloc(unmanaged_arena->address, v11, 0x3000u, 4u);
    }
  }
}
