int __cdecl ssl23_write_bytes(ssl_st *s)
{
  char *data; // ebp
  int init_off; // ebx
  int init_num; // edi
  int result; // eax
  bio_st *wbio; // [esp-Ch] [ebp-1Ch]

  data = s->init_buf->data;
  init_off = s->init_off;
  init_num = s->init_num;
  wbio = s->wbio;
  s->rwstate = 2;
  result = BIO_write(init_off, wbio, &data[init_off], init_num);
  if ( result <= 0 )
  {
LABEL_4:
    s->init_num = init_num;
    s->init_off = init_off;
  }
  else
  {
    while ( 1 )
    {
      s->rwstate = 1;
      if ( result == init_num )
        break;
      init_num -= result;
      init_off += result;
      s->rwstate = 2;
      result = BIO_write(init_off, s->wbio, &data[init_off], init_num);
      if ( result <= 0 )
        goto LABEL_4;
    }
    result += init_off;
  }
  return result;
}
