_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, 64);
}
