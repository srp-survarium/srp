int __usercall dsa_cb@<eax>(int a1@<edi>, int a2@<ebx>, int operation, dsa_st **pval)
{
  dsa_st *v4; // eax

  if ( operation )
  {
    if ( operation == 2 )
    {
      DSA_free(a1, a2, *pval);
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
    v4 = DSA_new(a2);
    *pval = v4;
    return v4 != 0 ? 2 : 0;
  }
}
