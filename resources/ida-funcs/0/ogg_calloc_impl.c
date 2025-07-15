unsigned __int8 *__cdecl ogg_calloc_impl(unsigned int num, unsigned int size)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  void *v5; // esi
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  v2 = vostok::sound::g_allocator;
  v3 = type_info::raw_name(&char `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(v4, (int)v2, size * num, v3, v7, v8, v9);
  memset((int)v5, 0, size * num);
  return (unsigned __int8 *)v5;
}
