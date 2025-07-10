const ssl_method_st *__cdecl ssl2_get_server_method(int ver)
{
  return ver != 2 ? 0 : &SSLv2_server_method_data;
}
