PBE2PARAM_st *__cdecl d2i_PBE2PARAM(PBE2PARAM_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  return (PBE2PARAM_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_843060);
}
