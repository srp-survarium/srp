int __cdecl png_set_error_fn(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // eax

  if ( a1 )
  {
    a1[19] = a2;
    result = a3;
    a1[17] = a3;
    a1[18] = a4;
  }
  return result;
}
