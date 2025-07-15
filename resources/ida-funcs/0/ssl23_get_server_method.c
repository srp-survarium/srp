const ssl_method_st *__cdecl ssl23_get_server_method(int ver)
{
  switch ( ver )
  {
    case 2:
      return SSLv2_server_method();
    case 768:
      return SSLv3_server_method();
    case 769:
      return TLSv1_server_method();
  }
  return 0;
}
