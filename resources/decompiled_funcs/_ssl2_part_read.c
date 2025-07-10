int __cdecl ssl2_part_read(ssl_st *s, __int16 f, int i)
{
  int result; // eax
  unsigned __int8 *data; // edi
  __int16 v5; // ax
  signed int init_num; // esi

  result = i;
  if ( i >= 0 )
  {
    s->init_num += i;
    if ( s->init_num >= 3 )
    {
      data = (unsigned __int8 *)s->init_buf->data;
      if ( !*data )
      {
        v5 = ssl_mt_error(data[2] | (data[1] << 8));
        ERR_put_error(0x14u, f, v5, ".\\ssl\\s2_pkt.c", 682);
        s->init_num -= 3;
        init_num = s->init_num;
        if ( init_num > 0 )
          memmove(data, data + 3, init_num);
      }
    }
    return 0;
  }
  return result;
}
