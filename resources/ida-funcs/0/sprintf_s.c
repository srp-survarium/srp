int sprintf_s(char *string, unsigned int sizeInBytes, const char *format, ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  return _vsprintf_s_l(string, sizeInBytes, format, 0, ap);
}


int sprintf_s<256>(char (*_Dest)[256], const char *_Format, ...)
{
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, _Format);
  return vsprintf_s((char *)_Dest, 0x100u, _Format, va);
}


int sprintf_s<4096>(char (*_Dest)[4096], const char *_Format, ...)
{
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, _Format);
  return vsprintf_s((char *)_Dest, 0x1000u, _Format, va);
}


int __usercall sprintf_s<260>@<eax>(char (*_Dest)[260]@<edx>, const char *_Format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x104u, _Format, ap);
}


int __usercall sprintf_s<32>@<eax>(char (*_Dest)[32]@<edx>, const char *_Format, ...)
{
  va_list ap; // [esp+8h] [ebp+8h] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x20u, _Format, ap);
}


int sprintf_s<512>(char (*_Dest)[512], const char *_Format, ...)
{
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, _Format);
  return vsprintf_s((char *)_Dest, 0x200u, _Format, va);
}


int sprintf_s<64>(char (*_Dest)[64], const char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x40u, _Format, ap);
}
