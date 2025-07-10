BOOL __usercall check_delta_base@<eax>(X509_crl_st *delta@<ebx>, X509_crl_st *base@<esi>)
{
  if ( !delta->base_crl_number || !base->crl_number || X509_NAME_cmp(base->crl->issuer, delta->crl->issuer) )
    return 0;
  if ( crl_extension_match(delta, 90, base)
    && crl_extension_match(delta, 770, base)
    && ASN1_INTEGER_cmp(delta->base_crl_number, base->crl_number) <= 0 )
  {
    return ASN1_INTEGER_cmp(delta->crl_number, base->crl_number) > 0;
  }
  return 0;
}
