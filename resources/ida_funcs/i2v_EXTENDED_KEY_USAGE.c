stack_st_CONF_VALUE *__cdecl i2v_EXTENDED_KEY_USAGE(
        const v3_ext_method *method,
        stack_st *a,
        stack_st_CONF_VALUE *ext_list)
{
  int i; // esi
  char *v4; // eax
  stack_st_CONF_VALUE *extlist; // [esp+8h] [ebp-58h] BYREF
  char buf[80]; // [esp+Ch] [ebp-54h] BYREF

  extlist = ext_list;
  for ( i = 0; i < sk_num(a); ++i )
  {
    v4 = sk_value(a, i);
    i2t_ASN1_OBJECT(buf, 0x50u, (asn1_object_st *)v4);
    X509V3_add_value(0, buf, &extlist);
  }
  return extlist;
}
