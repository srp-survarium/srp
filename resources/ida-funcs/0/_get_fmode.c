int __usercall _get_fmode@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int *pMode)
{
  if ( pMode )
  {
    *pMode = _fmode;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return 22;
  }
}
