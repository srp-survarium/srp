unsigned int *__cdecl vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator,
        unsigned int count)
{
  unsigned int *v2; // eax
  unsigned int *b; // [esp+Ch] [ebp-4h]

  v2 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 4 * count + 8);
  *v2 = count;
  v2[1] = 4;
  b = v2 + 2;
  vostok::memory::detail::call_constructor<unsigned int>(v2 + 2, &v2[count + 2]);
  return b;
}
