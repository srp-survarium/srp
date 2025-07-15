int __cdecl asn1_check_tlen(
        int *olen,
        int *otag,
        unsigned __int8 *oclass,
        char *inf,
        char *cst,
        ASN1_TLC_st **in,
        unsigned __int8 *len,
        int exptag,
        int expclass,
        char opt,
        ASN1_TLC_st *ctx)
{
  ASN1_TLC_st *v11; // ecx
  ASN1_TLC_st *v12; // esi
  ASN1_TLC_st *v13; // edi
  ASN1_TLC_st *v14; // ecx
  int plen; // ebp
  int ret; // eax
  int v17; // edx
  int v18; // edx
  int pclass; // [esp+10h] [ebp-Ch] BYREF
  int ptag; // [esp+14h] [ebp-8h] BYREF
  int plength; // [esp+18h] [ebp-4h] BYREF

  v11 = *in;
  v12 = ctx;
  ctx = v11;
  v13 = v11;
  if ( v12 && v12->valid )
  {
    v14 = (ASN1_TLC_st *)((char *)v11 + v12->hdrlen);
    plen = v12->plen;
    ret = v12->ret;
    pclass = v12->pclass;
    v17 = v12->ptag;
    plength = plen;
    ptag = v17;
    ctx = v14;
  }
  else
  {
    ret = ASN1_get_object((const unsigned __int8 **)&ctx, &plength, &ptag, &pclass, len);
    plen = plength;
    if ( v12 )
    {
      v18 = ptag;
      v12->pclass = pclass;
      v14 = ctx;
      v12->ptag = v18;
      v12->ret = ret;
      v12->plen = plen;
      v12->hdrlen = (char *)v14 - (char *)v13;
      v12->valid = 1;
      if ( (ret & 0x81) == 0 && plen + (char *)v14 - (char *)v13 > (int)len )
      {
        ERR_put_error(0xDu, 104, 155, ".\\crypto\\asn1\\tasn_dec.c", 1297);
        v12->valid = 0;
        return 0;
      }
    }
    else
    {
      v14 = ctx;
    }
  }
  if ( (ret & 0x80u) != 0 )
  {
    ERR_put_error(0xDu, 104, 102, ".\\crypto\\asn1\\tasn_dec.c", 1306);
    if ( v12 )
      v12->valid = 0;
    return 0;
  }
  if ( exptag < 0 )
    goto LABEL_18;
  if ( exptag == ptag && expclass == pclass )
  {
    if ( v12 )
      v12->valid = 0;
LABEL_18:
    if ( (ret & 1) != 0 )
      plen = (int)&len[(char *)v13 - (char *)v14];
    if ( inf )
      *inf = ret & 1;
    if ( cst )
      *cst = ret & 0x20;
    if ( olen )
      *olen = plen;
    if ( oclass )
      *oclass = pclass;
    if ( otag )
      *otag = ptag;
    *in = v14;
    return 1;
  }
  if ( opt )
    return -1;
  if ( v12 )
    v12->valid = 0;
  ERR_put_error(0xDu, 104, 168, ".\\crypto\\asn1\\tasn_dec.c", 1319);
  return 0;
}
