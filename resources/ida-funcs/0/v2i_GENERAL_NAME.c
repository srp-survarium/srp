GENERAL_NAME_st *__usercall v2i_GENERAL_NAME@<eax>(
        int a1@<ebx>,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        CONF_VALUE *cnf)
{
  return v2i_GENERAL_NAME_ex(a1, 0, method, ctx, cnf, 0);
}
