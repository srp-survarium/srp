int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( !str )
    return flsall(0);
  if ( _flush(str) )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno(str);
  return -(_commit(v2) != 0);
}
