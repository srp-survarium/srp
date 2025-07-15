char *__cdecl NCONF_get_string(const conf_st *conf, const char *group, const char *name)
{
  char *result; // eax

  result = _CONF_get_string(conf, group, name);
  if ( !result )
  {
    if ( conf )
    {
      ERR_put_error(0xEu, 109, 108, ".\\crypto\\conf\\conf_lib.c", 335);
      ERR_add_error_data(4, "group=", group, " name=", name);
    }
    else
    {
      ERR_put_error(0xEu, 109, 106, ".\\crypto\\conf\\conf_lib.c", 331);
    }
    return 0;
  }
  return result;
}
