stack_st_GENERAL_NAME *__usercall gnames_from_sectname@<eax>(v3_ext_ctx *ctx@<ebx>, char *sect@<edi>)
{
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v3; // esi
  stack_st_GENERAL_NAME *v5; // ebp

  if ( *sect == 64 )
    section = X509V3_get_section(ctx);
  else
    section = X509V3_parse_list(sect);
  v3 = section;
  if ( section )
  {
    v5 = v2i_GENERAL_NAMES(0, ctx, section);
    if ( *sect == 64 )
      X509V3_section_free(ctx, v3);
    else
      sk_pop_free(&v3->stack, (void (__cdecl *)(void *))X509V3_conf_free);
    return v5;
  }
  else
  {
    ERR_put_error((int)ctx, 0x22u, 156, 150, ".\\crypto\\x509v3\\v3_crld.c", 104);
    return 0;
  }
}
