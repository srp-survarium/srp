int __usercall vswprintf_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        unsigned __int16 *string,
        unsigned int sizeInWords,
        const wchar_t *format,
        char *ap)
{
  return _vswprintf_s_l(a1, a2, string, sizeInWords, format, 0, ap);
}
