stack_st_CONF_VALUE *__cdecl i2v_GENERAL_NAMES(
        v3_ext_method *method,
        stack_st_GENERAL_NAME *gens,
        stack_st_CONF_VALUE *ret)
{
  int i; // esi
  char *v5; // eax

  for ( i = 0; i < sk_num(&gens->stack); ++i )
  {
    v5 = sk_value(&gens->stack, i);
    ret = i2v_GENERAL_NAME(method, (GENERAL_NAME_st *)v5, ret);
  }
  if ( ret )
    return ret;
  else
    return (stack_st_CONF_VALUE *)sk_new_null();
}
