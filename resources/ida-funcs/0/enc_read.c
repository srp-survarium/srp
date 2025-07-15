char *__cdecl enc_read(bio_st *b, char *out, int outl)
{
  char *result; // eax
  bio_st *v4; // ebx
  char *ptr; // esi
  int v6; // ebp
  signed int v7; // edi
  int v8; // eax
  char *v9; // edi
  const __m128i *v10; // ebx
  bool v11; // zf
  signed int v12; // edi
  int v13; // ebp
  char *v14; // [esp+0h] [ebp-4h]

  result = out;
  v14 = 0;
  if ( out )
  {
    v4 = b;
    ptr = (char *)b->ptr;
    if ( ptr && b->next_bio )
    {
      v6 = outl;
      if ( *(int *)ptr > 0 )
      {
        v7 = *(_DWORD *)ptr - *((_DWORD *)ptr + 1);
        if ( v7 > outl )
          v7 = outl;
        memcpy((int)out, (const __m128i *)&ptr[*((_DWORD *)ptr + 1) + 160], v7);
        *((_DWORD *)ptr + 1) += v7;
        out += v7;
        v6 = outl - v7;
        v14 = (char *)v7;
        outl -= v7;
        if ( *(_DWORD *)ptr == *((_DWORD *)ptr + 1) )
        {
          *(_DWORD *)ptr = 0;
          *((_DWORD *)ptr + 1) = 0;
        }
      }
      if ( v6 > 0 )
      {
        do
        {
          if ( *((int *)ptr + 2) <= 0 )
            break;
          v8 = BIO_read((int)v4, v4->next_bio, ptr + 224, 4096);
          v9 = (char *)v8;
          if ( v8 > 0 )
          {
            v10 = (const __m128i *)(ptr + 160);
            EVP_CipherUpdate(
              (evp_cipher_ctx_st *)(ptr + 20),
              (unsigned __int8 *)ptr + 160,
              (int *)ptr,
              (unsigned __int8 *)ptr + 224,
              v8);
            v11 = *(_DWORD *)ptr == 0;
            *((_DWORD *)ptr + 2) = 1;
            if ( v11 )
            {
              v13 = outl;
              goto LABEL_20;
            }
          }
          else
          {
            if ( BIO_test_flags(v4->next_bio, 8) )
            {
              if ( !v14 )
                v14 = v9;
              break;
            }
            v10 = (const __m128i *)(ptr + 160);
            *((_DWORD *)ptr + 2) = v9;
            *((_DWORD *)ptr + 4) = EVP_CipherFinal_ex(
                                     (evp_cipher_ctx_st *)(ptr + 20),
                                     (unsigned __int8 *)ptr + 160,
                                     (unsigned int *)ptr);
            *((_DWORD *)ptr + 1) = 0;
          }
          v12 = *(_DWORD *)ptr;
          if ( *(_DWORD *)ptr > outl )
            v12 = outl;
          if ( v12 <= 0 )
          {
            v4 = b;
            break;
          }
          memcpy((int)out, v10, v12);
          v14 += v12;
          v13 = outl - v12;
          *((_DWORD *)ptr + 1) = v12;
          outl -= v12;
          out += v12;
LABEL_20:
          v4 = b;
        }
        while ( v13 > 0 );
      }
      BIO_clear_flags(v4, 15);
      BIO_copy_next_retry(v4);
      result = v14;
      if ( !v14 )
        return (char *)*((_DWORD *)ptr + 2);
    }
    else
    {
      return 0;
    }
  }
  return result;
}
