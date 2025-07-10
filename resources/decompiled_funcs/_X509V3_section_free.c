void __cdecl X509V3_section_free(v3_ext_ctx *ctx, stack_st_CONF_VALUE *section)
{
  void (__cdecl *free_section)(void *, stack_st_CONF_VALUE *); // eax

  if ( section )
  {
    free_section = ctx->db_meth->free_section;
    if ( free_section )
      ((void (__cdecl *)(void *))free_section)(ctx->db);
  }
}
