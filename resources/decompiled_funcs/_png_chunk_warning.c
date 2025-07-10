int __cdecl png_chunk_warning(int a1, _BYTE *a2)
{
  _BYTE v3[92]; // [esp+0h] [ebp-60h] BYREF

  if ( !a1 )
    return png_warning(0, a2);
  sub_355B50(a1, (int)v3, (int)a2);
  return png_warning(a1, v3);
}
