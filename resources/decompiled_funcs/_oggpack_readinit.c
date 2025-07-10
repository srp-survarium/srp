void __usercall oggpack_readinit(oggpack_buffer *b@<eax>, unsigned __int8 *buf@<ecx>, int bytes)
{
  *(_QWORD *)&b->endbyte = 0;
  *(_QWORD *)&b->buffer = 0;
  b->storage = 0;
  b->ptr = buf;
  b->buffer = buf;
  b->storage = bytes;
}
