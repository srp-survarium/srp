char *__usercall _getcwd@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(7);
  retval = _getdcwd_nolock(a1, a2, 0, pnbuf, maxlen);
  _unlock(7);
  return retval;
}
