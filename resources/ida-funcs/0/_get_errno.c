int __usercall _get_errno@<eax>(int a1@<ebx>, int a2@<edi>, int *pValue)
{
  if ( pValue )
  {
    *pValue = *_errno();
    return 0;
  }
  else
  {
    _invalid_parameter(a1, a2, 0);
    return 22;
  }
}
