char *__cdecl vostok::strings::copy(char *destination, unsigned int destination_size, char *source)
{
  strcpy_s(destination, destination_size, source);
  return destination;
}


char *__cdecl vostok::strings::copy<16>(char (*destination)[16], char *source)
{
  strcpy_s((char *)destination, 0x10u, source);
  return *destination;
}


char *__cdecl vostok::strings::copy<260>(char (*destination)[260], char *source)
{
  strcpy_s((char *)destination, 0x104u, source);
  return *destination;
}


char *__cdecl vostok::strings::copy<32>(char (*destination)[32], char *source)
{
  strcpy_s((char *)destination, 0x20u, source);
  return *destination;
}


char *__cdecl vostok::strings::copy<512>(char (*destination)[512], char *source)
{
  strcpy_s((char *)destination, 0x200u, source);
  return *destination;
}


char *__cdecl vostok::strings::copy<64>(char (*destination)[64], char *source)
{
  strcpy_s((char *)destination, 0x40u, source);
  return *destination;
}


char *__cdecl vostok::strings::copy<128>(char (*destination)[128], char *source)
{
  strcpy_s((char *)destination, 0x80u, source);
  return *destination;
}
