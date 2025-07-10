int __cdecl cpy_utf8(unsigned int value, unsigned __int8 **arg)
{
  *arg += UTF8_putc(*arg, 255, value);
  return 1;
}
