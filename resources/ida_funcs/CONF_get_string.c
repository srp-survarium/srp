char *__cdecl CONF_get_string(conf_st *conf, char *group, char *name)
{
  char *result; // eax
  conf_method_st *v4; // eax
  conf_st v5; // [esp+4h] [ebp-Ch] BYREF

  if ( conf )
  {
    v4 = default_CONF_method;
    if ( !default_CONF_method )
    {
      v4 = (conf_method_st *)NCONF_default();
      default_CONF_method = v4;
    }
    v4->init(&v5);
    v5.data = (lhash_st_CONF_VALUE *)conf;
    return NCONF_get_string(&v5, group, name);
  }
  else
  {
    result = _CONF_get_string(0, group, name);
    if ( !result )
    {
      ERR_put_error(0xEu, 109, 106, ".\\crypto\\conf\\conf_lib.c", 331);
      return 0;
    }
  }
  return result;
}
