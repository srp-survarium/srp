int __cdecl X509_ALGOR_set0(X509_algor_st *alg, asn1_object_st *aobj, int ptype, int pval)
{
  int result; // eax

  if ( !alg )
    return 0;
  if ( ptype == -1 || alg->parameter || (result = (int)ASN1_TYPE_new(), (alg->parameter = (asn1_type_st *)result) != 0) )
  {
    if ( alg->algorithm )
      ASN1_OBJECT_free(alg->algorithm);
    alg->algorithm = aobj;
    if ( ptype )
    {
      if ( ptype == -1 )
      {
        if ( alg->parameter )
        {
          ASN1_TYPE_free(alg->parameter);
          result = 1;
          alg->parameter = 0;
          return result;
        }
      }
      else
      {
        ASN1_TYPE_set(alg->parameter, ptype, pval);
      }
    }
    return 1;
  }
  return result;
}
