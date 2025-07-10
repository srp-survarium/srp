char *__usercall vostok::strings::copy<64>@<eax>(char (*destination)[64]@<esi>, const char *source@<eax>)
{
  strcpy_s((char *)destination, 0x40u, source);
  return *destination;
}
