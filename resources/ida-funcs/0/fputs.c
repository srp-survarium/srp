int __usercall fputs@<eax>(int a1@<ebx>, _iobuf *a2@<edi>, __m128i *string, _iobuf *stream)
{
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  unsigned int v8; // eax
  int v9; // esi
  unsigned int ndone; // [esp+10h] [ebp-20h]
  unsigned int length; // [esp+14h] [ebp-1Ch]

  if ( string
    && (a2 = stream) != 0
    && ((stream->_flag & 0x40) != 0
     || ((v5 = _fileno(a1, (int)stream, stream), v5 == -1) || v5 == -2
       ? (v6 = &__badioinfo)
       : (v6 = (ioinfo *)((char *)__pioinfo[v5 >> 5] + 64 * (v5 & 0x1F))),
         (*((_BYTE *)v6 + 36) & 0x7F) == 0
      && (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = (ioinfo *)((char *)__pioinfo[v5 >> 5] + 64 * (v5 & 0x1F))),
          *((char *)v7 + 36) >= 0))) )
  {
    strlen((unsigned __int8 *)string);
    length = v8;
    _lock_file(stream);
    v9 = _stbuf(a1, (int)stream, stream);
    ndone = _fwrite_nolock(a1, string, 1u, length, stream);
    _ftbuf(v9, stream);
    _unlock_file(stream);
    return (ndone == length) - 1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, (int)a2, 0);
    return -1;
  }
}
