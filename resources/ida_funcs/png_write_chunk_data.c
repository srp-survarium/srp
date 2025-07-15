_DWORD *__cdecl png_write_chunk_data(_DWORD *a1, unsigned __int8 *buf, int a3)
{
  _DWORD *result; // eax

  if ( a1 && buf )
  {
    if ( a3 )
    {
      png_write_data((int)a1, (int)buf, a3);
      return png_calculate_crc(a1, buf, a3);
    }
  }
  return result;
}
