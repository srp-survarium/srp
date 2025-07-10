char *__cdecl vostok::memory::new_array_helper<char>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator,
        unsigned int count)
{
  char *v2; // eax
  char *b; // [esp+Ch] [ebp-4h]

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, count + 8);
  *(_DWORD *)v2 = count;
  *((_DWORD *)v2 + 1) = 1;
  b = v2 + 8;
  vostok::memory::detail::call_constructor<char>(v2 + 8, &v2[count + 8]);
  return b;
}
