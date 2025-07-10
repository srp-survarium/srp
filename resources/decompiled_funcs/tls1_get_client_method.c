const ssl_method_st *__cdecl tls1_get_client_method(int ver)
{
  return ver != 769 ? 0 : &TLSv1_client_method_data;
}
