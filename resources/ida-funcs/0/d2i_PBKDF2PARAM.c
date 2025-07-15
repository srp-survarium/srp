PBKDF2PARAM_st *__cdecl d2i_PBKDF2PARAM(PBKDF2PARAM_st **a, unsigned __int8 **in, const unsigned __int8 **len)
{
  return (PBKDF2PARAM_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_6D4D24);
}
