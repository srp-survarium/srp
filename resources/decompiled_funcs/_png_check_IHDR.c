int __cdecl png_check_IHDR(_DWORD *a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // eax
  int v9; // [esp+0h] [ebp-4h]

  v9 = 0;
  if ( !a2 )
  {
    png_warning((int)a1, "Image width is zero in IHDR");
    v9 = 1;
  }
  if ( !a3 )
  {
    png_warning((int)a1, "Image height is zero in IHDR");
    v9 = 1;
  }
  if ( a2 > a1[160] )
  {
    png_warning((int)a1, "Image width exceeds user limit in IHDR");
    v9 = 1;
  }
  result = a3;
  if ( a3 > a1[161] )
  {
    result = png_warning((int)a1, "Image height exceeds user limit in IHDR");
    v9 = 1;
  }
  if ( a2 > 0x7FFFFFFF )
  {
    result = png_warning((int)a1, "Invalid image width in IHDR");
    v9 = 1;
  }
  if ( a3 > 0x7FFFFFFF )
  {
    result = png_warning((int)a1, "Invalid image height in IHDR");
    v9 = 1;
  }
  if ( a2 > 0x1FFFFF8E )
    result = png_warning((int)a1, "Width is too large for libpng to process pixels");
  if ( a4 != 1 && a4 != 2 && a4 != 4 && a4 != 8 && a4 != 16 )
  {
    result = png_warning((int)a1, "Invalid bit depth in IHDR");
    v9 = 1;
  }
  if ( a5 < 0 || a5 == 1 || a5 == 5 || a5 > 6 )
  {
    result = png_warning((int)a1, "Invalid color type in IHDR");
    v9 = 1;
  }
  if ( a5 == 3 && a4 > 8 || (a5 == 2 || a5 == 4 || a5 == 6) && a4 < 8 )
  {
    result = png_warning((int)a1, "Invalid color type/bit depth combination in IHDR");
    v9 = 1;
  }
  if ( a6 >= 2 )
  {
    result = png_warning((int)a1, "Unknown interlace method in IHDR");
    v9 = 1;
  }
  if ( a7 )
  {
    result = png_warning((int)a1, "Unknown compression method in IHDR");
    v9 = 1;
  }
  if ( (a1[27] & 0x1000) != 0 )
  {
    result = (int)a1;
    if ( a1[150] )
      result = png_warning((int)a1, "MNG features are not allowed in a PNG datastream");
  }
  if ( a8 )
  {
    result = a1[150] & 4;
    if ( !result || a8 != 64 || (a1[27] & 0x1000) != 0 || a5 != 2 && a5 != 6 )
    {
      result = png_warning((int)a1, "Unknown filter method in IHDR");
      v9 = 1;
    }
    if ( (a1[27] & 0x1000) != 0 )
    {
      result = png_warning((int)a1, "Invalid filter method in IHDR");
      v9 = 1;
    }
  }
  if ( v9 == 1 )
    png_error((int)a1, (int)"Invalid IHDR data");
  return result;
}
