int __cdecl def_destroy_data(conf_st *conf)
{
  int result; // eax

  result = (int)conf;
  if ( conf )
  {
    _CONF_free_data(conf);
    return 1;
  }
  return result;
}
