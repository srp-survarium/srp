int __cdecl X509V3_add_value_bool(char *name, int asn1_bool, stack_st_CONF_VALUE **extlist)
{
  if ( asn1_bool )
    return X509V3_add_value(name, "TRUE", extlist);
  else
    return X509V3_add_value(name, "FALSE", extlist);
}
