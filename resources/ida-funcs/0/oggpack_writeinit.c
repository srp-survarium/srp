void __usercall oggpack_writeinit(oggpack_buffer *b@<esi>)
{
  unsigned __int8 *v1; // eax

  b->endbyte = 0;
  b->endbit = 0;
  b->buffer = 0;
  b->ptr = 0;
  b->storage = 0;
  v1 = (unsigned __int8 *)ogg_malloc_impl(0x100u);
  b->buffer = v1;
  b->ptr = v1;
  *v1 = 0;
  b->storage = 256;
}
