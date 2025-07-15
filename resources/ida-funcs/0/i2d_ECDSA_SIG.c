int __cdecl i2d_ECDSA_SIG(ECDSA_SIG_st *a, unsigned __int8 **out)
{
  return ASN1_item_i2d((struct ASN1_VALUE_st *)a, out, &stru_6DBB74);
}
