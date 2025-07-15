int __usercall dh_cb@<eax>(int a1@<edi>, int a2@<ebx>, int operation, dh_st **pval)
{
  dh_st *v4; // eax

  if ( operation )
  {
    if ( operation == 2 )
    {
      DH_free(a1, a2, *pval);
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
    v4 = DH_new(a2);
    *pval = v4;
    return v4 != 0 ? 2 : 0;
  }
}
