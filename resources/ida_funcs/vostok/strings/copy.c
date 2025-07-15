char *__usercall vostok::strings::copy@<eax>(
        char *destination@<esi>,
        unsigned int destination_size@<ecx>,
        const char *source@<eax>)
{
  strcpy_s(destination, destination_size, source);
  return destination;
}


char *__cdecl vostok::strings::copy<32>(char (*destination)[32], const char *source)
{
  return vostok::strings::copy((char *)destination, 0x20u, source);
}


char *__usercall vostok::strings::copy<512>@<eax>(char (*destination)[512]@<esi>, const char *source@<eax>)
{
  strcpy_s((char *)destination, 0x200u, source);
  return *destination;
}


char *__usercall vostok::strings::copy<64>@<eax>(char (*destination)[64]@<esi>, const char *source@<eax>)
{
  strcpy_s((char *)destination, 0x40u, source);
  return *destination;
}


char *__usercall vostok::strings::copy<128>@<eax>(char (*destination)[128]@<esi>, const char *source@<eax>)
{
  strcpy_s((char *)destination, 0x80u, source);
  return *destination;
}
