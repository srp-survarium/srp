int sprintf_s<256>(char (*_Dest)[256], const char *_Format, ...)
{
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, _Format);
  return vsprintf_s((char *)_Dest, 0x100u, _Format, va);
}
