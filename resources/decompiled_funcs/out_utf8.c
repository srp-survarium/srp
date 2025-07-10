int __cdecl out_utf8(unsigned int value, _DWORD *arg)
{
  *arg += UTF8_putc(0, -1, value);
  return 1;
}
