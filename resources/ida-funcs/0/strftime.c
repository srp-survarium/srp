unsigned int __usercall strftime@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        char *string,
        int maxsize,
        const char *format,
        const tm *timeptr)
{
  return _Strftime_l(a1, a2, string, maxsize, format, timeptr, 0, 0);
}
