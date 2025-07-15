void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  int *v4; // esi
  int *v6; // eax

  v4 = pnumwritten;
  if ( (f->_flag & 0x40) == 0 || f->_base )
  {
    while ( len > 0 )
    {
      LOBYTE(pnumwritten) = *string;
      --len;
      write_char((int)pnumwritten, f, v4, (int)string++, (int)f);
      if ( *v4 == -1 )
      {
        v6 = _errno();
        if ( *v6 != 42 )
          return;
        LOBYTE(v6) = 63;
        write_char((int)v6, f, v4, (int)string, (int)f);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}
