unsigned __int8 *__usercall i2d_name_canon@<eax>(
        stack_st_STACK_OF_X509_NAME_ENTRY *_intname@<edi>,
        unsigned __int8 **in)
{
  int v2; // ebx
  int v3; // esi
  unsigned __int8 *result; // eax
  const stack_st *v5; // [esp+0h] [ebp-14h]
  struct ASN1_VALUE_st *pval; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  v3 = 0;
  if ( sk_num(v5) <= 0 )
    return (unsigned __int8 *)v2;
  while ( 1 )
  {
    pval = (struct ASN1_VALUE_st *)sk_value(&_intname->stack, v3);
    result = ASN1_item_ex_i2d(&pval, in, &local_it_36, -1, -1);
    if ( (int)result < 0 )
      break;
    v2 += (int)result;
    if ( ++v3 >= sk_num(&_intname->stack) )
      return (unsigned __int8 *)v2;
  }
  return result;
}
