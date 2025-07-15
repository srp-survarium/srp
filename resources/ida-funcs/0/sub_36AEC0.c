int __cdecl sub_36AEC0(_DWORD *a1, int a2, unsigned __int8 *buf, int a4)
{
  int result; // eax

  if ( a1 )
  {
    sub_36AD20(a1, a2, a4);
    png_write_chunk_data(a1, buf, a4);
    return png_write_chunk_end((int)a1);
  }
  return result;
}
