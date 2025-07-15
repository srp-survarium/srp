int vostok::sprintf(char *buffer, unsigned int buffer_size, const char *format, ...)
{
  va_list va; // [esp+18h] [ebp+14h] BYREF

  va_start(va, format);
  return vostok::vsprintf(format, va, buffer, buffer_size);
}


int __usercall vostok::sprintf<256>@<eax>(char (*buffer)[256]@<edx>, const char *format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x100u, format, ap);
}


int __usercall vostok::sprintf<4096>@<eax>(char (*buffer)[4096]@<edx>, const char *format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x1000u, format, ap);
}


int __usercall vostok::sprintf<512>@<eax>(char (*buffer)[512]@<edx>, const char *format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x200u, format, ap);
}


int __usercall vostok::sprintf<64>@<eax>(char (*buffer)[64]@<edx>, const char *format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x40u, format, ap);
}
