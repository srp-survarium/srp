unsigned int __usercall _fwrite_nolock@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int8 *buffer,
        unsigned int size,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edi
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( !size || !num )
    return 0;
  if ( !stream || !buffer || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, (unsigned int)stream);
    return 0;
  }
  v6 = num * size;
  data = buffer;
  v7 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( !v6 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v14 = v6;
          return (v14 - v7) / size;
        }
        v9 = v7;
        if ( v7 >= cnt )
          v9 = stream->_cnt;
        memcpy((unsigned __int8 *)stream->_ptr, data, v9);
        stream->_cnt -= v9;
        stream->_ptr += v9;
        v7 -= v9;
        data += v9;
        goto LABEL_27;
      }
    }
    if ( v7 >= bufsize )
      break;
    if ( _flsbuf(*data, (int)stream) == -1 )
      goto LABEL_34;
    ++data;
    --v7;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( !v7 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(stream) )
    goto LABEL_34;
  v10 = v7;
  if ( bufsize )
    v10 = v7 - v7 % bufsize;
  v11 = _fileno(stream);
  v12 = _write(v11, data, v10);
  if ( v12 != -1 )
  {
    v13 = v10;
    if ( v12 <= v10 )
      v13 = v12;
    data += v13;
    v7 -= v13;
    if ( v12 >= v10 )
    {
LABEL_27:
      v6 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v14 = num * size;
  return (v14 - v7) / size;
}
