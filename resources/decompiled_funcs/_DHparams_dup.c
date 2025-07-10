dh_st *__cdecl DHparams_dup(dh_st *dh)
{
  return (dh_st *)ASN1_item_dup(&stru_84A0BC, (unsigned __int8 *)dh);
}
