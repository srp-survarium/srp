int __cdecl MDC2_Final(unsigned __int8 *md, mdc2_ctx_st *c)
{
  unsigned int num; // eax
  int pad_type; // ecx

  num = c->num;
  pad_type = c->pad_type;
  if ( c->num )
  {
    if ( pad_type != 2 )
    {
LABEL_6:
      memset((int)&c->data[num], 0, 8 - num);
      mdc2_body(c, 8u);
      goto LABEL_7;
    }
LABEL_5:
    c->data[num++] = 0x80;
    goto LABEL_6;
  }
  if ( pad_type == 2 )
    goto LABEL_5;
LABEL_7:
  *(_QWORD *)md = *(_QWORD *)c->h;
  *((_QWORD *)md + 1) = *(_QWORD *)c->hh;
  return 1;
}
