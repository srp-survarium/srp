int sprintf_s<4096>(char (*_Dest)[4096], const char *_Format, ...)
{
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, _Format);
  return vsprintf_s((char *)_Dest, 0x1000u, _Format, va);
}
