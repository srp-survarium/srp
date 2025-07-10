const ssl_method_st *__cdecl ssl2_get_method(int ver)
{
  return ver != 2 ? 0 : &SSLv2_method_data;
}
