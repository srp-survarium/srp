int __usercall _fflush_nolock@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *str)
{
  int v4; // eax

  if ( !str )
    return flsall(0);
  if ( _flush(str) )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v4 = _fileno(a1, a2, str);
  return -(_commit(v4) != 0);
}
