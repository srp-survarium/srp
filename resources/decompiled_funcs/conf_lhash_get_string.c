// attributes: thunk
char *__cdecl conf_lhash_get_string(conf_st *db, char *section, char *value)
{
  return CONF_get_string(db, section, value);
}
