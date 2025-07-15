void __cdecl _ftbuf(int flag, _iobuf *str)
{
  if ( flag )
  {
    if ( (str->_flag & 0x1000) != 0 )
    {
      _flush(str);
      str->_flag &= 0xFFFFEEFF;
      str->_bufsiz = 0;
      str->_ptr = 0;
      str->_base = 0;
    }
  }
}
