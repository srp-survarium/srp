int __cdecl def_init_default(conf_st *conf)
{
  int result; // eax

  result = (int)conf;
  if ( conf )
  {
    conf->meth = &default_method;
    conf->meth_data = CONF_type_default;
    conf->data = 0;
    return 1;
  }
  return result;
}
