stack_st_CONF_VALUE *__usercall i2v_POLICY_CONSTRAINTS@<eax>(
        stack_st_CONF_VALUE **a1@<ebx>,
        const v3_ext_method *method,
        asn1_string_st **a,
        stack_st_CONF_VALUE *extlist)
{
  X509V3_add_value_int(a1, "Require Explicit Policy", *a, &extlist);
  X509V3_add_value_int(a1, "Inhibit Policy Mapping", a[1], &extlist);
  return extlist;
}
