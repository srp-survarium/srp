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
  void *v12; // eax
  char *v13; // eax
  int *v14; // eax
  int v15; // ebp
  int v16; // esi
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  int i; // edx
  unsigned __int8 v21; // cl
  int v22; // edi
  int v23; // eax
  unsigned __int8 *v24; // esi
  const __m128i *v25; // eax
  int v26; // esi
  char *v27; // ecx
  _BYTE *v28; // esi
  int v29; // edi
  _BYTE *v30; // esi
  int j; // ecx
  int v32; // eax
  _BYTE *v33; // esi
  const stack_st **v34; // ecx
  int v35; // esi
  const asn1_object_st *v36; // [esp-Ch] [ebp-9Ch]
  stack_st_X509_NAME_ENTRY *entries; // [esp-4h] [ebp-94h]
  const stack_st *v38; // [esp-4h] [ebp-94h]
  buf_mem_st *v39; // [esp+10h] [ebp-80h]
  int v40; // [esp+14h] [ebp-7Ch]
  int v41; // [esp+18h] [ebp-78h]
  int v42; // [esp+1Ch] [ebp-74h]
  int v43; // [esp+20h] [ebp-70h]
  unsigned __int8 *dest; // [esp+24h] [ebp-6Ch]
  int v45; // [esp+28h] [ebp-68h]
  unsigned __int8 *src; // [esp+2Ch] [ebp-64h]
  int v47; // [esp+30h] [ebp-60h]
  X509_name_st *v48; // [esp+34h] [ebp-5Ch]
  char *v49; // [esp+38h] [ebp-58h]
  char v50[80]; // [esp+3Ch] [ebp-54h] BYREF
  int v51; // [esp+9Ch] [ebp+Ch]

  v3 = a;
  v4 = 0;
  v48 = a;
  dest = (unsigned __int8 *)buf;
  v39 = 0;
  if ( buf )
  {
    v7 = len;
  }
  else
  {
    v5 = BUF_MEM_new((int)a);
    v6 = v5;
    v39 = v5;
    if ( !v5 || !BUF_MEM_grow(v5, 0xC8u) )
    {
err_46:
      ERR_put_error((int)v3, 0xBu, 116, 65, ".\\crypto\\x509\\x509_obj.c", 222);
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
    v51 = v7 - 1;
    v47 = 0;
    v45 = 0;
    if ( sk_num(&entries->stack) > 0 )
    {
      while ( 1 )
      {
        v11 = sk_value(&v3->entries->stack, v45);
        v36 = *(const asn1_object_st **)v11;
        v49 = v11;
        v12 = OBJ_obj2nid(v36);
        if ( !v12 || (v13 = (char *)OBJ_nid2sn((int)v3, (unsigned int)v12), (src = (unsigned __int8 *)v13) == 0) )
        {
          i2t_ASN1_OBJECT(v50, 0x50u, *(asn1_object_st **)v11);
          src = (unsigned __int8 *)v50;
          v13 = v50;
        }
        v3 = (X509_name_st *)strlen(v13);
        v14 = (int *)*((_DWORD *)v11 + 1);
        v15 = *v14;
        v16 = v14[2];
        if ( v14[1] != 27 || v15 % 4 )
        {
          v43 = 1;
          v42 = 1;
          v41 = 1;
          v40 = 1;
        }
        else
        {
          v17 = 0;
          v18 = 0;
          v42 = 0;
          v41 = 0;
          v40 = 0;
          if ( v15 > 0 )
          {
            do
            {
              if ( *(_BYTE *)(v18 + v16) )
                *(&v40 + (v18 & 3)) = 1;
              ++v18;
            }
            while ( v18 < v15 );
            v17 = v40;
          }
          if ( v42 | v41 | v17 )
          {
            v43 = 1;
            v42 = 1;
            v41 = 1;
            v40 = 1;
          }
          else
          {
            v42 = 0;
            v41 = 0;
            v40 = 0;
            v43 = 1;
          }
        }
        v19 = 0;
        for ( i = 0; v19 < v15; ++v19 )
        {
          if ( *(&v40 + (v19 & 3)) )
          {
            v21 = *(_BYTE *)(v19 + v16);
            ++i;
            if ( v21 < 0x20u || v21 > 0x7Eu )
              i += 3;
          }
        }
        v22 = v47;
        v23 = (int)&v3->entries + i + v47 + 2;
        v47 = v23;
        if ( v39 )
        {
          if ( !BUF_MEM_grow(v39, v23 + 1) )
          {
            v6 = v39;
            goto err_46;
          }
          v24 = (unsigned __int8 *)&v39->data[v22];
        }
        else
        {
          if ( v23 > v51 )
            goto LABEL_51;
          v24 = &dest[v22];
        }
        v25 = (const __m128i *)src;
        *v24 = 47;
        v26 = (int)(v24 + 1);
        memcpy(v26, v25, (unsigned int)v3);
        v27 = v49;
        v28 = (char *)v3 + v26;
        *v28 = 61;
        v29 = *(_DWORD *)(*((_DWORD *)v27 + 1) + 8);
        v30 = v28 + 1;
        for ( j = 0; j < v15; ++j )
        {
          if ( *(&v40 + (j & 3)) )
          {
            v32 = *(unsigned __int8 *)(j + v29);
            if ( (unsigned int)(v32 - 32) > 0x5E )
            {
              *v30 = 92;
              v33 = v30 + 1;
              *v33++ = 120;
              *v33 = hex[(v32 >> 4) & 0xF];
              v30 = v33 + 1;
              LOBYTE(v32) = hex[v32 & 0xF];
            }
            *v30++ = v32;
          }
        }
        v34 = (const stack_st **)v48;
        *v30 = 0;
        v38 = *v34;
        v35 = ++v45;
        if ( v35 >= sk_num(v38) )
        {
          v4 = (unsigned __int8 **)v39;
          break;
        }
        v3 = v48;
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
    if ( !v45 )
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
