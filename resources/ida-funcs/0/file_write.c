unsigned int __usercall file_write@<eax>(int a1@<ebx>, int a2@<edi>, bio_st *b, const __m128i *in, unsigned int inl)
{
  unsigned int result; // eax

  result = 0;
  if ( b->init && in )
  {
    result = fwrite(a1, a2, in, inl, 1u, (_iobuf *)b->ptr);
    if ( result )
      return inl;
  }
  return result;
}
