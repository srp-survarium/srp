unsigned int __usercall file_puts@<eax>(unsigned int a1@<ebx>, bio_st *bp, char *str)
{
  unsigned int v3; // esi
  unsigned int result; // eax

  v3 = strlen(str);
  result = 0;
  if ( bp->init && str )
  {
    result = fwrite(a1, (unsigned int)str, (unsigned __int8 *)str, v3, 1u, (_iobuf *)bp->ptr);
    if ( result )
      return v3;
  }
  return result;
}
