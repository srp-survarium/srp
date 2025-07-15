void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>, int a4@<ebx>, int a5@<edi>)
{
  bool v5; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base)
    && ((v5 = f->_cnt - 1 < 0, --f->_cnt, v5)
      ? (ch = _flsbuf(a4, a5, ch, f))
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
