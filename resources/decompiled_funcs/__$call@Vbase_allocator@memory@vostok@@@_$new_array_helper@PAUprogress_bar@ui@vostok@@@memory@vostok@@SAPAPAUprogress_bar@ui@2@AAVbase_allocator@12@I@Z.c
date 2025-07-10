vostok::ui::progress_bar **__cdecl vostok::memory::new_array_helper<vostok::ui::progress_bar *>::call<vostok::memory::base_allocator>(
        vostok::memory::base_allocator *allocator,
        unsigned int count)
{
  unsigned int *v2; // eax
  unsigned int *i; // [esp+8h] [ebp-Ch]

  v2 = (unsigned int *)vostok::memory::base_allocator::malloc_impl(allocator, 4 * count + 8);
  *v2 = count;
  v2[1] = 4;
  for ( i = v2 + 2; i != &v2[count + 2]; ++i )
  {
    if ( i )
      *i = 0;
  }
  return (vostok::ui::progress_bar **)(v2 + 2);
}
