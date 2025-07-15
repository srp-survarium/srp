void __usercall write_multi_char_0(int *pnumwritten@<eax>, wchar_t ch, int num, _iobuf *f)
{
  do
  {
    if ( num <= 0 )
      break;
    --num;
    write_char_0(f, pnumwritten, ch);
  }
  while ( *pnumwritten != -1 );
}
