unsigned int __usercall file_write@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        bio_st *b,
        char *in,
        unsigned int inl)
{
  unsigned int result; // eax

  result = 0;
  if ( b->init && in )
  {
    result = fwrite(a1, a2, (unsigned __int8 *)in, inl, 1u, (_iobuf *)b->ptr);
    if ( result )
      return inl;
  }
  return result;
}
