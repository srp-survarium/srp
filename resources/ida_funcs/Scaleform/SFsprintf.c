int Scaleform::SFsprintf(char *dest, unsigned int destsize, const char *format, ...)
{
  int result; // eax
  va_list ap; // [esp+18h] [ebp+10h] BYREF

  va_start(ap, format);
  result = vsnprintf_s(dest, destsize, 0xFFFFFFFF, format, ap);
  if ( result == -1 )
  {
    dest[destsize - 1] = 0;
    return destsize - 1;
  }
  return result;
}
