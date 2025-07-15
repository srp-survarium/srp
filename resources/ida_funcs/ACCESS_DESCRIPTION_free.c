void __cdecl ACCESS_DESCRIPTION_free(ACCESS_DESCRIPTION_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_70);
}
