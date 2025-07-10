unsigned int __cdecl _fread_nolock_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  char *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( !elementSize || !num )
    return 0;
  if ( !buffer )
    goto LABEL_4;
  if ( !stream || num > 0xFFFFFFFF / elementSize )
  {
    if ( bufferSize != -1 )
      memset((int)buffer, 0, bufferSize);
    if ( !stream || num > 0xFFFFFFFF / elementSize )
    {
LABEL_4:
      *_errno() = 22;
      _invalid_parameter(0, 0, 0, 0, 0);
      return 0;
    }
  }
  v6 = num * elementSize;
  v7 = num * elementSize;
  if ( (stream->_flag & 0x10C) != 0 )
    streambufsize = stream->_bufsiz;
  else
    streambufsize = 4096;
  if ( !v6 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x10C) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt )
      {
        if ( cnt < 0 )
          goto LABEL_46;
        v9 = v7;
        if ( v7 >= cnt )
          v9 = stream->_cnt;
        if ( v9 <= dataSize )
        {
          memcpy_s(data, dataSize, stream->_ptr, v9);
          stream->_cnt -= v9;
          stream->_ptr += v9;
          data += v9;
          v7 -= v9;
          dataSize -= v9;
          v6 = num * elementSize;
          goto LABEL_38;
        }
        if ( bufferSize != -1 )
          memset((int)buffer, 0, bufferSize);
LABEL_42:
        *_errno() = 34;
        _invalid_parameter(0, 0, 0, 0, 0);
        return 0;
      }
    }
    if ( v7 < streambufsize )
    {
      v15 = _filbuf(stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_38;
      }
LABEL_43:
      if ( bufferSize != -1 )
        memset((int)buffer, 0, bufferSize);
      goto LABEL_42;
    }
    if ( streambufsize )
    {
      if ( v7 <= 0x7FFFFFFF )
      {
        v10 = v7 % streambufsize;
        v11 = v7;
      }
      else
      {
        v10 = 0x7FFFFFFF % streambufsize;
        v11 = 0x7FFFFFFF;
      }
      v12 = v11 - v10;
    }
    else
    {
      v12 = 0x7FFFFFFF;
      if ( v7 <= 0x7FFFFFFF )
        v12 = v7;
    }
    if ( v12 > dataSize )
      goto LABEL_43;
    v17 = v12;
    v13 = _fileno(stream);
    v14 = _read(v13, data, v17);
    if ( !v14 )
      break;
    if ( v14 == -1 )
    {
LABEL_46:
      stream->_flag |= 0x20u;
      return (v6 - v7) / elementSize;
    }
    data += v14;
    v7 -= v14;
    dataSize -= v14;
LABEL_38:
    if ( !v7 )
      return num;
  }
  stream->_flag |= 0x10u;
  return (v6 - v7) / elementSize;
}
