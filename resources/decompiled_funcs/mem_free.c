int __cdecl mem_free(bio_st *a)
{
  buf_mem_st *ptr; // eax

  if ( !a )
    return 0;
  if ( a->shutdown )
  {
    if ( a->init )
    {
      ptr = (buf_mem_st *)a->ptr;
      if ( ptr )
      {
        if ( (a->flags & 0x200) != 0 )
          ptr->data = 0;
        BUF_MEM_free(ptr);
        a->ptr = 0;
      }
    }
  }
  return 1;
}
