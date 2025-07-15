int __cdecl def_init_WIN32(conf_st *conf)
{
  int result; // eax

  result = (int)conf;
  if ( conf )
  {
    conf->meth = &WIN32_method;
    conf->meth_data = CONF_type_win32;
    conf->data = 0;
    return 1;
  }
  return result;
}
