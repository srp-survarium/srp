struct ASN1_VALUE_st *__cdecl ASN1_item_d2i(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **in,
        unsigned __int8 *len,
        const ASN1_ITEM_st *it)
{
  struct ASN1_VALUE_st **v4; // esi
  int v6; // [esp+4h] [ebp-1Ch] BYREF
  ASN1_TLC_st ctx; // [esp+8h] [ebp-18h] BYREF

  v4 = pval;
  v6 = 0;
  if ( !pval )
    v4 = (struct ASN1_VALUE_st **)&v6;
  ctx.valid = 0;
  if ( ASN1_item_ex_d2i(v4, in, len, it, -1, 0, 0, &ctx) <= 0 )
    return 0;
  else
    return *v4;
}
