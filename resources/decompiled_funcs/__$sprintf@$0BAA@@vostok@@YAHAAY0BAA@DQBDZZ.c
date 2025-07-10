int __usercall vostok::sprintf<256>@<eax>(char (*buffer)[256]@<edx>, const char *format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x100u, format, ap);
}
