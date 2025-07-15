unsigned int __usercall _fwrite_nolock@<eax>(
        int a1@<ebx>,
        const __m128i *buffer,
        unsigned int size,
        unsigned int num,
        _iobuf *stream)
{
  int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edi
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  int bufsiz; // [esp+10h] [ebp-8h]
  const __m128i *src; // [esp+14h] [ebp-4h]

  if ( !size || !num )
    return 0;
  if ( !stream || !buffer || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, (int)stream);
    return 0;
  }
  v6 = num * size;
  src = buffer;
  v7 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsiz = stream->_bufsiz;
  else
    bufsiz = 4096;
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
        memcpy((int)stream->_ptr, src, v9);
        stream->_cnt -= v9;
        stream->_ptr += v9;
        v7 -= v9;
        src = (const __m128i *)((char *)src + v9);
        goto LABEL_27;
      }
    }
    if ( v7 >= bufsiz )
      break;
    if ( _flsbuf(v7, v6, src->m128i_i8[0], stream) == -1 )
      goto LABEL_34;
    src = (const __m128i *)((char *)src + 1);
    --v7;
    bufsiz = stream->_bufsiz;
    if ( bufsiz <= 0 )
      bufsiz = 1;
LABEL_31:
    if ( !v7 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(stream) )
    goto LABEL_34;
  v10 = v7;
  if ( bufsiz )
    v10 = v7 - v7 % bufsiz;
  v11 = _fileno(v7, v10, stream);
  v12 = _write(v11, src, v10);
  if ( v12 != -1 )
  {
    v13 = v10;
    if ( v12 <= v10 )
      v13 = v12;
    src = (const __m128i *)((char *)src + v13);
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
