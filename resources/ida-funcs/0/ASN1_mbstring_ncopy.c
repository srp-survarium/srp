int __cdecl ASN1_mbstring_ncopy(
        asn1_string_st **out,
        const __m128i *in,
        int len,
        int inform,
        unsigned int mask,
        int minsize,
        int maxsize)
{
  int v7; // eax
  const unsigned __int8 *v8; // edi
  int v9; // ebp
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int v13; // esi
  int v14; // edi
  asn1_string_st **v15; // ebx
  asn1_string_st *v16; // esi
  unsigned __int8 *data; // eax
  asn1_string_st *v18; // eax
  int v19; // ebx
  char v21; // [esp+13h] [ebp-3Dh]
  int v22; // [esp+14h] [ebp-3Ch] BYREF
  unsigned int val; // [esp+18h] [ebp-38h] BYREF
  int (__cdecl *v24)(unsigned int, void *); // [esp+1Ch] [ebp-34h]
  const __m128i *v25; // [esp+20h] [ebp-30h]
  unsigned __int8 *v26; // [esp+24h] [ebp-2Ch] BYREF
  asn1_string_st **v27; // [esp+28h] [ebp-28h]
  char v28[32]; // [esp+2Ch] [ebp-24h] BYREF

  v27 = out;
  v7 = len;
  v8 = (const unsigned __int8 *)in;
  v25 = in;
  v22 = 0;
  v24 = 0;
  if ( len == -1 )
  {
    v7 = strlen(in->m128i_i8);
    len = v7;
  }
  if ( !mask )
    mask = 10246;
  switch ( inform )
  {
    case 4096:
      v9 = 0;
      v10 = v7;
      if ( !v7 )
        goto LABEL_20;
      do
      {
        v11 = UTF8_getc(v8, v10, &val);
        if ( v11 < 0 )
        {
          ERR_put_error(0, 0xDu, 122, 134, ".\\crypto\\asn1\\a_mbstr.c", 132);
          return -1;
        }
        v10 -= v11;
        v8 += v11;
        if ( in_utf8 )
          ++v9;
      }
      while ( v10 );
      goto LABEL_20;
    case 4097:
      v9 = v7;
      goto LABEL_20;
    case 4098:
      if ( (v7 & 1) != 0 )
      {
        ERR_put_error(0, 0xDu, 122, 129, ".\\crypto\\asn1\\a_mbstr.c", 111);
        return -1;
      }
      v9 = v7 >> 1;
      goto LABEL_20;
    case 4100:
      if ( (v7 & 3) != 0 )
      {
        ERR_put_error(0, 0xDu, 122, 133, ".\\crypto\\asn1\\a_mbstr.c", 120);
      }
      else
      {
        v9 = v7 >> 2;
LABEL_20:
        v12 = minsize;
        if ( minsize <= 0 || v9 >= minsize )
        {
          v13 = maxsize;
          if ( maxsize <= 0 || v9 <= maxsize )
          {
            if ( traverse_string(
                   (const unsigned __int8 *)v25,
                   len,
                   (int (__cdecl *)(unsigned int, void *))type_str,
                   inform,
                   &mask) >= 0 )
            {
              val = 4097;
              if ( (mask & 2) != 0 )
              {
                v14 = 19;
              }
              else if ( (mask & 0x10) != 0 )
              {
                v14 = 22;
              }
              else if ( (mask & 4) != 0 )
              {
                v14 = 20;
              }
              else if ( (mask & 0x800) != 0 )
              {
                v14 = 30;
                val = 4098;
              }
              else if ( (mask & 0x100) != 0 )
              {
                v14 = 28;
                val = 4100;
              }
              else
              {
                v14 = 12;
                val = 4096;
              }
              v15 = v27;
              if ( v27 )
              {
                v16 = *v27;
                if ( *v27 )
                {
                  data = v16->data;
                  v21 = 0;
                  if ( data )
                  {
                    v16->length = 0;
                    CRYPTO_free(data);
                    v16->data = 0;
                  }
                  v16->type = v14;
                }
                else
                {
                  v21 = 1;
                  v18 = ASN1_STRING_type_new((int)v27, v14);
                  v16 = v18;
                  if ( !v18 )
                  {
                    ERR_put_error((int)v15, 0xDu, 122, 65, ".\\crypto\\asn1\\a_mbstr.c", 197);
                    return -1;
                  }
                  *v15 = v18;
                }
                v19 = inform;
                if ( inform == val )
                {
                  if ( !ASN1_STRING_set(v16, v25, len) )
                  {
                    ERR_put_error(inform, 0xDu, 122, 65, ".\\crypto\\asn1\\a_mbstr.c", 205);
                    return -1;
                  }
                }
                else
                {
                  switch ( val )
                  {
                    case 0x1000u:
                      v22 = 0;
                      traverse_string(
                        (const unsigned __int8 *)v25,
                        len,
                        (int (__cdecl *)(unsigned int, void *))out_utf8,
                        inform,
                        &v22);
                      v19 = inform;
                      v24 = (int (__cdecl *)(unsigned int, void *))cpy_utf8;
                      break;
                    case 0x1001u:
                      v22 = v9;
                      v24 = (int (__cdecl *)(unsigned int, void *))cpy_asc;
                      break;
                    case 0x1002u:
                      v22 = 2 * v9;
                      v24 = (int (__cdecl *)(unsigned int, void *))cpy_bmp;
                      break;
                    case 0x1004u:
                      v22 = 4 * v9;
                      v24 = (int (__cdecl *)(unsigned int, void *))cpy_univ;
                      break;
                    default:
                      break;
                  }
                  v26 = (unsigned __int8 *)CRYPTO_malloc(v22 + 1, ".\\crypto\\asn1\\a_mbstr.c", 234);
                  if ( !v26 )
                  {
                    if ( v21 )
                      ASN1_STRING_free(v16);
                    ERR_put_error(v19, 0xDu, 122, 65, ".\\crypto\\asn1\\a_mbstr.c", 236);
                    return -1;
                  }
                  v16->length = v22;
                  v16->data = v26;
                  v26[v22] = 0;
                  traverse_string((const unsigned __int8 *)v25, len, v24, v19, &v26);
                }
              }
              return v14;
            }
            ERR_put_error((int)type_str, 0xDu, 122, 124, ".\\crypto\\asn1\\a_mbstr.c", 162);
          }
          else
          {
            ERR_put_error(0, 0xDu, 122, 151, ".\\crypto\\asn1\\a_mbstr.c", 154);
            BIO_snprintf(v28, 0x20u, "%ld", v13);
            ERR_add_error_data(2, "maxsize=", v28);
          }
        }
        else
        {
          ERR_put_error(0, 0xDu, 122, 152, ".\\crypto\\asn1\\a_mbstr.c", 147);
          BIO_snprintf(v28, 0x20u, "%ld", v12);
          ERR_add_error_data(2, "minsize=", v28);
        }
      }
      return -1;
    default:
      ERR_put_error(0, 0xDu, 122, 160, ".\\crypto\\asn1\\a_mbstr.c", 142);
      return -1;
  }
}
