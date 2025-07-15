char *__usercall CONF_get_string@<eax>(int a1@<ebx>, conf_st *conf, char *group, char *name)
{
  char *result; // eax
  conf_method_st *v5; // eax
  conf_st v6; // [esp+4h] [ebp-Ch] BYREF

  if ( conf )
  {
    v5 = default_CONF_method;
    if ( !default_CONF_method )
    {
      v5 = NCONF_default();
      default_CONF_method = v5;
    }
    v5->init(&v6);
    v6.data = (lhash_st_CONF_VALUE *)conf;
    return NCONF_get_string(&v6, group, name);
  }
  else
  {
    result = _CONF_get_string(0, group, name);
    if ( !result )
    {
      ERR_put_error(a1, 0xEu, 109, 106, ".\\crypto\\conf\\conf_lib.c", 331);
      return 0;
    }
  }
  return result;
}
