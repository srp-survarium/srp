vostok::memory::platform::region **__cdecl select_best_region_0(
        unsigned __int64 largest_but_two_size,
        vostok::memory::platform::region **largest_but_one,
        vostok::memory::platform::region **largest,
        unsigned __int64 size,
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas,
        unsigned int allocation_granularity)
{
  unsigned int v6; // ebp
  unsigned int v7; // esi
  unsigned int size_high; // edi
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  unsigned __int64 v12; // [esp+14h] [ebp-10h]
  unsigned int v13; // [esp+20h] [ebp-4h]

  v6 = (*largest)->size;
  v7 = (*largest_but_one)->size;
  size_high = HIDWORD((*largest_but_one)->size);
  v13 = HIDWORD((*largest)->size);
  LODWORD(v9) = select_best_region(
                  resource_arenas,
                  largest_but_two_size,
                  (*largest_but_one)->size,
                  __PAIR64__(v13, v6) - size,
                  allocation_granularity);
  v12 = v9;
  LODWORD(v10) = select_best_region(
                   resource_arenas,
                   largest_but_two_size,
                   __PAIR64__(size_high, v7) - size,
                   __PAIR64__(v13, v6),
                   allocation_granularity);
  if ( v10 < v12 )
    return largest;
  else
    return largest_but_one;
}
