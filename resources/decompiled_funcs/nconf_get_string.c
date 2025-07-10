// attributes: thunk
char *__cdecl nconf_get_string(const conf_st *db, char *section, char *value)
{
  return NCONF_get_string(db, section, value);
}
