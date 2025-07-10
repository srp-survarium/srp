HANDLE __termcon()
{
  HANDLE result; // eax

  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    CloseHandle(_confh);
  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(_coninpfh);
  return result;
}
