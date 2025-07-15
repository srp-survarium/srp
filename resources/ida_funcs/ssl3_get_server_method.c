const ssl_method_st *__cdecl ssl3_get_server_method(int ver)
{
  return ver != 768 ? 0 : &SSLv3_server_method_data;
}
