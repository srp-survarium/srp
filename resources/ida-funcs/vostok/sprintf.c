int vostok::sprintf(char *buffer, unsigned int buffer_size, char *format, ...)
{
  va_list ap; // [esp+10h] [ebp+10h] BYREF

  va_start(ap, format);
  return vsprintf_s(buffer, buffer_size, format, ap);
}


int vostok::sprintf<512>(char (*buffer)[512], char *format, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, format);
  return vsprintf_s((char *)buffer, 0x200u, format, ap);
}
