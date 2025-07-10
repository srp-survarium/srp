int vostok::sprintf(char *buffer, unsigned int buffer_size, const char *format, ...)
{
  va_list va; // [esp+18h] [ebp+14h] BYREF

  va_start(va, format);
  return vostok::vsprintf(format, va, buffer, buffer_size);
}
