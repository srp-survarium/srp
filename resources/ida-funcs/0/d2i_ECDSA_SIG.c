ECDSA_SIG_st *__cdecl d2i_ECDSA_SIG(ECDSA_SIG_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  return (ECDSA_SIG_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_849EC4);
}
