stack_st_CONF_VALUE *__cdecl NCONF_get_section(const conf_st *conf, const char *section)
{
  if ( conf )
  {
    if ( section )
    {
      return _CONF_get_section_values(conf, section);
    }
    else
    {
      ERR_put_error(0xEu, 108, 107, ".\\crypto\\conf\\conf_lib.c", 313);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0xEu, 108, 105, ".\\crypto\\conf\\conf_lib.c", 307);
    return 0;
  }
}
