stack_st_CONF_VALUE *__cdecl i2v_BASIC_CONSTRAINTS(
        v3_ext_method *method,
        BASIC_CONSTRAINTS_st *bcons,
        stack_st_CONF_VALUE *extlist)
{
  X509V3_add_value_bool("CA", bcons->ca, &extlist);
  X509V3_add_value_int("pathlen", bcons->pathlen, &extlist);
  return extlist;
}
