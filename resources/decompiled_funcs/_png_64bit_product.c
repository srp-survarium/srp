int __cdecl png_64bit_product(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int result; // eax

  *a3 = (((unsigned __int16)a1 * HIWORD(a2)
        + (unsigned __int16)a2 * HIWORD(a1)
        + (((unsigned __int16)a2 * (unsigned int)(unsigned __int16)a1) >> 16)) >> 16)
      + HIWORD(a2) * HIWORD(a1);
  result = a1 * a2;
  *a4 = a1 * a2;
  return result;
}
