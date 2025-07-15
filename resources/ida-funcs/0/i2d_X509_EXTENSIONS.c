int __cdecl i2d_X509_EXTENSIONS(stack_st_X509_EXTENSION *a, unsigned __int8 **out)
{
  return ASN1_item_i2d((struct ASN1_VALUE_st *)a, out, &stru_6CE2DC);
}
