void __cdecl vostok::memory::copy(
        unsigned __int8 *destination,
        unsigned int destination_size,
        unsigned __int8 *source,
        unsigned int size)
{
  memcpy(destination, source, size);
}
