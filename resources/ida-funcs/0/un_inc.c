void __usercall un_inc(int a1@<ebx>, int a2@<edi>, int chr, _iobuf *fileptr)
{
  if ( chr != -1 )
    _ungetc_nolock(a1, a2, chr, fileptr);
}
