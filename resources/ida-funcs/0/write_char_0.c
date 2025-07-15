void __usercall write_char_0(
        _iobuf *f@<eax>,
        int *pnumwritten@<esi>,
        ioinfo *a3@<ebx>,
        stlp_std::ioinfo **a4@<edi>,
        wchar_t ch)
{
  if ( ((f->_flag & 0x40) == 0 || f->_base) && _fputwc_nolock(a3, a4, ch, f) == 0xFFFF )
    *pnumwritten = -1;
  else
    ++*pnumwritten;
}
