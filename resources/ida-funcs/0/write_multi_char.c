void __usercall write_multi_char(int *pnumwritten@<eax>, int a2@<ebx>, int a3@<edi>, char ch, int num, _iobuf *f)
{
  int *v6; // esi

  v6 = pnumwritten;
  do
  {
    if ( num <= 0 )
      break;
    LOBYTE(pnumwritten) = ch;
    --num;
    write_char((int)pnumwritten, f, v6, a2, a3);
  }
  while ( *v6 != -1 );
}
