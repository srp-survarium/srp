int __cdecl png_check_fp_string(int a1, unsigned int a2)
{
  int v3; // [esp+0h] [ebp-8h] BYREF
  unsigned int v4; // [esp+4h] [ebp-4h] BYREF

  v3 = 0;
  v4 = 0;
  if ( png_check_fp_number(a1, a2, &v3, &v4) && (v4 == a2 || !*(_BYTE *)(v4 + a1)) )
    return v3;
  else
    return 0;
}
