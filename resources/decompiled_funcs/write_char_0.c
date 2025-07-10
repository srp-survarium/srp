void __usercall write_char_0(_iobuf *f@<eax>, int *pnumwritten@<esi>, wchar_t ch)
{
  if ( ((f->_flag & 0x40) == 0 || f->_base) && _fputwc_nolock(ch, f) == 0xFFFF )
    *pnumwritten = -1;
  else
    ++*pnumwritten;
}
