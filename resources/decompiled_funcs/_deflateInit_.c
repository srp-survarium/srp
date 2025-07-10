int __cdecl deflateInit_(z_stream_s *strm, unsigned int level, const char *version, int stream_size)
{
  return deflateInit2_(strm, level, 8, 15, 8, 0, version, stream_size);
}
