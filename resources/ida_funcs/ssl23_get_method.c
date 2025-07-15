const ssl_method_st *__cdecl ssl23_get_method(int ver)
{
  switch ( ver )
  {
    case 2:
      return SSLv2_method();
    case 768:
      return SSLv3_method();
    case 769:
      return TLSv1_method();
  }
  return 0;
}
