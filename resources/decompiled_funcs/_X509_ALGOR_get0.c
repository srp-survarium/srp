void __cdecl X509_ALGOR_get0(asn1_object_st **paobj, int *pptype, void **ppval, X509_algor_st *algor)
{
  asn1_type_st *parameter; // eax

  if ( paobj )
    *paobj = algor->algorithm;
  if ( pptype )
  {
    parameter = algor->parameter;
    if ( parameter )
    {
      *pptype = parameter->type;
      if ( ppval )
        *ppval = algor->parameter->value.ptr;
    }
    else
    {
      *pptype = -1;
    }
  }
}
