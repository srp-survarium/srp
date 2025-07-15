int __usercall swprintf_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        unsigned __int16 *string,
        unsigned int sizeInWords,
        const wchar_t *format,
        ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  return _vswprintf_s_l(a1, a2, string, sizeInWords, format, 0, ap);
}


int __usercall swprintf_s<32>@<eax>(wchar_t (*_Dest)[32]@<edx>, const wchar_t *_Format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, _Format);
  return vswprintf_s((unsigned __int16 *)_Dest, 0x20u, _Format, ap);
}
