stack_st_CONF_VALUE *__cdecl i2v_POLICY_CONSTRAINTS(
        const v3_ext_method *method,
        asn1_string_st **a,
        stack_st_CONF_VALUE *extlist)
{
  X509V3_add_value_int("Require Explicit Policy", *a, &extlist);
  X509V3_add_value_int("Inhibit Policy Mapping", a[1], &extlist);
  return extlist;
}
