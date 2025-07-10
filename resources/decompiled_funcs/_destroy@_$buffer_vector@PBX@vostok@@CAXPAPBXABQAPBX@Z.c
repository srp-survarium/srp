void __cdecl vostok::buffer_vector<void const *>::destroy(const void **begin, const void **const *end)
{
  while ( begin != *end )
    ++begin;
}
