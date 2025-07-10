int __usercall swprintf_s<32>@<eax>(wchar_t (*_Dest)[32]@<edx>, const wchar_t *_Format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, _Format);
  return vswprintf_s((unsigned __int16 *)_Dest, 0x20u, _Format, ap);
}
