void __usercall write_multi_char(int *pnumwritten@<eax>, char ch, int num, _iobuf *f)
{
  int *v4; // esi

  v4 = pnumwritten;
  do
  {
    if ( num <= 0 )
      break;
    LOBYTE(pnumwritten) = ch;
    --num;
    write_char((int)pnumwritten, f, v4);
  }
  while ( *v4 != -1 );
}
