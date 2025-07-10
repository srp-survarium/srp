unsigned int __cdecl mem_write(bio_st *b, char *in, unsigned int inl)
{
  buf_mem_st *ptr; // esi
  unsigned int length; // ebx
  unsigned int v6; // edi

  ptr = (buf_mem_st *)b->ptr;
  if ( in )
  {
    if ( (b->flags & 0x200) != 0 )
    {
      ERR_put_error(0x20u, 117, 126, ".\\crypto\\bio\\bss_mem.c", 183);
      return -1;
    }
    else
    {
      BIO_clear_flags(b, 15);
      length = ptr->length;
      v6 = ptr->length + inl;
      if ( BUF_MEM_grow_clean(ptr, v6) == v6 )
      {
        memcpy((unsigned __int8 *)&ptr->data[length], (unsigned __int8 *)in, inl);
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
    ERR_put_error(0x20u, 117, 115, ".\\crypto\\bio\\bss_mem.c", 178);
    return -1;
  }
}
