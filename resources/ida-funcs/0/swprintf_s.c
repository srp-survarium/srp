int __usercall swprintf_s@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        unsigned __int16 *string,
        unsigned int sizeInWords,
        wchar_t *format,
        ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  return _vswprintf_s_l(a1, a2, (char *)string, sizeInWords, format, 0, ap);
}
