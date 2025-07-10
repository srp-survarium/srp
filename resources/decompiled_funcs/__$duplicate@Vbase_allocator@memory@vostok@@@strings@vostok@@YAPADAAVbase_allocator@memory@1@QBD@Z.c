char *__cdecl vostok::strings::duplicate<vostok::memory::base_allocator>(char *string)
{
  vostok::memory::base_allocator *allocator; // ecx
  unsigned int v2; // kr00_4
  unsigned __int8 *v3; // edi

  v2 = strlen(string);
  v3 = (unsigned __int8 *)allocator->call_malloc(allocator, v2 + 1);
  memcpy(v3, (unsigned __int8 *)string, v2 + 1);
  return (char *)v3;
}
