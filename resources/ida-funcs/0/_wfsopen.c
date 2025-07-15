_iobuf *__usercall _wfsopen@<eax>(const wchar_t *a1@<edi>, _iobuf *file, const wchar_t *mode, int shflag)
{
  unsigned int v4; // ebp
  _iobuf *v7; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( !file || (a1 = mode) == 0 || !*mode )
  {
    *_errno() = 22;
    _invalid_parameter((int)file, (int)a1, 0);
    return 0;
  }
  v7 = _getstream();
  stream = v7;
  if ( !v7 )
  {
    *_errno() = 24;
    return 0;
  }
  ms_exc.registration.TryLevel = 0;
  if ( !LOWORD(file->_ptr) )
  {
    *_errno() = 22;
    _local_unwind4(v4, &__security_cookie, (int)&ms_exc.registration, 0xFFFFFFFE);
    return 0;
  }
  retval = _wopenfile((const wchar_t *)file, mode, shflag, v7);
  _unlock_file(stream);
  return retval;
}
