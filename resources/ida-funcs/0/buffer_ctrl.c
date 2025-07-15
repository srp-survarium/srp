int __cdecl buffer_ctrl(bio_st *b, int cmd, int num, bio_st *ptr)
{
  void *v4; // esi
  int v5; // ebx
  bio_st *next_bio; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  _BYTE *v11; // eax
  bio_st *v12; // edi
  bio_st *v13; // edi
  int v14; // ebp
  void *v15; // edi
  int v16; // ebx
  bio_st *v17; // eax
  int v18; // [esp-Ch] [ebp-1Ch]
  int ba; // [esp+14h] [ebp+4h]
  void *cmda; // [esp+18h] [ebp+8h]

  v4 = b->ptr;
  v5 = 1;
  switch ( cmd )
  {
    case 1:
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 3) = 0;
      *((_DWORD *)v4 + 7) = 0;
      *((_DWORD *)v4 + 6) = 0;
      next_bio = b->next_bio;
      if ( !next_bio )
        return 0;
      return BIO_ctrl(1, next_bio, cmd, num, ptr);
    case 3:
      return *((_DWORD *)v4 + 6);
    case 10:
      v5 = *((_DWORD *)v4 + 3);
      if ( v5 )
        return v5;
      goto LABEL_15;
    case 11:
      v17 = b->next_bio;
      if ( !v17 )
        return 0;
      if ( *((int *)v4 + 6) <= 0 )
        return BIO_ctrl(1, v17, cmd, num, ptr);
      BIO_clear_flags(b, 15);
      if ( *((int *)v4 + 6) <= 0 )
        goto LABEL_51;
      break;
    case 12:
      if ( BIO_int_ctrl(1, ptr, 117, *(_DWORD *)v4, 0) && BIO_int_ctrl(1, ptr, 117, *((_DWORD *)v4 + 1), 1) )
        return v5;
      return 0;
    case 13:
      v5 = *((_DWORD *)v4 + 6);
      if ( v5 )
        return v5;
      v12 = b->next_bio;
      if ( !v12 )
        return 0;
      return BIO_ctrl(0, v12, cmd, num, ptr);
    case 101:
      if ( !b->next_bio )
        return 0;
      BIO_clear_flags(b, 15);
      v16 = BIO_ctrl(1, b->next_bio, cmd, num, ptr);
      BIO_copy_next_retry(b);
      return v16;
    case 116:
      v8 = *((_DWORD *)v4 + 2);
      v5 = 0;
      if ( *((int *)v4 + 3) <= 0 )
        return v5;
      v9 = *((_DWORD *)v4 + 4);
      v10 = *((_DWORD *)v4 + 3);
      v11 = (_BYTE *)(v8 + v9);
      do
      {
        if ( *v11 == 10 )
          ++v5;
        ++v11;
        --v10;
      }
      while ( v10 );
      return v5;
    case 117:
      if ( ptr )
      {
        if ( ptr->method )
        {
          v14 = *(_DWORD *)v4;
          ba = num;
        }
        else
        {
          v14 = num;
          ba = *((_DWORD *)v4 + 1);
        }
      }
      else
      {
        v14 = num;
        ba = num;
      }
      v15 = (void *)*((_DWORD *)v4 + 2);
      cmda = (void *)*((_DWORD *)v4 + 5);
      if ( v14 > 4096 && v14 != *(_DWORD *)v4 )
      {
        v15 = CRYPTO_malloc(num, ".\\crypto\\bio\\bf_buff.c", 355);
        if ( !v15 )
          goto malloc_error;
      }
      if ( ba > 4096 && ba != *((_DWORD *)v4 + 1) )
      {
        cmda = CRYPTO_malloc(num, ".\\crypto\\bio\\bf_buff.c", 360);
        if ( !cmda )
        {
          if ( v15 != *((void **)v4 + 2) )
            CRYPTO_free(v15);
malloc_error:
          ERR_put_error(v5, 0x20u, 114, 65, ".\\crypto\\bio\\bf_buff.c", 438);
          return 0;
        }
      }
      if ( *((void **)v4 + 2) != v15 )
      {
        CRYPTO_free(*((void **)v4 + 2));
        *((_DWORD *)v4 + 2) = v15;
        *((_DWORD *)v4 + 4) = 0;
        *((_DWORD *)v4 + 3) = 0;
        *(_DWORD *)v4 = v14;
      }
      if ( *((void **)v4 + 5) != cmda )
      {
        CRYPTO_free(*((void **)v4 + 5));
        *((_DWORD *)v4 + 7) = 0;
        *((_DWORD *)v4 + 6) = 0;
        *((_DWORD *)v4 + 1) = ba;
        *((_DWORD *)v4 + 5) = cmda;
        return 1;
      }
      return v5;
    case 122:
      if ( num <= *(_DWORD *)v4 )
        goto LABEL_23;
      v5 = (int)CRYPTO_malloc(num, ".\\crypto\\bio\\bf_buff.c", 321);
      if ( !v5 )
        goto malloc_error;
      if ( *((_DWORD *)v4 + 2) )
        CRYPTO_free(*((void **)v4 + 2));
      *((_DWORD *)v4 + 2) = v5;
LABEL_23:
      v18 = *((_DWORD *)v4 + 2);
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 3) = num;
      memcpy(v18, (const __m128i *)ptr, num);
      return 1;
    default:
LABEL_15:
      v13 = b->next_bio;
      if ( !v13 )
        return 0;
      return BIO_ctrl(v5, v13, cmd, num, ptr);
  }
  do
  {
    v5 = BIO_write(v5, b->next_bio, (const char *)(*((_DWORD *)v4 + 7) + *((_DWORD *)v4 + 5)), *((_DWORD *)v4 + 6));
    BIO_copy_next_retry(b);
    if ( v5 <= 0 )
      return v5;
    *((_DWORD *)v4 + 7) += v5;
    *((_DWORD *)v4 + 6) -= v5;
    BIO_clear_flags(b, 15);
  }
  while ( *((int *)v4 + 6) > 0 );
LABEL_51:
  *((_DWORD *)v4 + 6) = 0;
  *((_DWORD *)v4 + 7) = 0;
  return BIO_ctrl(v5, b->next_bio, cmd, num, ptr);
}
