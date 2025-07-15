void __usercall un_inc(unsigned int a1@<ebx>, int chr, _iobuf *fileptr)
{
  if ( chr != -1 )
    _ungetc_nolock(a1, chr, fileptr);
}
