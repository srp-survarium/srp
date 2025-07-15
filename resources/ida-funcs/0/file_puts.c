unsigned int __usercall file_puts@<eax>(int a1@<ebx>, bio_st *bp, const __m128i *str)
{
  unsigned int v3; // esi
  unsigned int result; // eax

  v3 = strlen(str->m128i_i8);
  result = 0;
  if ( bp->init && str )
  {
    result = fwrite(a1, (int)str, str, v3, 1u, (_iobuf *)bp->ptr);
    if ( result )
      return v3;
  }
  return result;
}
