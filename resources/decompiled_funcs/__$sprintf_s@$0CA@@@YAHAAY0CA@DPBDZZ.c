int __usercall sprintf_s<32>@<eax>(char (*_Dest)[32]@<edx>, const char *_Format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x20u, _Format, ap);
}
