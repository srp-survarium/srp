int __cdecl asn1_Finish(asn1_const_ctx_st *c)
{
  int inf; // edx
  int slen; // ecx
  const unsigned __int8 *p; // ecx
  int v4; // ecx

  inf = c->inf;
  if ( inf == 33 && !c->eos )
  {
    slen = c->slen;
    if ( slen > 0 )
    {
      if ( slen < 2 || (p = c->p, *c->p) || p[1] )
      {
        c->error = 63;
        return 0;
      }
      c->p = p + 2;
    }
  }
  v4 = c->slen;
  if ( !v4 || (inf & 1) != 0 && (v4 >= 0 || (inf & 1) == 0) )
    return 1;
  c->error = 62;
  return 0;
}
