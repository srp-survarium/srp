int __usercall whiteout@<eax>(int *counter@<esi>, int ebx0@<ebx>, _iobuf *fileptr)
{
  do
  {
    ++*counter;
    ebx0 = inc(fileptr, ebx0);
  }
  while ( ebx0 != -1 && isspace((unsigned __int8)ebx0) );
  return ebx0;
}
