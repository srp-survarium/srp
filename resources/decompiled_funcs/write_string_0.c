void __usercall write_string_0(wchar_t *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  if ( (f->_flag & 0x40) == 0 || f->_base )
  {
    while ( len > 0 )
    {
      --len;
      write_char_0(f, pnumwritten, *string++);
      if ( *pnumwritten == -1 )
      {
        if ( *_errno() != 42 )
          return;
        write_char_0(f, pnumwritten, 0x3Fu);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}
