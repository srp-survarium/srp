void __usercall setup_idp(ISSUING_DIST_POINT_st *idp@<esi>, X509_crl_st *crl)
{
  int v2; // edx
  asn1_string_st *onlysomereasons; // ecx
  asn1_string_st *v4; // ecx

  crl->idp_flags |= 1u;
  v2 = 0;
  if ( idp->onlyuser > 0 )
  {
    v2 = 1;
    crl->idp_flags |= 4u;
  }
  if ( idp->onlyCA > 0 )
  {
    ++v2;
    crl->idp_flags |= 8u;
  }
  if ( idp->onlyattr > 0 )
  {
    ++v2;
    crl->idp_flags |= 0x10u;
  }
  if ( v2 > 1 )
    crl->idp_flags |= 2u;
  if ( idp->indirectCRL > 0 )
    crl->idp_flags |= 0x20u;
  if ( idp->onlysomereasons )
  {
    crl->idp_flags |= 0x40u;
    onlysomereasons = idp->onlysomereasons;
    if ( onlysomereasons->length > 0 )
      crl->idp_reasons = *onlysomereasons->data;
    v4 = idp->onlysomereasons;
    if ( v4->length > 1 )
      crl->idp_reasons |= v4->data[1] << 8;
    crl->idp_reasons &= 0x807Fu;
  }
  DIST_POINT_set_dpname(idp->distpoint, crl->crl->issuer);
}
