int __cdecl ssl3_do_compress(ssl_st *ssl)
{
  ssl3_state_st *s3; // esi
  int length; // ecx
  unsigned __int8 *input; // edx
  ssl3_record_st *p_wrec; // esi
  int v5; // eax

  s3 = ssl->s3;
  length = s3->wrec.length;
  input = s3->wrec.input;
  p_wrec = &s3->wrec;
  v5 = COMP_compress_block(ssl->compress, p_wrec->data, 17408, input, length);
  if ( v5 < 0 )
    return 0;
  p_wrec->length = v5;
  p_wrec->input = p_wrec->data;
  return 1;
}
