X509_name_st *__cdecl do_dirname(GENERAL_NAME_st *gen, v3_ext_ctx *ctx)
{
  int v2; // ecx
  int v3; // ebx
  X509_name_st *result; // eax
  X509_name_st *v5; // esi
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v7; // edi
  int v8; // ebx

  v3 = v2;
  result = X509_NAME_new();
  v5 = result;
  if ( result )
  {
    section = X509V3_get_section(ctx);
    v7 = section;
    if ( section )
    {
      v8 = X509V3_NAME_from_section(v5, section, 4097);
      if ( !v8 )
        X509_NAME_free(v5);
      gen->d.ptr = (char *)v5;
      X509V3_section_free(ctx, v7);
      return (X509_name_st *)v8;
    }
    else
    {
      ERR_put_error(v3, 0x22u, 144, 150, ".\\crypto\\x509v3\\v3_alt.c", 601);
      ERR_add_error_data(2, "section=", v3);
      X509_NAME_free(v5);
      return 0;
    }
  }
  return result;
}
