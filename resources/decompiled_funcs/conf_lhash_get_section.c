// attributes: thunk
stack_st_CONF_VALUE *__cdecl conf_lhash_get_section(lhash_st_CONF_VALUE *db, char *section)
{
  return CONF_get_section(db, section);
}
