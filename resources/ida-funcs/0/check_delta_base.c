BOOL __usercall check_delta_base@<eax>(stack_st_X509_ATTRIBUTE *delta@<ebx>, stack_st_X509_ATTRIBUTE *base@<esi>)
{
  if ( !delta[2].stack.num
    || !base[1].stack.comp
    || X509_NAME_cmp(*(X509_name_st **)(base->stack.num + 8), *(X509_name_st **)(delta->stack.num + 8)) )
  {
    return 0;
  }
  if ( crl_extension_match(delta, 90, base)
    && crl_extension_match(delta, 770, base)
    && ASN1_INTEGER_cmp((const asn1_string_st *)delta[2].stack.num, (const asn1_string_st *)base[1].stack.comp) <= 0 )
  {
    return ASN1_INTEGER_cmp((const asn1_string_st *)delta[1].stack.comp, (const asn1_string_st *)base[1].stack.comp) > 0;
  }
  return 0;
}
