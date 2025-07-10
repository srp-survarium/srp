unsigned int __cdecl fread(char *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, 0xFFFFFFFF, elementSize, count, stream);
}
