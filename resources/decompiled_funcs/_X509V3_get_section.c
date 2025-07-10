stack_st_CONF_VALUE *__cdecl X509V3_get_section(v3_ext_ctx *ctx)
{
  X509V3_CONF_METHOD_st *db_meth; // eax
  stack_st_CONF_VALUE *(__cdecl *get_section)(void *, char *); // eax

  if ( ctx->db )
  {
    db_meth = ctx->db_meth;
    if ( db_meth )
    {
      get_section = db_meth->get_section;
      if ( get_section )
        return (stack_st_CONF_VALUE *)((int (__cdecl *)(void *))get_section)(ctx->db);
    }
  }
  ERR_put_error(0x22u, 142, 148, ".\\crypto\\x509v3\\v3_conf.c", 401);
  return 0;
}
