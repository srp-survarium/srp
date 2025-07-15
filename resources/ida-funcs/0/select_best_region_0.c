vostok::memory::platform::region **__cdecl select_best_region_0(
        unsigned __int64 largest_but_two_size,
        vostok::memory::platform::region **largest_but_one,
        vostok::memory::platform::region **largest,
        const unsigned __int64 size,
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas,
        const unsigned int allocation_granularity)
{
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int size_high; // edi
  unsigned int v10; // [esp+14h] [ebp-Ch]
  unsigned __int64 v11; // [esp+18h] [ebp-8h]

  v6 = (*largest)->size;
  v7 = (*largest_but_one)->size;
  size_high = HIDWORD((*largest_but_one)->size);
  v10 = HIDWORD((*largest)->size);
  v11 = select_best_region(
          resource_arenas,
          largest_but_two_size,
          (*largest_but_one)->size,
          __PAIR64__(v10, v6) - size,
          allocation_granularity);
  if ( select_best_region(
         resource_arenas,
         largest_but_two_size,
         __PAIR64__(size_high, v7) - size,
         __PAIR64__(v10, v6),
         allocation_granularity) < v11 )
    return largest;
  else
    return largest_but_one;
}
