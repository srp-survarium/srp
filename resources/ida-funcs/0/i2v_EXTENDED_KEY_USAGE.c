stack_st_CONF_VALUE *__usercall i2v_EXTENDED_KEY_USAGE@<eax>(
        stack_st_CONF_VALUE **a1@<ebx>,
        const v3_ext_method *method,
        stack_st *a,
        stack_st_CONF_VALUE *ext_list)
{
  int i; // esi
  char *v5; // eax
  stack_st_CONF_VALUE *v7; // [esp+8h] [ebp-58h] BYREF
  char v8[80]; // [esp+Ch] [ebp-54h] BYREF

  v7 = ext_list;
  for ( i = 0; i < sk_num(a); ++i )
  {
    v5 = sk_value(a, i);
    i2t_ASN1_OBJECT(v8, 0x50u, (asn1_object_st *)v5);
    X509V3_add_value(a1, 0, v8, &v7);
  }
  return v7;
}
