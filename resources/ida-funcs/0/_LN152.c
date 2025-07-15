void __usercall _LN152(
        vostok::memory::platform::region *managed_arena@<eax>,
        vostok::memory::platform::region *unmanaged_arena@<esi>,
        unsigned __int64 size_to_reduce,
        unsigned __int64 minimum_resources_size,
        const unsigned __int64 granularity)
{
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  char *address; // eax
  unsigned int size_high; // ecx
  unsigned int v10; // edi
  unsigned __int64 v11; // [esp-8h] [ebp-34h]
  unsigned int v12; // [esp+8h] [ebp-24h]
  unsigned int size; // [esp+10h] [ebp-1Ch]
  unsigned __int64 v14; // [esp+18h] [ebp-14h]
  unsigned __int64 v15; // [esp+20h] [ebp-Ch]
  unsigned __int64 value; // [esp+34h] [ebp+8h]
  unsigned __int64 valuea; // [esp+34h] [ebp+8h]

  value = vostok::math::align_up<unsigned __int64>(size_to_reduce, minimum_resources_size);
  v14 = managed_arena->size + unmanaged_arena->size - value;
  v7 = vostok::math::align_up<unsigned __int64>(
         (unsigned __int64)((double)v14 / (*(float *)&granularity + s_bm_current_air_resistance) * *(float *)&granularity),
         minimum_resources_size);
  v6 = v14 - v7;
  v15 = v7;
  HIDWORD(v7) = s_single_block_arena;
  v12 = v6;
  if ( s_single_block_arena )
  {
    managed_arena->size = __PAIR64__(HIDWORD(v15), v7);
    LODWORD(unmanaged_arena->size) = v6;
    LODWORD(v6) = unmanaged_arena->address;
    HIDWORD(unmanaged_arena->size) = HIDWORD(v6);
    address = (char *)managed_arena->address;
    if ( (unsigned int)address >= (unsigned int)v6 )
      managed_arena->address = (void *)(v6 + LODWORD(unmanaged_arena->size));
    else
      unmanaged_arena->address = &address[LODWORD(managed_arena->size)];
    VirtualFree((LPVOID)HIDWORD(v7), 0, 0x8000u);
    s_single_block_arena_size -= value;
    s_single_block_arena = allocate_region(s_single_block_arena_size, s_single_block_arena);
  }
  else
  {
    LODWORD(valuea) = managed_arena->size;
    size = managed_arena->size;
    size_high = HIDWORD(managed_arena->size);
    if ( __PAIR64__(HIDWORD(v15), v7) > managed_arena->size )
    {
      HIDWORD(valuea) = HIDWORD(managed_arena->size);
      HIDWORD(v6) = (v14 - valuea) >> 32;
      v10 = v14 - valuea;
    }
    else
    {
      managed_arena->size = __PAIR64__(HIDWORD(v15), v7);
      vostok::memory::platform::free_region(__PAIR64__(size_high, size));
      managed_arena->address = allocate_region(v15, managed_arena->address);
      v10 = v12;
    }
    if ( __PAIR64__(HIDWORD(v6), v10) <= unmanaged_arena->size )
    {
      v11 = unmanaged_arena->size;
      LODWORD(unmanaged_arena->size) = v10;
      HIDWORD(unmanaged_arena->size) = HIDWORD(v6);
      vostok::memory::platform::free_region(v11);
      unmanaged_arena->address = allocate_region(__PAIR64__(HIDWORD(v6), v10), unmanaged_arena->address);
    }
  }
}
