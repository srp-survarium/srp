unsigned int __usercall _fread_nolock_s@<eax>(
        _iobuf *a1@<esi>,
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int cnt; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned __int8 *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int bufsiz; // [esp+10h] [ebp-Ch]
  unsigned __int8 *buf; // [esp+14h] [ebp-8h]
  unsigned int sizeInBytes; // [esp+18h] [ebp-4h]

  v6 = bufferSize;
  v7 = 0;
  buf = buffer;
  sizeInBytes = bufferSize;
  if ( !elementSize || !num )
    return 0;
  if ( !buffer )
    goto LABEL_4;
  a1 = stream;
  if ( !stream || num > 0xFFFFFFFF / elementSize )
  {
    if ( bufferSize != -1 )
      memset((int)buffer, 0, bufferSize);
    if ( !stream || num > 0xFFFFFFFF / elementSize )
    {
LABEL_4:
      *_errno() = 22;
LABEL_5:
      _invalid_parameter(v6, v7, (int)a1);
      return 0;
    }
  }
  v7 = num * elementSize;
  v6 = num * elementSize;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsiz = stream->_bufsiz;
  else
    bufsiz = 4096;
  if ( !v7 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x10C) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt )
      {
        if ( cnt < 0 )
          goto LABEL_47;
        v7 = v6;
        if ( v6 >= cnt )
          v7 = stream->_cnt;
        if ( v7 <= sizeInBytes )
        {
          memcpy_s(v6, buf, sizeInBytes, (unsigned __int8 *)stream->_ptr, v7);
          stream->_cnt -= v7;
          stream->_ptr += v7;
          buf += v7;
          v6 -= v7;
          sizeInBytes -= v7;
          v7 = num * elementSize;
          goto LABEL_39;
        }
        a1 = 0;
        if ( bufferSize != -1 )
          memset((int)buffer, 0, bufferSize);
LABEL_43:
        *_errno() = 34;
        goto LABEL_5;
      }
    }
    if ( v6 < bufsiz )
    {
      v15 = _filbuf(v6, stream);
      if ( v15 == -1 )
        return (v7 - v6) / elementSize;
      if ( sizeInBytes )
      {
        v16 = buf++;
        *v16 = v15;
        --v6;
        --sizeInBytes;
        bufsiz = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_44:
      if ( bufferSize != -1 )
        memset((int)buffer, 0, bufferSize);
      goto LABEL_43;
    }
    if ( bufsiz )
    {
      if ( v6 <= 0x7FFFFFFF )
      {
        v10 = v6 % bufsiz;
        v11 = v6;
      }
      else
      {
        v10 = 0x7FFFFFFF % bufsiz;
        v11 = 0x7FFFFFFF;
      }
      v12 = v11 - v10;
    }
    else
    {
      v12 = 0x7FFFFFFF;
      if ( v6 <= 0x7FFFFFFF )
        v12 = v6;
    }
    if ( v12 > sizeInBytes )
      goto LABEL_44;
    v17 = v12;
    v13 = _fileno(v6, v7, stream);
    v14 = _read(v13, buf, v17);
    if ( !v14 )
      break;
    if ( v14 == -1 )
    {
LABEL_47:
      stream->_flag |= 0x20u;
      return (v7 - v6) / elementSize;
    }
    buf += v14;
    v6 -= v14;
    sizeInBytes -= v14;
LABEL_39:
    if ( !v6 )
      return num;
  }
  stream->_flag |= 0x10u;
  return (v7 - v6) / elementSize;
}
