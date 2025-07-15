int __usercall vsprintf_s@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        char *string,
        unsigned int sizeInBytes,
        char *format,
        char *ap)
{
  return _vsprintf_s_l(a1, a2, string, sizeInBytes, format, 0, ap);
}
