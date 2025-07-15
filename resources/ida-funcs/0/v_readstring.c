void __usercall v_readstring(char *buf@<eax>, oggpack_buffer *o, int bytes)
{
  for ( ; bytes; ++buf )
  {
    --bytes;
    *buf = oggpack_read(o, 8u);
  }
}
