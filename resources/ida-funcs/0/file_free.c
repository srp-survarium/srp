int __usercall file_free@<eax>(int a1@<ebx>, bio_st *a)
{
  if ( !a )
    return 0;
  if ( a->shutdown )
  {
    if ( a->init )
    {
      if ( a->ptr )
      {
        fclose(a1, (_iobuf *)a->ptr);
        a->ptr = 0;
        a->flags = 0;
      }
    }
    a->init = 0;
  }
  return 1;
}
