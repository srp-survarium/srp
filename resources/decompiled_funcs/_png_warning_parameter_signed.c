unsigned int __cdecl png_warning_parameter_signed(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // [esp+0h] [ebp-24h]
  _BYTE v6[24]; // [esp+4h] [ebp-20h] BYREF
  int v7; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int v8; // [esp+20h] [ebp-4h]

  v8 = a4;
  if ( a4 < 0 )
    v8 = -v8;
  v5 = png_format_number((unsigned int)v6, (int)&v7, a3, v8);
  if ( a4 < 0 && v5 > v6 )
    *--v5 = 45;
  return png_warning_parameter(a1, a2, v5);
}
