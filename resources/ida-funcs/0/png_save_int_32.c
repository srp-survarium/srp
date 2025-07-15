int __cdecl png_save_int_32(_BYTE *a1, int a2)
{
  int result; // eax

  *a1 = HIBYTE(a2);
  a1[1] = BYTE2(a2);
  a1[2] = BYTE1(a2);
  result = (unsigned __int8)a2;
  a1[3] = a2;
  return result;
}
