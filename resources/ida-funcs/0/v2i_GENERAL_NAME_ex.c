GENERAL_NAME_st *__usercall v2i_GENERAL_NAME_ex@<eax>(
        int a1@<ebx>,
        GENERAL_NAME_st *out,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        CONF_VALUE *cnf,
        int is_nc)
{
  char *name; // esi
  __m128i *value; // edi
  int v9; // eax

  name = cnf->name;
  value = (__m128i *)cnf->value;
  if ( !value )
  {
    ERR_put_error(a1, 0x22u, 117, 124, ".\\crypto\\x509v3\\v3_alt.c", 537);
    return 0;
  }
  if ( !name_cmp(name, "email") )
  {
    v9 = 1;
    return a2i_GENERAL_NAME(a1, out, method, ctx, v9, value, is_nc);
  }
  if ( !name_cmp(name, "URI") )
  {
    v9 = 6;
    return a2i_GENERAL_NAME(a1, out, method, ctx, v9, value, is_nc);
  }
  if ( !name_cmp(name, "DNS") )
  {
    v9 = 2;
    return a2i_GENERAL_NAME(a1, out, method, ctx, v9, value, is_nc);
  }
  if ( !name_cmp(name, "RID") )
  {
    v9 = 8;
    return a2i_GENERAL_NAME(a1, out, method, ctx, v9, value, is_nc);
  }
  if ( !name_cmp(name, "IP") )
  {
    v9 = 7;
    return a2i_GENERAL_NAME(a1, out, method, ctx, v9, value, is_nc);
  }
  if ( !name_cmp(name, "dirName") )
  {
    v9 = 4;
    return a2i_GENERAL_NAME(a1, out, method, ctx, v9, value, is_nc);
  }
  v9 = name_cmp(name, "otherName");
  if ( !v9 )
    return a2i_GENERAL_NAME(a1, out, method, ctx, v9, value, is_nc);
  ERR_put_error(a1, 0x22u, 117, 117, ".\\crypto\\x509v3\\v3_alt.c", 557);
  ERR_add_error_data(2, "name=", name);
  return 0;
}
