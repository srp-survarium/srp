void __usercall oggpack_writeclear(oggpack_buffer *b@<eax>)
{
  unsigned __int8 *buffer; // eax
  int *p_endbit; // edi

  buffer = b->buffer;
  if ( buffer )
    ogg_free_impl(buffer);
  b->endbyte = 0;
  p_endbit = &b->endbit;
  *p_endbit++ = 0;
  *p_endbit++ = 0;
  *p_endbit = 0;
  p_endbit[1] = 0;
}
