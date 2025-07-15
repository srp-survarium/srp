void __cdecl __noreturn png_chunk_error(int a1, int a2)
{
  _BYTE v2[88]; // [esp+0h] [ebp-58h] BYREF

  if ( !a1 )
    png_error(0, a2);
  sub_355B50(a1, v2, a2);
  png_error(a1, (int)v2);
}
