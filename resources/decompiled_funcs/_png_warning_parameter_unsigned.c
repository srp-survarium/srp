unsigned int __cdecl png_warning_parameter_unsigned(int a1, int a2, int a3, unsigned int a4)
{
  _BYTE *v4; // eax
  _BYTE v6[24]; // [esp+0h] [ebp-1Ch] BYREF
  int v7; // [esp+18h] [ebp-4h] BYREF

  v4 = png_format_number((unsigned int)v6, (int)&v7, a3, a4);
  return png_warning_parameter(a1, a2, v4);
}
