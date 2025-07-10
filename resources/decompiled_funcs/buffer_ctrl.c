int __cdecl buffer_ctrl(bio_st *b, char *cmd, int num, bio_st *ptr)
{
  void *v4; // esi
  int v5; // ebx
  bio_st *next_bio; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  _BYTE *v11; // eax
  bio_st *v12; // edi
  void *v13; // ebx
  int v14; // ebp
  void *v15; // edi
  int v16; // ebx
  bio_st *v17; // eax
  unsigned __int8 *v18; // [esp-Ch] [ebp-1Ch]
  int obs; // [esp+14h] [ebp+4h]
  char *p2; // [esp+18h] [ebp+8h]

  v4 = b->ptr;
  v5 = 1;
  switch ( (unsigned int)cmd )
  {
    case 1u:
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 3) = 0;
      *((_DWORD *)v4 + 7) = 0;
      *((_DWORD *)v4 + 6) = 0;
      next_bio = b->next_bio;
      if ( !next_bio )
        return 0;
      return BIO_ctrl(next_bio, (int)cmd, num, ptr);
    case 3u:
      return *((_DWORD *)v4 + 6);
    case 0xAu:
      v5 = *((_DWORD *)v4 + 3);
      if ( !v5 )
        goto LABEL_15;
      return v5;
    case 0xBu:
      v17 = b->next_bio;
      if ( !v17 )
        return 0;
      if ( *((int *)v4 + 6) <= 0 )
        return BIO_ctrl(v17, (int)cmd, num, ptr);
      BIO_clear_flags(b, 15);
      if ( *((int *)v4 + 6) <= 0 )
        goto LABEL_51;
      break;
    case 0xCu:
      if ( BIO_int_ctrl(ptr, 117, *(_DWORD *)v4, 0) && BIO_int_ctrl(ptr, 117, *((_DWORD *)v4 + 1), 1) )
        return v5;
      return 0;
    case 0xDu:
      v5 = *((_DWORD *)v4 + 6);
      if ( v5 )
        return v5;
      next_bio = b->next_bio;
      if ( !next_bio )
        return 0;
      return BIO_ctrl(next_bio, (int)cmd, num, ptr);
    case 0x65u:
      if ( !b->next_bio )
        return 0;
      BIO_clear_flags(b, 15);
      v16 = BIO_ctrl(b->next_bio, (int)cmd, num, ptr);
      BIO_copy_next_retry(b);
      return v16;
    case 0x74u:
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
    case 0x75u:
      if ( ptr )
      {
        if ( ptr->method )
        {
          v14 = *(_DWORD *)v4;
          obs = num;
        }
        else
        {
          v14 = num;
          obs = *((_DWORD *)v4 + 1);
        }
      }
      else
      {
        v14 = num;
        obs = num;
      }
      v15 = (void *)*((_DWORD *)v4 + 2);
      p2 = (char *)*((_DWORD *)v4 + 5);
      if ( v14 > 4096 && v14 != *(_DWORD *)v4 )
      {
        v15 = CRYPTO_malloc(num, ".\\crypto\\bio\\bf_buff.c", 355);
        if ( !v15 )
          goto malloc_error;
      }
      if ( obs > 4096 && obs != *((_DWORD *)v4 + 1) )
      {
        p2 = (char *)CRYPTO_malloc(num, ".\\crypto\\bio\\bf_buff.c", 360);
        if ( !p2 )
        {
          if ( v15 != *((void **)v4 + 2) )
            CRYPTO_free(v15);
malloc_error:
          ERR_put_error(0x20u, 114, 65, ".\\crypto\\bio\\bf_buff.c", 438);
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
      if ( *((char **)v4 + 5) != p2 )
      {
        CRYPTO_free(*((void **)v4 + 5));
        *((_DWORD *)v4 + 7) = 0;
        *((_DWORD *)v4 + 6) = 0;
        *((_DWORD *)v4 + 1) = obs;
        *((_DWORD *)v4 + 5) = p2;
        return 1;
      }
      return v5;
    case 0x7Au:
      if ( num <= *(_DWORD *)v4 )
        goto LABEL_23;
      v13 = CRYPTO_malloc(num, ".\\crypto\\bio\\bf_buff.c", 321);
      if ( !v13 )
        goto malloc_error;
      if ( *((_DWORD *)v4 + 2) )
        CRYPTO_free(*((void **)v4 + 2));
      *((_DWORD *)v4 + 2) = v13;
LABEL_23:
      v18 = (unsigned __int8 *)*((_DWORD *)v4 + 2);
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 3) = num;
      memcpy(v18, (unsigned __int8 *)ptr, num);
      return 1;
    default:
LABEL_15:
      v12 = b->next_bio;
      if ( !v12 )
        return 0;
      return BIO_ctrl(v12, (int)cmd, num, ptr);
  }
  do
  {
    v5 = BIO_write(b->next_bio, (const char *)(*((_DWORD *)v4 + 7) + *((_DWORD *)v4 + 5)), *((_DWORD *)v4 + 6));
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
  return BIO_ctrl(b->next_bio, (int)cmd, num, ptr);
}
