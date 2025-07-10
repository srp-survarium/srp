// attributes: thunk
int __cdecl X509V3_add_value_uchar(const char *name, const unsigned __int8 *value, stack_st_CONF_VALUE **extlist)
{
  return X509V3_add_value(name, (const char *)value, extlist);
}
