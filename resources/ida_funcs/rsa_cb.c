int __usercall rsa_cb@<eax>(unsigned int a1@<edi>, int operation, struct ASN1_VALUE_st **pval)
{
  struct ASN1_VALUE_st *v3; // eax

  if ( operation )
  {
    if ( operation == 2 )
    {
      RSA_free(a1, (rsa_st *)*pval);
      *pval = 0;
      return 2;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    v3 = (struct ASN1_VALUE_st *)RSA_new();
    *pval = v3;
    return v3 != 0 ? 2 : 0;
  }
}
