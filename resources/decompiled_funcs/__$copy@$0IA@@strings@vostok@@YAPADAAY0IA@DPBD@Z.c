char *__usercall vostok::strings::copy<128>@<eax>(char (*destination)[128]@<esi>, const char *source@<eax>)
{
  strcpy_s((char *)destination, 0x80u, source);
  return *destination;
}
