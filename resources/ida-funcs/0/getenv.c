char *__usercall getenv@<eax>(int a1@<ebx>, int a2@<edi>, char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option && (a2 = 0x7FFF, strnlen(option, 0x7FFFu) < 0x7FFF) )
  {
    _lock(7);
    retval = (char *)_getenv_helper_nolock(option);
    _unlock(7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return 0;
  }
}
