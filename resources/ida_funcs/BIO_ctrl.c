int __cdecl bio_ctrl(bio_st *bio, int cmd, int num, bio_st *ptr)
{
  int *v4; // esi
  int result; // eax
  int v6; // esi
  _DWORD *v7; // eax

  v4 = (int *)bio->ptr;
  switch ( cmd )
  {
    case 1:
      if ( !v4[5] )
        goto LABEL_4;
      v4[2] = 0;
      v4[3] = 0;
      return 0;
    case 2:
      if ( ptr )
      {
        v7 = ptr->ptr;
        if ( v7[2] || !v7[1] )
          goto LABEL_4;
      }
      return 1;
    case 8:
      return bio->shutdown;
    case 9:
      bio->shutdown = num;
      return 1;
    case 10:
      v6 = *v4;
      if ( !v6 )
        goto LABEL_4;
      return *(_DWORD *)(*(_DWORD *)(v6 + 32) + 8);
    case 11:
      goto $LN34_2;
    case 12:
      *((_DWORD *)ptr->ptr + 4) = v4[4];
      return 1;
    case 13:
      if ( !v4[5] )
        goto LABEL_4;
      result = v4[2];
      break;
    case 136:
      if ( *v4 )
      {
        ERR_put_error(0x20u, 103, 123, ".\\crypto\\bio\\bss_bio.c", 517);
LABEL_4:
        result = 0;
      }
      else if ( num )
      {
        if ( v4[4] != num )
        {
          if ( v4[5] )
          {
            CRYPTO_free((void *)v4[5]);
            v4[5] = 0;
          }
          v4[4] = num;
        }
$LN34_2:
        result = 1;
      }
      else
      {
        ERR_put_error(0x20u, 103, 125, ".\\crypto\\bio\\bss_bio.c", 522);
        result = 0;
      }
      break;
    case 137:
      return v4[4];
    case 138:
      return bio_make_pair(bio, ptr) != 0;
    case 139:
      bio_destroy_pair(bio);
      return 1;
    case 140:
      if ( !*v4 || v4[1] )
        goto LABEL_4;
      result = v4[4] - v4[2];
      break;
    case 141:
      return v4[6];
    case 142:
      result = 1;
      v4[1] = 1;
      return result;
    case 143:
      return bio_nread0(bio, (char **)ptr);
    case 144:
      return bio_nread(bio, (char **)ptr, num);
    case 145:
      return bio_nwrite0(bio, (char **)ptr);
    case 146:
      return bio_nwrite(num, bio, (char **)ptr);
    case 147:
      v4[6] = 0;
      return 1;
    default:
      goto LABEL_4;
  }
  return result;
}
