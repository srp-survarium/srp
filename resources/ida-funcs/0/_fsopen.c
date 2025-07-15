_iobuf *__usercall _fsopen@<eax>(const char *a1@<esi>, char *file, const char *mode, int shflag)
{
  _iobuf *v6; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( !file || (a1 = mode) == 0 || !*mode )
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)file, (int)a1);
    return 0;
  }
  v6 = _getstream();
  stream = v6;
  if ( !v6 )
  {
    *_errno() = 24;
    return 0;
  }
  ms_exc.registration.TryLevel = 0;
  if ( !*file )
  {
    *_errno() = 22;
    _local_unwind4(&__security_cookie, (int)&ms_exc.registration, 0xFFFFFFFE);
    return 0;
  }
  retval = _openfile((int)file, file, mode, shflag, v6);
  _unlock_file(stream);
  return retval;
}
