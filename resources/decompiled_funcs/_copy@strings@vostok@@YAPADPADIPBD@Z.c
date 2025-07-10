char *__usercall vostok::strings::copy@<eax>(
        char *destination@<esi>,
        unsigned int destination_size@<ecx>,
        const char *source@<eax>)
{
  strcpy_s(destination, destination_size, source);
  return destination;
}
