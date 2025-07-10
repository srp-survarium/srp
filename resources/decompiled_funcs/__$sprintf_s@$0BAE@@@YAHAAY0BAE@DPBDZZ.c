int __usercall sprintf_s<260>@<eax>(char (*_Dest)[260]@<edx>, const char *_Format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x104u, _Format, ap);
}
