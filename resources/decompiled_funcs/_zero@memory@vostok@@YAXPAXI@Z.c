void __cdecl vostok::memory::zero(void *destination, unsigned int size_in_bytes)
{
  memset((int)destination, 0, size_in_bytes);
}
