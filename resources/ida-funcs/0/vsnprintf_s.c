int __usercall vsnprintf_s@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        char *string,
        unsigned int sizeInBytes,
        unsigned int count,
        char *format,
        char *ap)
{
  return _vsnprintf_s_l(a1, a2, string, sizeInBytes, count, format, 0, ap);
}
