struct ASN1_VALUE_st *__cdecl ASN1_item_d2i(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **in,
        const unsigned __int8 **len,
        const ASN1_ITEM_st *it)
{
  struct ASN1_VALUE_st **v4; // esi
  int v6; // [esp+4h] [ebp-1Ch] BYREF
  ASN1_TLC_st v7; // [esp+8h] [ebp-18h] BYREF

  v4 = pval;
  v6 = 0;
  if ( !pval )
    v4 = (struct ASN1_VALUE_st **)&v6;
  v7.valid = 0;
  if ( ASN1_item_ex_d2i(v4, in, len, it, -1, 0, 0, &v7) <= 0 )
    return 0;
  else
    return *v4;
}
