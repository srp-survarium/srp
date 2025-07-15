int __cdecl X509V3_get_value_bool(CONF_VALUE *value, int *asn1_bool)
{
  if ( !value->value )
    goto err_82;
  if ( !strcmp(value->value, "TRUE")
    || !strcmp(value->value, (const char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1])
    || !strcmp(value->value, "Y")
    || !strcmp(value->value, "y")
    || !strcmp(value->value, "YES")
    || !strcmp(value->value, "yes") )
  {
    *asn1_bool = 255;
    return 1;
  }
  else
  {
    if ( strcmp(value->value, "FALSE")
      && strcmp(value->value, (const char *)&stru_95AF78.m_key_bindings[6])
      && strcmp(value->value, "N")
      && strcmp(value->value, "n")
      && strcmp(value->value, "NO")
      && strcmp(value->value, "no") )
    {
err_82:
      ERR_put_error(0x22u, 110, 104, ".\\crypto\\x509v3\\v3_utl.c", 229);
      ERR_add_error_data(6, "section:", value->section, ",name:", value->name, ",value:", value->value);
      return 0;
    }
    *asn1_bool = 0;
    return 1;
  }
}
