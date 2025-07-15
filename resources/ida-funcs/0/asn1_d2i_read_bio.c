int __usercall asn1_d2i_read_bio@<eax>(int a1@<ebx>, bio_st *in, buf_mem_st **pb)
{
  int v3; // esi
  int v4; // ebp
  buf_mem_st *v5; // ebx
  int result; // eax
  int v7; // eax
  bool v8; // cc
  const unsigned __int8 *v9; // edi
  int object; // eax
  int v11; // eax
  unsigned int v12; // edi
  int v13; // edi
  int v14; // eax
  int v15; // [esp-8h] [ebp-48h]
  int v16; // [esp+Ch] [ebp-34h]
  const unsigned __int8 *v17; // [esp+14h] [ebp-2Ch] BYREF
  int v18; // [esp+20h] [ebp-20h]
  int v19; // [esp+24h] [ebp-1Ch] BYREF
  int v20; // [esp+28h] [ebp-18h] BYREF
  unsigned int v21[5]; // [esp+2Ch] [ebp-14h] BYREF

  v3 = 0;
  v16 = 0;
  v4 = 0;
  v5 = BUF_MEM_new(a1);
  if ( !v5 )
  {
    ERR_put_error(0, 0xDu, 107, 65, ".\\crypto\\asn1\\a_d2i_fp.c", 161);
    return -1;
  }
  ERR_clear_error((int)v5);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v3 - v4 <= 8 )
      {
        if ( !BUF_MEM_grow_clean(v5, v4 + 8) )
        {
          ERR_put_error((int)v5, 0xDu, 107, 65, ".\\crypto\\asn1\\a_d2i_fp.c", 174);
          goto err_56;
        }
        v7 = BIO_read((int)v5, in, &v5->data[v3], v4 - v3 + 8);
        v8 = v7 <= 0;
        if ( v7 < 0 )
        {
          if ( v3 == v4 )
          {
            v15 = 180;
            goto LABEL_33;
          }
          v8 = v7 <= 0;
        }
        if ( !v8 )
          v3 += v7;
      }
      v9 = (const unsigned __int8 *)&v5->data[v4];
      v17 = v9;
      object = ASN1_get_object((const unsigned __int8 **)v5, &v17, v21, &v19, &v20, (const unsigned __int8 *)(v3 - v4));
      v18 = object;
      if ( (object & 0x80u) != 0 )
      {
        if ( (ERR_peek_error() & 0xFFF) != 0x9B )
          goto err_56;
        ERR_clear_error((int)v5);
        LOBYTE(object) = v18;
      }
      v4 += v17 - v9;
      if ( (object & 1) == 0 )
        break;
      ++v16;
    }
    v11 = v16;
    v12 = v21[0];
    if ( !v16 || v21[0] || v19 )
      break;
    v11 = --v16;
LABEL_20:
    if ( v11 <= 0 )
    {
      result = v4;
      *pb = v5;
      return result;
    }
  }
  if ( (int)v21[0] <= v3 - v4 )
  {
LABEL_28:
    v4 += v12;
    goto LABEL_20;
  }
  v13 = v4 + v21[0] - v3;
  if ( !BUF_MEM_grow_clean(v5, v4 + v21[0]) )
  {
    ERR_put_error((int)v5, 0xDu, 107, 65, ".\\crypto\\asn1\\a_d2i_fp.c", 229);
    goto err_56;
  }
  if ( v13 <= 0 )
  {
LABEL_27:
    v12 = v21[0];
    v11 = v16;
    goto LABEL_28;
  }
  while ( 1 )
  {
    v14 = BIO_read((int)v5, in, &v5->data[v3], v13);
    if ( v14 <= 0 )
      break;
    v13 -= v14;
    v3 += v14;
    if ( v13 <= 0 )
      goto LABEL_27;
  }
  v15 = 238;
LABEL_33:
  ERR_put_error((int)v5, 0xDu, 107, 142, ".\\crypto\\asn1\\a_d2i_fp.c", v15);
err_56:
  BUF_MEM_free(v5);
  return -1;
}
