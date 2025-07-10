const ssl_method_st *__cdecl ssl3_get_client_method(int ver)
{
  return ver != 768 ? 0 : &SSLv3_client_method_data;
}
