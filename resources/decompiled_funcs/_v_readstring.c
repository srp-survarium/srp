void __usercall v_readstring(oggpack_buffer *o@<ecx>, int bytes@<eax>, char *buf)
{
  int i; // esi

  for ( i = bytes; i; ++buf )
  {
    --i;
    *buf = oggpack_read(o, 8u);
  }
}
