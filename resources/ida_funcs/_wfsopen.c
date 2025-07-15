_iobuf *__usercall _wfsopen@<eax>(const wchar_t *a1@<edi>, _iobuf *file, const wchar_t *mode, int shflag)
{
  _iobuf *v6; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( !file || (a1 = mode) == 0 || !*mode )
  {
    *_errno() = 22;
    _invalid_parameter((unsigned int)file, (unsigned int)a1, 0);
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
  if ( !LOWORD(file->_ptr) )
  {
    *_errno() = 22;
    _local_unwind4(&__security_cookie, (int)&ms_exc.registration, 0xFFFFFFFE);
    return 0;
  }
  retval = _wopenfile((const wchar_t *)file, mode, shflag, v6);
  _unlock_file(stream);
  return retval;
}
