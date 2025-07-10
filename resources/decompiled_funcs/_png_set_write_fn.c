int __cdecl png_set_write_fn(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // eax

  if ( a1 )
  {
    result = (int)a1;
    a1[22] = a2;
    if ( a3 )
    {
      result = a3;
      a1[20] = a3;
    }
    else
    {
      a1[20] = png_default_write_data;
    }
    if ( a4 )
    {
      result = a4;
      a1[90] = a4;
    }
    else
    {
      a1[90] = png_default_flush;
    }
    if ( a1[21] )
    {
      a1[21] = 0;
      return png_warning((int)a1, "Can't set both read_data_fn and write_data_fn in the same structure");
    }
  }
  return result;
}
