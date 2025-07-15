int __cdecl cpy_univ(unsigned int value, _BYTE **arg)
{
  _BYTE *v2; // eax

  v2 = *arg;
  *v2++ = HIBYTE(value);
  *v2++ = BYTE2(value);
  *v2 = BYTE1(value);
  v2[1] = value;
  *arg += 4;
  return 1;
}
