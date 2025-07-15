void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = 0;
    stream->_base = 0;
    stream->_cnt = 0;
  }
}
