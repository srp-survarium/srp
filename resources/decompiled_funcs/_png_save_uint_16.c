_BYTE *__cdecl png_save_uint_16(_BYTE *a1, __int16 a2)
{
  _BYTE *result; // eax

  *a1 = HIBYTE(a2);
  result = a1;
  a1[1] = a2;
  return result;
}
