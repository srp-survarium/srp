void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_86F340 )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(pf - _iob + 16);
  }
}
