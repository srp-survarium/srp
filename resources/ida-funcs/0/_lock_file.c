void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_86F340 )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}
