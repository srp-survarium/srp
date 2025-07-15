int __usercall ssl2_part_read@<eax>(int a1@<ebx>, ssl_st *s, __int16 f, int i)
{
  int result; // eax
  char *data; // edi
  __int16 v6; // ax
  signed int init_num; // esi

  result = i;
  if ( i >= 0 )
  {
    s->init_num += i;
    if ( s->init_num >= 3 )
    {
      data = s->init_buf->data;
      if ( !*data )
      {
        v6 = ssl_mt_error((unsigned __int8)data[2] | ((unsigned __int8)data[1] << 8));
        ERR_put_error(a1, 0x14u, f, v6, ".\\ssl\\s2_pkt.c", 682);
        s->init_num -= 3;
        init_num = s->init_num;
        if ( init_num > 0 )
          memmove((int)data, (const __m128i *)(data + 3), init_num);
      }
    }
    return 0;
  }
  return result;
}
