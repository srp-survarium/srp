int sprintf_s(char *string, unsigned int sizeInBytes, const char *format, ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  return _vsprintf_s_l(string, sizeInBytes, format, 0, ap);
}
