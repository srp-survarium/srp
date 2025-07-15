int __cdecl inflateInit_(z_stream_s *strm, const char *version, int stream_size)
{
  return inflateInit2_(strm, 15, version, stream_size);
}
