unsigned int __cdecl OBJ_obj2txt(char *buf, unsigned int buf_len, const asn1_object_st *a, int no_name)
{
  char *v4; // ebp
  unsigned int v5; // eax
  unsigned int v6; // ebx
  const char *v7; // edi
  bignum_st *v9; // ecx
  unsigned int v10; // esi
  int v11; // edi
  char v12; // bl
  bool v13; // zf
  bignum_st *v14; // eax
  unsigned int v15; // ebx
  const char *v16; // eax
  char *v17; // edi
  signed int v18; // esi
  signed int v19; // ebx
  signed int v20; // kr00_4
  bignum_st *r; // [esp+8h] [ebp-38h]
  int size; // [esp+Ch] [ebp-34h]
  int v23; // [esp+10h] [ebp-30h]
  int length; // [esp+14h] [ebp-2Ch]
  int v25; // [esp+18h] [ebp-28h]
  const unsigned __int8 *data; // [esp+1Ch] [ebp-24h]
  char bufa[28]; // [esp+20h] [ebp-20h] BYREF

  v4 = buf;
  size = buf_len;
  v23 = 0;
  if ( !a || !a->data )
  {
    *buf = 0;
    return 0;
  }
  if ( !no_name )
  {
    v5 = OBJ_obj2nid(a);
    v6 = v5;
    if ( v5 )
    {
      v7 = OBJ_nid2ln(v5);
      if ( v7 || (v7 = OBJ_nid2sn(v6)) != 0 )
      {
        if ( buf )
          BUF_strlcpy(buf, v7, buf_len);
        return strlen(v7);
      }
    }
  }
  v9 = 0;
  length = a->length;
  data = a->data;
  v25 = 1;
  r = 0;
  if ( length <= 0 )
    return v23;
  while ( 2 )
  {
    v10 = 0;
    v11 = 0;
    while ( 1 )
    {
      v12 = *data;
      v13 = length-- == 1;
      ++data;
      if ( v13 && v12 < 0 )
        goto err_7;
      if ( v11 )
      {
        if ( !BN_add_word(v9, v12 & 0x7F) )
          goto LABEL_61;
        v9 = r;
      }
      else
      {
        v10 |= v12 & 0x7F;
      }
      if ( v12 >= 0 )
        break;
      if ( v11 )
        goto LABEL_28;
      if ( v10 <= (unsigned int)&vostok::memory::s_CRT_arena[22351415] )
      {
        v10 <<= 7;
      }
      else
      {
        if ( !v9 )
        {
          v14 = BN_new();
          r = v14;
          if ( !v14 )
            return -1;
          v9 = v14;
        }
        if ( !BN_set_word(v9, v10) )
          goto LABEL_61;
        v9 = r;
        v11 = 1;
LABEL_28:
        if ( !BN_lshift(v9, v9, 7) )
          goto LABEL_61;
        v9 = r;
      }
    }
    if ( !v25 )
      goto LABEL_42;
    v25 = 0;
    if ( v10 < 0x50 )
    {
      v15 = v10 / 0x28;
      v10 %= 0x28u;
      goto LABEL_38;
    }
    LOBYTE(v15) = 2;
    if ( !v11 )
    {
      v10 -= 80;
      goto LABEL_38;
    }
    if ( !BN_sub_word(v9, 0x50u) )
      goto LABEL_61;
    v9 = r;
LABEL_38:
    if ( v4 && size > 0 )
    {
      *v4++ = v15 + 48;
      --size;
    }
    ++v23;
LABEL_42:
    if ( v11 )
    {
      v16 = BN_bn2dec(v9);
      v17 = (char *)v16;
      if ( v16 )
      {
        v18 = strlen(v16);
        if ( v4 )
        {
          v19 = size;
          if ( size > 0 )
          {
            *v4++ = 46;
            v19 = size - 1;
          }
          BUF_strlcpy(v4, v17, v19);
          if ( v18 <= v19 )
          {
            v4 += v18;
            size = v19 - v18;
          }
          else
          {
            v4 += v19;
            size = 0;
          }
        }
        v23 += v18 + 1;
        CRYPTO_free(v17);
        goto LABEL_57;
      }
LABEL_61:
      v9 = r;
err_7:
      if ( v9 )
        BN_free(v9);
      return -1;
    }
    BIO_snprintf(bufa, 0x1Au, ".%lu", v10);
    v20 = strlen(bufa);
    if ( v4 && size > 0 )
    {
      BUF_strlcpy(v4, bufa, size);
      if ( v20 <= size )
      {
        v4 += v20;
        size -= v20;
      }
      else
      {
        v4 += size;
        size = 0;
      }
    }
    v23 += v20;
LABEL_57:
    if ( length > 0 )
    {
      v9 = r;
      continue;
    }
    break;
  }
  if ( r )
    BN_free(r);
  return v23;
}
