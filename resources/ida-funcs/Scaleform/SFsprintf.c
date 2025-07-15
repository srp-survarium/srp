int Scaleform::SFsprintf(char *dest, unsigned int destsize, char *format, ...)
{
  int result; // eax
  va_list va; // [esp+18h] [ebp+10h] BYREF

  va_start(va, format);
  result = vsnprintf_s((int)dest, destsize, dest, destsize, 0xFFFFFFFF, format, va);
  if ( result == -1 )
  {
    dest[destsize - 1] = 0;
    return destsize - 1;
  }
  return result;
}
