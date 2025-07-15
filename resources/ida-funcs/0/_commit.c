DWORD __usercall _commit@<eax>(stlp_std::ioinfo **a1@<edi>, int a2@<esi>, int filedes)
{
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (a1 = &__pioinfo[filedes >> 5], a2 = (filedes & 0x1F) << 6, (*(&(*a1)->osfile + a2) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter(0, (int)a1, a2);
    return -1;
  }
  __lock_fhandle(filedes);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(0, (int)a1, filedes);
    if ( FlushFileBuffers(osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( !retval )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(filedes);
  return retval;
}
