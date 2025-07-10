_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( !file || !mode || !*mode )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return 0;
  }
  v5 = _getstream();
  stream = v5;
  if ( !v5 )
  {
    *_errno() = 24;
    return 0;
  }
  ms_exc.registration.TryLevel = 0;
  if ( !LOBYTE(file->_ptr) )
  {
    *_errno() = 22;
    _local_unwind4(&__security_cookie, &ms_exc.registration, -2);
    return 0;
  }
  retval = _openfile((const char *)file, mode, shflag, v5);
  _unlock_file(stream);
  return retval;
}
