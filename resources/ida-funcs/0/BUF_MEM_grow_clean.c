unsigned int __cdecl BUF_MEM_grow_clean(buf_mem_st *str, unsigned int len)
{
  unsigned int length; // eax
  unsigned int max; // ecx
  __m128i *data; // eax
  unsigned int v6; // ebx
  char *v7; // eax
  int v8; // [esp-10h] [ebp-18h]
  int v9; // [esp-8h] [ebp-10h]

  length = str->length;
  if ( str->length < len )
  {
    max = str->max;
    if ( max < len )
    {
      data = (__m128i *)str->data;
      v6 = 4 * ((len + 3) / 3);
      if ( data )
        v7 = (char *)CRYPTO_realloc_clean(data, max, 4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 149);
      else
        v7 = (char *)CRYPTO_malloc(4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 147);
      if ( v7 )
      {
        v9 = len - str->length;
        v8 = (int)&v7[str->length];
        str->data = v7;
        str->max = v6;
        memset(v8, 0, v9);
        str->length = len;
        return len;
      }
      else
      {
        ERR_put_error(v6, 7u, 105, 65, ".\\crypto\\buffer\\buffer.c", 152);
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
