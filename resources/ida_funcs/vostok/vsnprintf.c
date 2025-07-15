int __usercall vostok::vsnprintf@<eax>(
        const char *format@<ecx>,
        char *const args@<eax>,
        char *const destination,
        unsigned int destination_size,
        unsigned int max_count)
{
  return vsnprintf_s(destination, destination_size, max_count, format, args);
}
