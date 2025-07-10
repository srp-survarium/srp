char *__cdecl X509_NAME_oneline(X509_name_st *a, char *buf, unsigned int len)
{
  X509_name_st *v3; // ebx
  unsigned __int8 **v4; // ebp
  buf_mem_st *v5; // eax
  buf_mem_st *v6; // edi
  unsigned int v7; // esi
  unsigned __int8 *v8; // edi
  unsigned __int8 *v10; // esi
  char *v11; // esi
  unsigned int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned int v14; // ebx
  int *v15; // eax
  int v16; // ebp
  int v17; // esi
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int j; // edx
  unsigned __int8 v22; // cl
  int v23; // edi
  int v24; // eax
  unsigned __int8 *v25; // esi
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // esi
  char *v28; // ecx
  unsigned __int8 *v29; // esi
  int v30; // edi
  _BYTE *v31; // esi
  int k; // ecx
  int v33; // eax
  _BYTE *v34; // esi
  const stack_st **v35; // ecx
  int v36; // esi
  const asn1_object_st *v37; // [esp-Ch] [ebp-9Ch]
  stack_st_X509_NAME_ENTRY *entries; // [esp-4h] [ebp-94h]
  const stack_st *v39; // [esp-4h] [ebp-94h]
  buf_mem_st *str; // [esp+10h] [ebp-80h]
  int v41; // [esp+14h] [ebp-7Ch]
  int v42; // [esp+18h] [ebp-78h]
  int v43; // [esp+1Ch] [ebp-74h]
  int v44; // [esp+20h] [ebp-70h]
  unsigned __int8 *dest; // [esp+24h] [ebp-6Ch]
  int i; // [esp+28h] [ebp-68h]
  unsigned __int8 *src; // [esp+2Ch] [ebp-64h]
  int v48; // [esp+30h] [ebp-60h]
  X509_name_st *v49; // [esp+34h] [ebp-5Ch]
  char *v50; // [esp+38h] [ebp-58h]
  char bufa[80]; // [esp+3Ch] [ebp-54h] BYREF
  int v52; // [esp+9Ch] [ebp+Ch]

  v3 = a;
  v4 = 0;
  v49 = a;
  dest = (unsigned __int8 *)buf;
  str = 0;
  if ( buf )
  {
    v7 = len;
  }
  else
  {
    v5 = BUF_MEM_new();
    v6 = v5;
    str = v5;
    if ( !v5 || !BUF_MEM_grow(v5, 0xC8u) )
    {
err_44:
      ERR_put_error(0xBu, 116, 65, ".\\crypto\\x509\\x509_obj.c", 222);
      if ( v6 )
        BUF_MEM_free(v6);
      return 0;
    }
    *v6->data = 0;
    v7 = 200;
    v4 = (unsigned __int8 **)v6;
  }
  if ( a )
  {
    entries = a->entries;
    v52 = v7 - 1;
    v48 = 0;
    i = 0;
    if ( sk_num(&entries->stack) > 0 )
    {
      while ( 1 )
      {
        v11 = sk_value(&v3->entries->stack, i);
        v37 = *(const asn1_object_st **)v11;
        v50 = v11;
        v12 = OBJ_obj2nid(v37);
        if ( !v12 || (v13 = (unsigned __int8 *)OBJ_nid2sn(v12), (src = v13) == 0) )
        {
          i2t_ASN1_OBJECT(bufa, 0x50u, *(asn1_object_st **)v11);
          src = (unsigned __int8 *)bufa;
          v13 = (unsigned __int8 *)bufa;
        }
        v14 = strlen((const char *)v13);
        v15 = (int *)*((_DWORD *)v11 + 1);
        v16 = *v15;
        v17 = v15[2];
        if ( v15[1] != 27 || v16 % 4 )
        {
          v44 = 1;
          v43 = 1;
          v42 = 1;
          v41 = 1;
        }
        else
        {
          v18 = 0;
          v19 = 0;
          v43 = 0;
          v42 = 0;
          v41 = 0;
          if ( v16 > 0 )
          {
            do
            {
              if ( *(_BYTE *)(v19 + v17) )
                *(&v41 + (v19 & 3)) = 1;
              ++v19;
            }
            while ( v19 < v16 );
            v18 = v41;
          }
          if ( v43 | v42 | v18 )
          {
            v44 = 1;
            v43 = 1;
            v42 = 1;
            v41 = 1;
          }
          else
          {
            v43 = 0;
            v42 = 0;
            v41 = 0;
            v44 = 1;
          }
        }
        v20 = 0;
        for ( j = 0; v20 < v16; ++v20 )
        {
          if ( *(&v41 + (v20 & 3)) )
          {
            v22 = *(_BYTE *)(v20 + v17);
            ++j;
            if ( v22 < 0x20u || v22 > 0x7Eu )
              j += 3;
          }
        }
        v23 = v48;
        v24 = v48 + v14 + j + 2;
        v48 = v24;
        if ( str )
        {
          if ( !BUF_MEM_grow(str, v24 + 1) )
          {
            v6 = str;
            goto err_44;
          }
          v25 = (unsigned __int8 *)&str->data[v23];
        }
        else
        {
          if ( v24 > v52 )
            goto LABEL_51;
          v25 = &dest[v23];
        }
        v26 = src;
        *v25 = 47;
        v27 = v25 + 1;
        memcpy(v27, v26, v14);
        v28 = v50;
        v29 = &v27[v14];
        *v29 = 61;
        v30 = *(_DWORD *)(*((_DWORD *)v28 + 1) + 8);
        v31 = v29 + 1;
        for ( k = 0; k < v16; ++k )
        {
          if ( *(&v41 + (k & 3)) )
          {
            v33 = *(unsigned __int8 *)(k + v30);
            if ( (unsigned int)(v33 - 32) > 0x5E )
            {
              *v31 = 92;
              v34 = v31 + 1;
              *v34++ = 120;
              *v34 = hex[(v33 >> 4) & 0xF];
              v31 = v34 + 1;
              LOBYTE(v33) = hex[v33 & 0xF];
            }
            *v31++ = v33;
          }
        }
        v35 = (const stack_st **)v49;
        *v31 = 0;
        v39 = *v35;
        v36 = ++i;
        if ( v36 >= sk_num(v39) )
        {
          v4 = (unsigned __int8 **)str;
          break;
        }
        v3 = v49;
      }
    }
    if ( v4 )
    {
      v10 = v4[1];
      CRYPTO_free(v4);
    }
    else
    {
LABEL_51:
      v10 = dest;
    }
    if ( !i )
      *v10 = 0;
    return (char *)v10;
  }
  else
  {
    if ( v4 )
    {
      dest = v4[1];
      CRYPTO_free(v4);
    }
    v8 = dest;
    strncpy(dest, "NO X509_NAME", v7);
    dest[v7 - 1] = 0;
    return (char *)v8;
  }
}
