dh_st *__usercall DHparams_dup@<eax>(int a1@<ebx>, dh_st *dh)
{
  return (dh_st *)ASN1_item_dup(a1, &stru_6DBD74, (struct ASN1_VALUE_st *)dh);
}
