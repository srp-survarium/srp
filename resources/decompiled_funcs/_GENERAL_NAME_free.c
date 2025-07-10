void __cdecl GENERAL_NAME_free(GENERAL_NAME_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_3);
}
