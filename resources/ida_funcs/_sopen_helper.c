int __usercall _sopen_helper@<eax>(
        unsigned int a1@<ebx>,
        const char *path,
        int oflag,
        int shflag,
        int pmode,
        int *pfh,
        int bSecure)
{
  int result; // eax
  char *v8; // eax
  int retval; // [esp+14h] [ebp-20h]
  int unlock_flag; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  unlock_flag = 0;
  if ( !pfh || (*pfh = -1, !path) || bSecure && (pmode & 0xFFFFFE7F) != 0 )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0x16u, 0);
    return 22;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    retval = tsopen_nolock(pfh, (unsigned int)pfh, &unlock_flag, path, oflag, shflag, pmode);
    ms_exc.registration.TryLevel = -2;
    if ( unlock_flag )
    {
      if ( retval )
      {
        v8 = &__pioinfo[*pfh >> 5]->osfile + 64 * (*pfh & 0x1F);
        *v8 &= ~1u;
      }
      _unlock_fhandle(*pfh);
    }
    result = retval;
    if ( retval )
      *pfh = -1;
  }
  return result;
}
