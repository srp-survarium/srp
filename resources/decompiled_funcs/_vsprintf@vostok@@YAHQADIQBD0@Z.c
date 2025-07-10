int __usercall vostok::vsprintf@<eax>(
        const char *format@<ecx>,
        char *const args@<eax>,
        char *const destination,
        unsigned int destination_size)
{
  return vsprintf_s(destination, destination_size, format, args);
}
