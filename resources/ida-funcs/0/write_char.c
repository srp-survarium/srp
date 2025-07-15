void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf(ch, (int)f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}
