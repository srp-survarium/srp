int __cdecl asn1_d2i_read_bio(bio_st *in, buf_mem_st **pb)
{
  int v2; // esi
  int v3; // ebp
  buf_mem_st *v4; // ebx
  int result; // eax
  int v6; // eax
  bool v7; // cc
  unsigned __int8 *v8; // edi
  int object; // eax
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // eax
  int v14; // [esp-8h] [ebp-48h]
  int v15; // [esp+Ch] [ebp-34h]
  unsigned __int8 *pp; // [esp+14h] [ebp-2Ch] BYREF
  int v17; // [esp+20h] [ebp-20h]
  int ptag; // [esp+24h] [ebp-1Ch] BYREF
  int pclass; // [esp+28h] [ebp-18h] BYREF
  int plength[5]; // [esp+2Ch] [ebp-14h] BYREF

  v2 = 0;
  v15 = 0;
  v3 = 0;
  v4 = BUF_MEM_new();
  if ( !v4 )
  {
    ERR_put_error(0xDu, 107, 65, ".\\crypto\\asn1\\a_d2i_fp.c", 161);
    return -1;
  }
  ERR_clear_error();
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v2 - v3 <= 8 )
      {
        if ( !BUF_MEM_grow_clean(v4, v3 + 8) )
        {
          ERR_put_error(0xDu, 107, 65, ".\\crypto\\asn1\\a_d2i_fp.c", 174);
          goto err_54;
        }
        v6 = BIO_read(in, &v4->data[v2], v3 - v2 + 8);
        v7 = v6 <= 0;
        if ( v6 < 0 )
        {
          if ( v2 == v3 )
          {
            v14 = 180;
            goto LABEL_33;
          }
          v7 = v6 <= 0;
        }
        if ( !v7 )
          v2 += v6;
      }
      v8 = (unsigned __int8 *)&v4->data[v3];
      pp = v8;
      object = ASN1_get_object((const unsigned __int8 **)&pp, plength, &ptag, &pclass, (unsigned __int8 *)(v2 - v3));
      v17 = object;
      if ( (object & 0x80u) != 0 )
      {
        if ( (ERR_peek_error() & 0xFFF) != 0x9B )
          goto err_54;
        ERR_clear_error();
        LOBYTE(object) = v17;
      }
      v3 += pp - v8;
      if ( (object & 1) == 0 )
        break;
      ++v15;
    }
    v10 = v15;
    v11 = plength[0];
    if ( !v15 || plength[0] || ptag )
      break;
    v10 = --v15;
LABEL_20:
    if ( v10 <= 0 )
    {
      result = v3;
      *pb = v4;
      return result;
    }
  }
  if ( plength[0] <= v2 - v3 )
  {
LABEL_28:
    v3 += v11;
    goto LABEL_20;
  }
  v12 = v3 + plength[0] - v2;
  if ( !BUF_MEM_grow_clean(v4, v3 + plength[0]) )
  {
    ERR_put_error(0xDu, 107, 65, ".\\crypto\\asn1\\a_d2i_fp.c", 229);
    goto err_54;
  }
  if ( v12 <= 0 )
  {
LABEL_27:
    v11 = plength[0];
    v10 = v15;
    goto LABEL_28;
  }
  while ( 1 )
  {
    v13 = BIO_read(in, &v4->data[v2], v12);
    if ( v13 <= 0 )
      break;
    v12 -= v13;
    v2 += v13;
    if ( v12 <= 0 )
      goto LABEL_27;
  }
  v14 = 238;
LABEL_33:
  ERR_put_error(0xDu, 107, 142, ".\\crypto\\asn1\\a_d2i_fp.c", v14);
err_54:
  BUF_MEM_free(v4);
  return -1;
}
