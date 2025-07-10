BOOL __usercall _isindst@<eax>(unsigned int a1@<ebx>, tm *tb)
{
  BOOL retval; // [esp+10h] [ebp-1Ch]

  _lock(6);
  retval = isindst_nolock(tb, a1);
  _unlock(6);
  return retval;
}
