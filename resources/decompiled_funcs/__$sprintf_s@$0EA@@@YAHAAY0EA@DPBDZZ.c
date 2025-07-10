int sprintf_s<64>(char (*_Dest)[64], const char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x40u, _Format, ap);
}
