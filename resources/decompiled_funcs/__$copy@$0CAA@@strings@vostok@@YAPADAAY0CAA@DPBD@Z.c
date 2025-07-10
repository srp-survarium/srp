char *__usercall vostok::strings::copy<512>@<eax>(char (*destination)[512]@<esi>, const char *source@<eax>)
{
  strcpy_s((char *)destination, 0x200u, source);
  return *destination;
}
