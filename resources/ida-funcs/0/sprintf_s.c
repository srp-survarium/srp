int __usercall sprintf_s@<eax>(int a1@<edi>, int a2@<esi>, char *string, unsigned int sizeInBytes, char *format, ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, format);
  return _vsprintf_s_l(a1, a2, string, sizeInBytes, format, 0, va);
}


int sprintf_s<16>(char (*_Dest)[16], char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x10u, _Format, ap);
}


int sprintf_s<256>(char (*_Dest)[256], char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x100u, _Format, ap);
}


int sprintf_s<4096>(char (*buffer)[4096], char *format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x1000u, format, ap);
}


int sprintf_s<260>(char (*_Dest)[260], char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x104u, _Format, ap);
}


int sprintf_s<32>(char (*_Dest)[32], char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x20u, _Format, ap);
}


int sprintf_s<64>(char (*_Dest)[64], char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x40u, _Format, ap);
}


int sprintf_s<16384>(char (*_Dest)[16384], char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x4000u, _Format, ap);
}


int sprintf_s<128>(char (*_Dest)[128], char *_Format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, _Format);
  return vsprintf_s((char *)_Dest, 0x80u, _Format, ap);
}
