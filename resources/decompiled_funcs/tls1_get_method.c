const ssl_method_st *__cdecl tls1_get_method(int ver)
{
  return ver != 769 ? 0 : &TLSv1_method_data;
}
