int __cdecl cpy_bmp(__int16 value, _BYTE **arg)
{
  _BYTE *v2; // ecx

  v2 = *arg;
  *v2 = HIBYTE(value);
  v2[1] = value;
  *arg += 2;
  return 1;
}
