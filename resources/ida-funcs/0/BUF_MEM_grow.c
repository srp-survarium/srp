unsigned int __cdecl BUF_MEM_grow(buf_mem_st *str, unsigned int len)
{
  char *data; // eax
  unsigned int v4; // ebx
  char *v5; // eax
  int v6; // [esp-10h] [ebp-18h]
  int v7; // [esp-8h] [ebp-10h]

  if ( str->length >= len )
    goto LABEL_4;
  if ( str->max >= len )
  {
    memset((int)&str->data[str->length], 0, len - str->length);
LABEL_4:
    str->length = len;
    return len;
  }
  data = str->data;
  v4 = 4 * ((len + 3) / 3);
  if ( data )
    v5 = (char *)CRYPTO_realloc(data, 4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 112);
  else
    v5 = (char *)CRYPTO_malloc(4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 110);
  if ( v5 )
  {
    v7 = len - str->length;
    v6 = (int)&v5[str->length];
    str->data = v5;
    str->max = v4;
    memset(v6, 0, v7);
    str->length = len;
    return len;
  }
  else
  {
    ERR_put_error(v4, 7u, 100, 65, ".\\crypto\\buffer\\buffer.c", 115);
    return 0;
  }
}
