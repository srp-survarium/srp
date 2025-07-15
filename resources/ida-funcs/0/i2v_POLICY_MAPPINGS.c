stack_st_CONF_VALUE *__cdecl i2v_POLICY_MAPPINGS(
        const v3_ext_method *method,
        stack_st *a,
        stack_st_CONF_VALUE *ext_list)
{
  int i; // esi
  asn1_object_st **v4; // edi
  stack_st_CONF_VALUE *v6; // [esp+8h] [ebp-A8h] BYREF
  char v7[80]; // [esp+Ch] [ebp-A4h] BYREF
  char v8[80]; // [esp+5Ch] [ebp-54h] BYREF

  v6 = ext_list;
  for ( i = 0; i < sk_num(a); ++i )
  {
    v4 = (asn1_object_st **)sk_value(a, i);
    i2t_ASN1_OBJECT(v8, 0x50u, *v4);
    i2t_ASN1_OBJECT(v7, 0x50u, v4[1]);
    X509V3_add_value((stack_st_CONF_VALUE **)a, v8, v7, &v6);
  }
  return v6;
}
