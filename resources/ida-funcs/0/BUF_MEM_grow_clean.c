unsigned int __cdecl BUF_MEM_grow_clean(buf_mem_st *str, unsigned int len)
{
  unsigned int length; // eax
  unsigned int max; // ecx
  char *data; // eax
  unsigned __int8 *v6; // eax
  int v7; // [esp-10h] [ebp-18h]
  unsigned int v8; // [esp-8h] [ebp-10h]

  length = str->length;
  if ( str->length < len )
  {
    max = str->max;
    if ( max < len )
    {
      data = str->data;
      if ( data )
        v6 = CRYPTO_realloc_clean(data, max, 4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 149);
      else
        v6 = (unsigned __int8 *)CRYPTO_malloc(4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 147);
      if ( v6 )
      {
        v8 = len - str->length;
        v7 = (int)&v6[str->length];
        str->data = (char *)v6;
        str->max = 4 * ((len + 3) / 3);
        memset(v7, 0, v8);
        str->length = len;
        return len;
      }
      else
      {
        ERR_put_error(7u, 105, 65, ".\\crypto\\buffer\\buffer.c", 152);
        return 0;
      }
    }
    else
    {
      memset((int)&str->data[length], 0, len - length);
      str->length = len;
      return len;
    }
  }
  else
  {
    memset((int)&str->data[len], 0, length - len);
    str->length = len;
    return len;
  }
}
