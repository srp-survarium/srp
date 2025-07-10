int __usercall swprintf_0@<eax>(
        unsigned int _Count@<edx>,
        unsigned int a2@<edi>,
        unsigned int a3@<esi>,
        wchar_t *_String,
        const wchar_t *_Format,
        ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return _vswprintf_c_l(a2, a3, _String, _Count, _Format, 0, ap);
}
