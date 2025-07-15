char *__cdecl vostok::strings::copy_n(
        char *const destination,
        unsigned int destination_size,
        char *source,
        unsigned int count)
{
  strncpy_s(destination, destination_size, source, count);
  return destination;
}
