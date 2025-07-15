int __thiscall oggpack_bytes(oggpack_buffer *b)
{
  return b->endbyte + (b->endbit + 7) / 8;
}
