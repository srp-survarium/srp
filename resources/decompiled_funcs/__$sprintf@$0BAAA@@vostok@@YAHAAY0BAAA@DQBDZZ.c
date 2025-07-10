int __usercall vostok::sprintf<4096>@<eax>(char (*buffer)[4096]@<edx>, const char *format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x1000u, format, ap);
}
