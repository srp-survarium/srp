void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}
