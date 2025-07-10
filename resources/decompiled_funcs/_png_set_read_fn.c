int __cdecl png_set_read_fn(_DWORD *a1, int a2, int a3)
{
  int result; // eax

  if ( a1 )
  {
    result = (int)a1;
    a1[22] = a2;
    if ( a3 )
    {
      result = a3;
      a1[21] = a3;
    }
    else
    {
      a1[21] = png_default_read_data;
    }
    if ( a1[20] )
    {
      a1[20] = 0;
      result = png_warning((int)a1, "Can't set both read_data_fn and write_data_fn in the same structure");
    }
    a1[90] = 0;
  }
  return result;
}
