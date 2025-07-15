unsigned int __usercall whiteout@<eax>(int *counter@<esi>, unsigned int a2@<ebx>, _iobuf *fileptr)
{
  do
  {
    ++*counter;
    a2 = inc(fileptr, a2);
  }
  while ( a2 != -1 && isspace((unsigned __int8)a2) );
  return a2;
}
