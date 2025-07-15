// attributes: thunk
int __cdecl X509V3_add_value_uchar(char *name, char *value, stack_st_CONF_VALUE **extlist)
{
  return X509V3_add_value(name, value, extlist);
}
