int __usercall _vsnprintf@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        char *string,
        unsigned int count,
        const char *format,
        char *ap)
{
  return _vsnprintf_l(a1, a2, string, count, format, 0, ap);
}
