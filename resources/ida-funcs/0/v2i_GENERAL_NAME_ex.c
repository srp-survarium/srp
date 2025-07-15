GENERAL_NAME_st *__cdecl v2i_GENERAL_NAME_ex(
        GENERAL_NAME_st *out,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        CONF_VALUE *cnf,
        int is_nc)
{
  char *name; // esi
  char *value; // edi
  int v8; // eax

  name = cnf->name;
  value = cnf->value;
  if ( !value )
  {
    ERR_put_error(0x22u, 117, 124, ".\\crypto\\x509v3\\v3_alt.c", 537);
    return 0;
  }
  if ( !name_cmp(name, "email") )
  {
    v8 = 1;
    return a2i_GENERAL_NAME(out, method, ctx, v8, value, is_nc);
  }
  if ( !name_cmp(name, "URI") )
  {
    v8 = 6;
    return a2i_GENERAL_NAME(out, method, ctx, v8, value, is_nc);
  }
  if ( !name_cmp(name, "DNS") )
  {
    v8 = 2;
    return a2i_GENERAL_NAME(out, method, ctx, v8, value, is_nc);
  }
  if ( !name_cmp(name, "RID") )
  {
    v8 = 8;
    return a2i_GENERAL_NAME(out, method, ctx, v8, value, is_nc);
  }
  if ( !name_cmp(name, "IP") )
  {
    v8 = 7;
    return a2i_GENERAL_NAME(out, method, ctx, v8, value, is_nc);
  }
  if ( !name_cmp(name, "dirName") )
  {
    v8 = 4;
    return a2i_GENERAL_NAME(out, method, ctx, v8, value, is_nc);
  }
  v8 = name_cmp(name, "otherName");
  if ( !v8 )
    return a2i_GENERAL_NAME(out, method, ctx, v8, value, is_nc);
  ERR_put_error(0x22u, 117, 117, ".\\crypto\\x509v3\\v3_alt.c", 557);
  ERR_add_error_data(2, "name=", name);
  return 0;
}
