void __cdecl ECDSA_SIG_free(ECDSA_SIG_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &stru_6DBB74);
}
