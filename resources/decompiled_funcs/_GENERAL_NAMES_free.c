void __cdecl GENERAL_NAMES_free(stack_st_GENERAL_NAME *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_4);
}
