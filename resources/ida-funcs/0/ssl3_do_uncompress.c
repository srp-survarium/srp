int __cdecl ssl3_do_uncompress(ssl_st *ssl)
{
  ssl3_state_st *s3; // esi
  int length; // ecx
  unsigned __int8 *data; // edx
  ssl3_record_st *p_rrec; // esi
  int v5; // eax

  s3 = ssl->s3;
  length = s3->rrec.length;
  data = s3->rrec.data;
  p_rrec = &s3->rrec;
  v5 = COMP_expand_block(ssl->expand, p_rrec->comp, 0x4000, data, length);
  if ( v5 < 0 )
    return 0;
  p_rrec->length = v5;
  p_rrec->data = p_rrec->comp;
  return 1;
}
