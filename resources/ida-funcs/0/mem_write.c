unsigned int __usercall mem_write@<eax>(int a1@<ebx>, bio_st *b, const __m128i *in, unsigned int inl)
{
  buf_mem_st *ptr; // esi
  unsigned int length; // ebx
  unsigned int v7; // edi

  ptr = (buf_mem_st *)b->ptr;
  if ( in )
  {
    if ( (b->flags & 0x200) != 0 )
    {
      ERR_put_error(a1, 0x20u, 117, 126, ".\\crypto\\bio\\bss_mem.c", 183);
      return -1;
    }
    else
    {
      BIO_clear_flags(b, 15);
      length = ptr->length;
      v7 = ptr->length + inl;
      if ( BUF_MEM_grow_clean(ptr, v7) == v7 )
      {
        memcpy((int)&ptr->data[length], in, inl);
        return inl;
      }
      else
      {
        return -1;
      }
    }
  }
  else
  {
    ERR_put_error(a1, 0x20u, 117, 115, ".\\crypto\\bio\\bss_mem.c", 178);
    return -1;
  }
}
