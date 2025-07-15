unsigned int __cdecl compress2(
        unsigned __int8 *dest,
        unsigned int *destLen,
        unsigned __int8 *source,
        unsigned int sourceLen,
        unsigned int level)
{
  unsigned int result; // eax
  int v6; // esi
  z_stream_s stream; // [esp+4h] [ebp-38h] BYREF

  stream.avail_in = sourceLen;
  stream.next_out = dest;
  stream.next_in = source;
  stream.avail_out = *destLen;
  memset(&stream.zalloc, 0, 12);
  result = deflateInit_(&stream, level, "1.2.3", 56);
  if ( !result )
  {
    v6 = deflate(&stream, 4u);
    if ( v6 == 1 )
    {
      *destLen = stream.total_out;
      return deflateEnd(&stream);
    }
    else
    {
      deflateEnd(&stream);
      result = -5;
      if ( v6 )
        return v6;
    }
  }
  return result;
}
