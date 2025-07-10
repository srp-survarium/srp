int __cdecl mem_ctrl(bio_st *b, int cmd, int num, int **ptr)
{
  int *v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int result; // eax

  v4 = (int *)b->ptr;
  v5 = 1;
  switch ( cmd )
  {
    case 1:
      v6 = v4[1];
      if ( !v6 )
        goto $LN18_24;
      v7 = v4[2];
      if ( (b->flags & 0x200) != 0 )
      {
        v4[1] = v6 + *v4 - v7;
        *v4 = v7;
      }
      else
      {
        memset(v6, 0, v4[2]);
        *v4 = 0;
      }
      return 1;
    case 2:
      return *v4 == 0;
    case 3:
      v5 = *v4;
      if ( !ptr )
        goto $LN18_24;
      *ptr = (int *)v4[1];
      return v5;
    case 8:
      return b->shutdown;
    case 9:
      b->shutdown = num;
      return 1;
    case 10:
      return *v4;
    case 11:
    case 12:
      goto $LN18_24;
    case 114:
      mem_free(b);
      b->ptr = ptr;
      b->shutdown = num;
      return 1;
    case 115:
      if ( !ptr )
        goto $LN18_24;
      *ptr = v4;
      result = 1;
      break;
    case 130:
      b->num = num;
      return 1;
    default:
      v5 = 0;
$LN18_24:
      result = v5;
      break;
  }
  return result;
}
