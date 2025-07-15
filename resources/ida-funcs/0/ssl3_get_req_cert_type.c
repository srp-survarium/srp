int __cdecl ssl3_get_req_cert_type(ssl_st *s, unsigned __int8 *p)
{
  unsigned int algorithm_mkey; // edx
  int v3; // eax
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  algorithm_mkey = s->s3->tmp.new_cipher->algorithm_mkey;
  v3 = 0;
  if ( s->version >= 769 && (algorithm_mkey & 0x200) != 0 )
  {
    *p = 21;
    p[1] = 22;
    return 2;
  }
  if ( (algorithm_mkey & 0xA) != 0 )
  {
    *p = 3;
    p[1] = 4;
    v3 = 2;
  }
  if ( s->version == 768 && (algorithm_mkey & 0xE) != 0 )
  {
    p[v3] = 5;
    v5 = v3 + 1;
    p[v5] = 6;
    v3 = v5 + 1;
  }
  p[v3] = 1;
  v6 = v3 + 1;
  p[v6] = 2;
  result = v6 + 1;
  if ( (algorithm_mkey & 0x60) != 0 )
  {
    if ( s->version < 769 )
      return result;
    p[result] = 65;
    v7 = result + 1;
    p[v7] = 66;
    result = v7 + 1;
  }
  if ( s->version >= 769 )
    p[result++] = 64;
  return result;
}
