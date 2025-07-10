int __usercall vostok::sprintf<512>@<eax>(char (*buffer)[512]@<edx>, const char *format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x200u, format, ap);
}
