unsigned int __cdecl BUF_MEM_grow(buf_mem_st *str, unsigned int len)
{
  char *data; // eax
  char *v4; // eax
  int v5; // [esp-10h] [ebp-18h]
  unsigned int v6; // [esp-8h] [ebp-10h]

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
  if ( data )
    v4 = (char *)CRYPTO_realloc(data, 4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 112);
  else
    v4 = (char *)CRYPTO_malloc(4 * ((len + 3) / 3), ".\\crypto\\buffer\\buffer.c", 110);
  if ( v4 )
  {
    v6 = len - str->length;
    v5 = (int)&v4[str->length];
    str->data = v4;
    str->max = 4 * ((len + 3) / 3);
    memset(v5, 0, v6);
    str->length = len;
    return len;
  }
  else
  {
    ERR_put_error(7u, 100, 65, ".\\crypto\\buffer\\buffer.c", 115);
    return 0;
  }
}
