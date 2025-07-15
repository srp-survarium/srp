void __usercall write_multi_char_0(
        int *pnumwritten@<eax>,
        ioinfo *a2@<ebx>,
        stlp_std::ioinfo **a3@<edi>,
        wchar_t ch,
        int num,
        _iobuf *f)
{
  do
  {
    if ( num <= 0 )
      break;
    --num;
    write_char_0(f, pnumwritten, a2, a3, ch);
  }
  while ( *pnumwritten != -1 );
}
