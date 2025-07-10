dh_st *__cdecl d2i_DHparams(dh_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  return (dh_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_84A0BC);
}
